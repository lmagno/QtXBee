TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = \
	QXBee \
	tests \
	sample

QXBee.subdir  = src/QXBee
tests.subdir = src/tests

sample.depends = src
tests.depends = src
