rootdir := $(shell pwd)/../..
project ?= ubuntu-base

include $(rootdir)/build/project/$(project).mk
include $(rootdir)/build/common/common.mk

TARGET_ARCHIVE = libonencoding.a
MODULENAME = libonencoding
MODULEVERSION = 0.1.0

COMMON_INCLUDE_DIRS += $(rootdir)/source/$(MODULENAME)/include
COMMON_SRC_FILES := $(rootdir)/source/$(MODULENAME)/src/onjson/onjson.c
COMMON_INST_HEADER_DIRS += $(rootdir)/source/$(MODULENAME)/include

include $(rootdir)/build/utils/archive.mk

.PHONY : sync
