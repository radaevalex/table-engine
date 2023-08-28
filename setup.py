import os
import platform
import subprocess
import sys

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from distutils.file_util import copy_file


BASE_DIR_PATH = os.path.dirname(os.path.abspath(__file__))


class CMakeExtension(Extension):
    def __init__(self, name: str, cmake_lists_dir: str = ".", libs_dir: str = ".", *args, **kwargs):
        """
        :param name:  name extension
        :param cmake_lists_dir: path to CMakeLists.txt
        :param libs_dir: path to put shared lib
        """
        Extension.__init__(self, name, sources=[], *args, **kwargs)
        self.cmake_lists_dir = os.path.join(BASE_DIR_PATH, cmake_lists_dir)
        self.libs_dir = libs_dir


class project_build_ext(build_ext):
    def copy_extensions_to_source(self):
        """Сopies extension files to source"""
        build_py = self.get_finalized_command('build_py')
        for ext in self.extensions:
            if isinstance(ext, CMakeExtension):
                suffix = '.dll' if platform == 'Windows' else '.so'
                fullname = os.path.join(ext.libs_dir, ext.name).replace('/', '.')
                filename = os.path.join(BASE_DIR_PATH, self.build_lib, ext.libs_dir, ext.name + suffix)
            else:
                fullname = self.get_ext_fullname(ext.name)
                filename = self.get_ext_filename(fullname)

            modpath = fullname.split('.')
            package = '.'.join(modpath[:-1])
            package_dir = build_py.get_package_dir(package)
            dest_filename = os.path.join(package_dir,
                                         os.path.basename(filename))
            src_filename = os.path.join(self.build_lib, filename)

            # Always copy, even if source is older than destination, to ensure
            # that the right extensions for the current Python/platform are
            # used.
            copy_file(
                src_filename, dest_filename, verbose=self.verbose,
                dry_run=self.dry_run
            )

            if ext._needs_stub:
                self.write_stub(package_dir or os.curdir, ext, True)

    def build_extension(self, ext: Extension):
        """builds extension"""
        if isinstance(ext, CMakeExtension):
            self.cmake_build_extension(ext)
        else:
            build_ext.build_extension(self, ext)

    def cmake_build_extension(self, ext: CMakeExtension):
        """builds extension by cmake"""
        # Ensure that CMake is present and working
        try:
            subprocess.check_output(["cmake", "--version"])
        except OSError:
            raise RuntimeError("Cannot find CMake executable")

        cfg = "Debug" if "--debug" in sys.argv else "Release"

        path_to_libs_dir = os.path.join(self.build_lib, ext.libs_dir)

        cmake_args = [
            "-DCMAKE_BUILD_TYPE={}".format(cfg),
            # Ask CMake to place the resulting library in the directory
            # containing the extension
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}".format(cfg.upper(), os.path.join(BASE_DIR_PATH, path_to_libs_dir)),
            # Other intermediate static libraries are placed in a
            # temporary build directory instead
            "-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_{}={}".format(cfg.upper(), os.path.join(BASE_DIR_PATH, self.build_temp)),
            # Hint CMake to use the same Python executable that
            # is launching the build, prevents possible mismatching if
            # multiple versions of Python are installed
            "-DPYTHON_EXECUTABLE={}".format(sys.executable),
            # Add other project-specific CMake arguments if needed
            # ...
        ]

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        if not os.path.exists(path_to_libs_dir):
            os.makedirs(path_to_libs_dir)

        # Config
        subprocess.check_call(["cmake", ext.cmake_lists_dir, *cmake_args], cwd=self.build_temp)

        # Build
        subprocess.check_call(["cmake", "--build", ".", "--config", "Release"], cwd=self.build_temp)


with open(os.path.join(BASE_DIR_PATH, "README.md"), "r") as file:
    README = file.read()

setup(
    name="table_engine",
    author="Alexey Radaev",
    author_email="radaevalexxey@gmail.com",
    version="0.0.1",
    description="Module for recalculation of values in the table",
    long_description=README,
    long_description_content_type="text/markdown",
    include_package_data=True,
    ext_modules=[CMakeExtension("table_engine", "core", "table_engine/libs", package="table_engine")],
    cmdclass={"build_ext": project_build_ext},
    packages=["table_engine"],
    zip_safe=False,
    test_suite="test.tests.TableEngineTest",
    tests_require=["pytest"]
)
