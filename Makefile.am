
AUTOMAKE_OPTIONS = foreign 1.4

DIRS = include src

if DIALECT_SET
EXAMPLES_DIRS = examples
else
EXAMPLES_DIRS =
endif

if CPPUNIT_PRESENT
TESTS_DIRS = tests
else
TESTS_DIRS =
endif

SUBDIRS = $(DIRS) $(TESTS_DIRS) $(EXAMPLES_DIRS)

