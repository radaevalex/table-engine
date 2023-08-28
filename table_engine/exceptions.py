class EngineError(Exception):
    """
    Base class for exceptions
    """


class ImportLibError(EngineError):
    """
    Shared library not found
    """


class LibError(EngineError):
    """
    Common exception caused in shared library
    """


class AttributeLibError(LibError):
    """
    Attribute in the library not found
    """


class FormulaLibError(LibError):
    """
    Exception caused during the calculation of the formula
    """


class ConverterError(LibError):
    """
    Exception caused during conversion of objects
    """
