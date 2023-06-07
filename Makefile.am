# Makefile for bash-5.2, version 5.1
#
# Copyright (C) 1996-2021 Free Software Foundation, Inc.

#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.

#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Make sure the first target in the makefile is the right one
#all: .made

ACLOCAL_AMFLAGS = -I gl_m4 -I m4
# lib/malloc
SUBDIRS = gnu builtins lib/readline lib/glob lib/intl lib/sh lib/termcap lib/tilde .
bin_PROGRAMS = bash



PACKAGE = @PACKAGE_NAME@
VERSION = @PACKAGE_VERSION@

PACKAGE_BUGREPORT = @PACKAGE_BUGREPORT@
PACKAGE_NAME = @PACKAGE_NAME@
PACKAGE_STRING = @PACKAGE_STRING@
PACKAGE_VERSION = @PACKAGE_VERSION@

PACKAGE_TARNAME = @PACKAGE_TARNAME@

# Include some boilerplate Gnu makefile definitions.
prefix = @prefix@
manpfx = man

man1ext = .1
man1dir = $(mandir)/$(manpfx)1
man3ext = .3
man3dir = $(mandir)/$(manpfx)3

htmldir = @htmldir@

# Support an alternate destination root directory for package building
DESTDIR =

topdir = @top_srcdir@
BUILD_DIR = @BUILD_DIR@
top_builddir = @BUILD_DIR@

@SET_MAKE@
CC = @CC@
CC_FOR_BUILD = @CC_FOR_BUILD@
YACC = @YACC@
SHELL = @MAKE_SHELL@
CP = cp
RM = rm -f
ARFLAGS = @ARFLAGS@
RANLIB = @RANLIB@
SIZE = @SIZE@
STRIP = strip

INSTALL = @INSTALL@
INSTALL_PROGRAM = @INSTALL_PROGRAM@
INSTALL_SCRIPT = @INSTALL_SCRIPT@
INSTALLCMD = @INSTALLCMD@
INSTALLMODE= -m 0755
INSTALLMODE2 = -m 0555

CTAGS = ctags
CTAGSFLAGS = -x
ETAGS = etags
ETAGSFLAGS =

TESTSCRIPT = @TESTSCRIPT@

DEBUGGER_START_FILE = @DEBUGGER_START_FILE@

#If you have purify, and want to use it, run the make as `make PURIFY=purify'
#PURIFY = @PURIFY@

EXEEXT = @EXEEXT@
OBJEXT = @OBJEXT@

# The name of this program and some version information.
VERSPROG = bashversion$(EXEEXT)
VERSOBJ = bashversion.$(OBJEXT)

Program = bash$(EXEEXT)
Version = @BASHVERS@
PatchLevel = `$(BUILD_DIR)/$(VERSPROG) -p`
RELSTATUS = @RELSTATUS@

Machine = @host_cpu@
OS = @host_os@
VENDOR = @host_vendor@
MACHTYPE = @host@

# comment out for release
DEBUG = @DEBUG@
MALLOC_DEBUG = @MALLOC_DEBUG@

THIS_SH = $(BUILD_DIR)/$(Program)

# PROFILE_FLAGS is either -pg, to generate profiling info for use
# with gprof, or nothing (the default).
PROFILE_FLAGS= @PROFILE_FLAGS@

CFLAGS = @CFLAGS@  -Iinclude -Ignu -Ilib -DHAVE_CONFIG_H
CFLAGS_FOR_BUILD = @CFLAGS_FOR_BUILD@ @CROSS_COMPILE@  -Ignu -Ilib
CPPFLAGS = @CPPFLAGS@ -Iinclude -Ignu -Ilib
CPPFLAGS_FOR_BUILD = @CPPFLAGS_FOR_BUILD@ -Ignu -Ilib
LOCAL_CFLAGS = @LOCAL_CFLAGS@ ${DEBUG} ${MALLOC_DEBUG} -Iinclude -I.
STYLE_CFLAGS = @STYLE_CFLAGS@
DEFS = @DEFS@
LOCAL_DEFS = @LOCAL_DEFS@

LOCALE_DEFS = -DLOCALEDIR='"$(localedir)"' -DPACKAGE='"$(PACKAGE)"'

LOCAL_LIBS = @LOCAL_LIBS@
LIBS = $(LIBRARIES) @LIBS@ gnu/libgnu.a
LIBS_FOR_BUILD = -lgnu

STATIC_LD = @STATIC_LD@
LOCALLDFLAGS = @LOCAL_LDFLAGS@

SYSTEM_FLAGS = -DPROGRAM='"$(Program)"' $(LOCALE_DEFS)

BASE_CCFLAGS = $(SYSTEM_FLAGS) $(LOCAL_DEFS) \
	  $(DEFS) $(LOCAL_CFLAGS) $(INCLUDES) $(STYLE_CFLAGS)

AM_CCFLAGS = $(ADDON_CFLAGS) $(BASE_CCFLAGS) ${PROFILE_FLAGS} $(CPPFLAGS) $(CFLAGS) -Iinclude

AM_CCFLAGS_FOR_BUILD = $(BASE_CCFLAGS) $(CPPFLAGS_FOR_BUILD) $(CFLAGS_FOR_BUILD)
CCFLAGS_FOR_BUILD = $(AM_CCFLAGS_FOR_BUILD)
CCFLAGS = $(AM_CCFLAGS)

BASELDADD = @LDFLAGS@ $(LOCALLDFLAGS) $(CFLAGS)
AM_LDFLAGS = ${ADDON_LDFLAGS} ${BASELDADD} ${PROFILE_FLAGS} ${STATIC_LD}
# ${LIBOBJS}
LDFLAGS_FOR_BUILD = @LDFLAGS_FOR_BUILD@ -L./gnu -L./lib
FOR_BUILDLDADD = $(LDFLAGS_FOR_BUILD) $(LOCALLDFLAGS) $(CFLAGS_FOR_BUILD)


ASAN_XCFLAGS = -fsanitize=address -fno-omit-frame-pointer
ASAN_XLDFLAGS = -fsanitize=address

GCOV_XCFLAGS = -fprofile-arcs -ftest-coverage
GCOV_XLDFLAGS = -fprofile-arcs -ftest-coverage

AM_CPPFLAGS = -I. @RL_INCLUDE@ -I$(srcdir) -I$(BASHINCDIR) -I$(srcdir)/gnu -I$(LIBSRC) $(INTL_INC) -Ilib -I$(srcdir)/lib -Iinclude

# Maybe add: -Wextra
GCC_LINT_FLAGS = -O -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wno-parentheses \
		 -Wcast-align -Wstrict-prototypes -Wconversion -Wformat \
		 -Wformat-nonliteral -Wmissing-braces -Wuninitialized \
		 -Wmissing-declarations  -Winline \
		 -Wmissing-prototypes -Wtraditional -Wredundant-decls \
		 -Wformat-security -pedantic

GCC_LINT_CFLAGS = $(BASE_CCFLAGS) $(CPPFLAGS) $(GCC_LINT_FLAGS)

#
# Support libraries
# 

dot = .

LIBSUBDIR = lib
LIBSRC = $(srcdir)/$(LIBSUBDIR)

LIBBUILD = ${BUILD_DIR}/${LIBSUBDIR}

SUBDIR_INCLUDES = -I. @RL_INCLUDE@ -I$(topdir) -I$(topdir)/$(LIBSUBDIR)

BUILD_INCLUDED_LIBINTL = @BUILD_INCLUDED_LIBINTL@
USE_INCLUDED_LIBINTL = @USE_INCLUDED_LIBINTL@

# the bash library
# the library is a mix of functions that the C library does not provide on
# some platforms and general shell utility functions
SH_LIBSRC = $(LIBSRC)/sh
SH_LIBDIR = $(dot)/${LIBSUBDIR}/sh
SH_ABSSRC = ${topdir}/${SH_LIBSRC}

if USE_JOB_CONTROL
bash_SOURCES = ${CSOURCES} jobs.c
else
bash_SOURCES = ${CSOURCES} nojobs.c
endif


bash_LDFLAGS = -L./builtins

SHLIB_LIBRARY = ${SH_LIBDIR}/libsh.a


# we assume for now that readline source is being shipped with bash
RL_LIBDIR = @RL_LIBDIR@
READLINE_LIBRARY = $(RL_LIBDIR)/libreadline.a


HIST_LIBDIR = @HIST_LIBDIR@
HISTORY_LIBRARY = $(HIST_LIBDIR)/libhistory.a

# You only need termcap (or curses) if you are linking with GNU Readline.
TERM_LIBDIR = $(dot)/$(LIBSUBDIR)/termcap
TERMCAP_LIBRARY = $(TERM_LIBDIR)/libtermcap.a

GLOB_LIBDIR = $(dot)/$(LIBSUBDIR)/glob
GLOB_LIBRARY = $(GLOB_LIBDIR)/libglob.a
BASH_ALWAYSLD = $(GLOB_LIBRARY) $(TERMCAP_LIBRARY) $(TILDE_LIBRARY) $(READLINE_LIBRARY) $(SHLIB_LIBRARY) $(BUILTINS_LIBRARY)
if USE_PDCURSES #test env var for now
bash_LDADD = ${BASH_ALWAYSLD}
else
bash_LDADD = ${BASH_ALWAYSLD}
endif

TILDE_LIBDIR = $(dot)/$(LIBSUBDIR)/tilde
TILDE_LIBRARY = $(TILDE_LIBDIR)/libtilde.a

INTL_LIBDIR = $(dot)/$(LIBSUBDIR)/intl
INTL_LIBRARY = $(INTL_LIBDIR)/libintl.a

LIBINTL_H = @LIBINTL_H@

# libiconv
LIBICONV = @LIBICONV@

# tests
LIBINTL = @LIBINTL@
LTLIBINTL = @LTLIBINTL@
INTLLIBS = @INTLLIBS@
INTLOBJS = @INTLOBJS@

# Our malloc.
MALLOC_TARGET = @MALLOC_TARGET@

MALLOC_LIBRARY = @MALLOC_LIBRARY@

BASHINCDIR = ${srcdir}/include
BASHINCFILES =	 $(BASHINCDIR)/posixstat.h $(BASHINCDIR)/ansi_stdlib.h \
		 $(BASHINCDIR)/filecntl.h $(BASHINCDIR)/posixdir.h \
		 $(BASHINCDIR)/memalloc.h $(BASHINCDIR)/stdc.h \
		 $(BASHINCDIR)/posixjmp.h $(BASHINCDIR)/posixwait.h \
		 $(BASHINCDIR)/posixtime.h $(BASHINCDIR)/systimes.h \
		 $(BASHINCDIR)/unionwait.h $(BASHINCDIR)/maxpath.h \
		 $(BASHINCDIR)/shtty.h $(BASHINCDIR)/typemax.h \
		 $(BASHINCDIR)/ocache.h

LIBRARYLDFLAGS = $(READLINELDFLAGS) $(HISTORYLDFLAGS) $(GLOBLDFLAGS) \
		  $(TILDELDFLAGS) $(MALLOCLDFLAGS) $(SHLIBLDFLAGS)

#
# The shell itself
#

# The main source code for the Bourne Again SHell.
# y.tab.c conflicts with parse.y jobs.c nojobs.c
CSOURCES = shell.c eval.c parse.y general.c make_cmd.c print_cmd.c  \
	   dispose_cmd.c execute_cmd.c variables.c  version.c \
	   expr.c copy_cmd.c flags.c subst.c hashcmd.c hashlib.c support/signames.c mailcheck.c \
	   test.c trap.c alias.c  braces.c \
	   input.c bashhist.c array.c arrayfunc.c assoc.c sig.c pathexp.c \
	   unwind_prot.c siglist.c bashline.c bracecomp.c error.c \
	   list.c stringlib.c locale.c findcmd.c redir.c \
	   pcomplete.c pcomplib.c syntax.c xmalloc.c debug.c osfixes.c

# headers in top-level source directory that get installed by install-headers
INSTALLEDHEADERS = shell.h bashjmp.h command.h syntax.h general.h error.h \
		    variables.h array.h assoc.h arrayfunc.h quit.h dispose_cmd.h \
		    make_cmd.h subst.h sig.h externs.h builtins.h \
		    bashtypes.h xmalloc.h config-top.h config-bot.h \
		    bashintl.h bashansi.h bashjmp.h alias.h hashlib.h \
		    conftypes.h unwind_prot.h jobs.h siglist.h \
		    execute_cmd.h
INSTALLEDBUILTINSHEADERS = bashgetopt.h common.h getopt.h
INSTALLED_INCFILES =	 posixstat.h ansi_stdlib.h filecntl.h posixdir.h \
	memalloc.h stdc.h posixjmp.h posixwait.h posixtime.h systimes.h \
	unionwait.h maxpath.h shtty.h typemax.h ocache.h chartypes.h gettext.h \
	posixstat.h shmbchar.h shmbutil.h stat-time.h

# header files chosen based on running of configure
SIGNAMES_H = @SIGNAMES_H@

# object files chosen based on running of configure
SIGLIST_O = @SIGLIST_O@
SIGNAMES_O = @SIGNAMES_O@

#ARRAY_O = @ARRAY_O@

# Where the source code of the shell builtins resides.
BUILTIN_SRCDIR=$(srcdir)/builtins
DEFSRC=$(BUILTIN_SRCDIR)
BUILTIN_ABSSRC=${topdir}/builtins
DEFDIR = $(dot)/builtins
DEBUGGER_DIR = $(dot)/debugger

BUILTINS_LIBRARY = $(DEFDIR)/libbuiltins.a

# Documentation for the shell.
DOCSRC = $(srcdir)/doc
DOCDIR = $(dot)/doc

# Translations and other i18n support files
PO_SRC = $(srcdir)/po/
PO_DIR = $(dot)/po/

SIGNAMES_SUPPORT = $(SUPPORT_SRC)mksignames.c

SUPPORT_SRC = $(srcdir)/support/
SDIR = $(dot)/support

TESTS_SUPPORT = recho$(EXEEXT) zecho$(EXEEXT) printenv$(EXEEXT) xcase$(EXEEXT)
CREATED_SUPPORT = signames.h recho$(EXEEXT) zecho$(EXEEXT) printenv$(EXEEXT) \
		  tests/recho$(EXEEXT) tests/zecho$(EXEEXT) \
		  tests/printenv$(EXEEXT) xcase$(EXEEXT) tests/xcase$(EXEEXT) \
		  mksignames$(EXEEXT) lsignames.h \
		  mksyntax${EXEEXT} syntax.c $(VERSPROG) $(VERSOBJ) \
		  buildversion.$(OBJEXT) mksignames.$(OBJEXT) signames.$(OBJEXT) buildsignames.$(OBJEXT)

CREATEDHEADERS = signames.h config.h pathnames.h version.h y.tab.h \
		  ${DEFDIR}/builtext.h

OTHER_DOCS = $(srcdir)/CHANGES $(srcdir)/COMPAT $(srcdir)/NEWS $(srcdir)/POSIX \
	$(srcdir)/RBASH $(srcdir)/README
OTHER_INSTALLED_DOCS = CHANGES COMPAT NEWS POSIX RBASH README

LOADABLES_DIR = ${top_builddir}/examples/loadables

# Keep GNU Make from exporting the entire environment for small machines.
#.NOEXPORT:

.made: $(Program) bashbug $(SDIR)/man2html$(EXEEXT)
	@echo "$(Program) last made for a $(Machine) running $(OS)" >.made


bashbug: $(SDIR)/bashbug.sh $(VERSPROG)
	@sed -e "s%!PATCHLEVEL!%$(PatchLevel)%" \
	     $(SDIR)/bashbug.sh > $@
	@chmod a+rx bashbug

strip:	$(Program) .made
	$(STRIP) $(Program)
	ls -l $(Program)
	-$(SIZE) $(Program)

lint:
	${MAKE} ${MFLAGS} ADDON_CFLAGS='${GCC_LINT_FLAGS}' .made

asan:
	${MAKE} ${MFLAGS} ADDON_CFLAGS='${ASAN_XCFLAGS}' ADDON_LDFLAGS='${ASAN_XLDFLAGS}' .made

valgrind:
	${MAKE} ${MFLAGS} ADDON_CFLAGS='-DDISABLE_MALLOC_WRAPPERS' ADDON_LDFLAGS= .made

# cheating
gcov:
	${MAKE} ${MFLAGS} CFLAGS=-g ADDON_CFLAGS='${GCOV_XCFLAGS}' ADDON_LDFLAGS='${GCOV_XLDFLAGS}' .made

# have to make this separate because making tests depend on $(PROGRAM)
asan-tests: asan  $(TESTS_SUPPORT)
	@-test -d tests || mkdir tests
	@cp $(TESTS_SUPPORT) tests
	@( cd $(srcdir)/tests && \
		BUILD_DIR=$(BUILD_DIR) PATH=$(BUILD_DIR)/tests:$$PATH THIS_SH=$(THIS_SH) $(SHELL) ${TESTSCRIPT} )

profiling-tests:	${PROGRAM}
	@test "X$$PROFILE_FLAGS" == "X" && { echo "profiling-tests: must be built with profiling enabled" >&2; exit 1; }
	@${MAKE} ${MFLAGS} tests TESTSCRIPT=run-gprof

version.h:
	$(SHELL) $(SUPPORT_SRC)mkversion.sh -b -S ${topdir} -s $(RELSTATUS) -d $(Version) -o newversion.h \
		&& mv newversion.h version.h

bashversion$(EXEEXT): buildversion.$(OBJEXT) $(SUPPORT_SRC)bashversion.c
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)bashversion.c buildversion.$(OBJEXT) ${LIBS_FOR_BUILD}

buildversion.$(OBJEXT): $(srcdir)/version.c
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -c -o $@ $(srcdir)/version.c

buildversion.$(OBJEXT): bashintl.h $(BASHINCDIR)/gettext.h
buildversion.$(OBJEXT): version.h patchlevel.h conftypes.h

# old rules
GRAM_H = parser-built
y.tab.$(OBJEXT): y.tab.h y.tab.c ${GRAM_H} command.h ${BASHINCDIR}/stdc.h input.h
${GRAM_H}:	y.tab.h
	@-if test -f y.tab.h ; then \
		cmp -s $@ y.tab.h 2>/dev/null || cp -p y.tab.h $@; \
	fi

y.tab.c: parse.y
#	-if test -f y.tab.h; then mv -f y.tab.h old-y.tab.h; fi
	$(YACC) -d $(srcdir)/parse.y
	$(RM) parser-built
	touch parser-built
#	-if cmp -s old-y.tab.h y.tab.h; then mv old-y.tab.h y.tab.h; else cp -p y.tab.h ${GRAM_H}; fi

y.tab.h: y.tab.c
	@true

debug.$(OBJEXT): debug.c

signames.$(OBJEXT): $(SUPPORT_SRC)signames.c
	$(RM) $@
	$(CC) $(CCFLAGS) -c $(SUPPORT_SRC)signames.c

buildsignames.$(OBJEXT):	$(SUPPORT_SRC)signames.c
	$(RM) $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -o $@ -c $(SUPPORT_SRC)signames.c

mksignames.$(OBJEXT):	$(SUPPORT_SRC)mksignames.c
	$(RM) $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) -DBUILDTOOL -c $(SUPPORT_SRC)mksignames.c

mksignames$(EXEEXT):	mksignames.$(OBJEXT) buildsignames.$(OBJEXT)
	$(RM) $@
	$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ mksignames.$(OBJEXT) buildsignames.$(OBJEXT) ${LIBS_FOR_BUILD}

mksyntax$(EXEEXT):	${srcdir}/mksyntax.c config.h syntax.h ${BASHINCDIR}/chartypes.h bashansi.h
	$(RM) $@
	${CC_FOR_BUILD} ${CCFLAGS_FOR_BUILD} ${LDFLAGS_FOR_BUILD} -o $@ ${srcdir}/mksyntax.c ${LIBS_FOR_BUILD}

# make a list of signals for the local system -- this is done when we're
# *not* cross-compiling
lsignames.h:   mksignames$(EXEEXT)
	$(RM) $@
	./mksignames$(EXEEXT) $@

# copy the correct signames header file to signames.h
signames.h: $(SIGNAMES_H)
	-if cmp -s $(SIGNAMES_H) $@ ; then :; else $(RM) $@ ; $(CP) $(SIGNAMES_H) $@ ; fi

syntax.c:	mksyntax${EXEEXT} $(srcdir)/syntax.h 
	$(RM) $@
	./mksyntax$(EXEEXT) -o $@

$(SDIR)/man2html$(EXEEXT):	${SUPPORT_SRC}/man2html.c
	@(cd $(SDIR) && $(MAKE) $(MFLAGS) all ) || exit 1

Makefiles makefiles:	config.status $(srcdir)/Makefile.in
	@for mf in $(CREATED_MAKEFILES); do \
		CONFIG_FILES=$$mf CONFIG_HEADERS= $(SHELL) ./config.status || exit 1; \
	done

pathnames.h:		Makefile $(srcdir)/pathnames.h.in
	@sed -e 's|@DEBUGGER_START_FILE\@|${DEBUGGER_START_FILE}|g' $(srcdir)/pathnames.h.in > pathnames.tmp
	@if test -f $@; then \
		cmp -s pathnames.tmp $@ || mv pathnames.tmp $@; \
	else \
		mv pathnames.tmp $@; \
	fi
	@${RM} pathnames.tmp

loadables:
	cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) all

doc documentation:  force
	@(cd $(DOCDIR) ; $(MAKE) $(MFLAGS) )

info dvi ps: force
	@(cd $(DOCDIR) ; $(MAKE) $(MFLAGS) CFLAGS='$(CCFLAGS)' $@ )

#force:

# unused
#TAGS:	$(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE)
#	( cd $(topdir) && $(ETAGS) $(ETAGSFLAGS) $(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE) )

#tags:	$(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE)
#	( cd $(topdir) && $(CTAGS) $(CTAGSFLAGS) $(SOURCES) $(BUILTIN_C_SRC) $(LIBRARY_SOURCE) > $@ )

# Targets that actually do things not part of the build

installdirs:
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(bindir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(man1dir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(infodir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(docdir)
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

install:	.made installdirs
	$(INSTALL_PROGRAM) $(INSTALLMODE) $(Program) $(DESTDIR)$(bindir)/$(Program)
	$(INSTALL_SCRIPT) $(INSTALLMODE2) bashbug $(DESTDIR)$(bindir)/bashbug
	$(INSTALLCMD) $(OTHER_DOCS) $(DESTDIR)$(docdir)
	-( cd $(DOCDIR) ; $(MAKE) $(MFLAGS) \
		man1dir=$(man1dir) man1ext=$(man1ext) \
		man3dir=$(man3dir) man3ext=$(man3ext) \
		infodir=$(infodir) htmldir=$(htmldir) DESTDIR=$(DESTDIR) $@ )
	-( cd $(DEFDIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

install-strip:
	$(MAKE) $(MFLAGS) INSTALL_PROGRAM='$(INSTALL_PROGRAM) -s' \
		prefix=${prefix} exec_prefix=${exec_prefix} \
		DESTDIR=$(DESTDIR) install

install-headers-dirs:
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)/builtins
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(headersdir)/include
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(pkgconfigdir)

install-headers: install-headers-dirs
	@for hf in $(INSTALLEDHEADERS) ; do \
		${INSTALLCMD} $(srcdir)/"$$hf" $(DESTDIR)$(headersdir)/$$hf || exit 1; \
	done
	@for hf in $(INSTALLED_INCFILES) ; do \
		${INSTALLCMD} $(BASHINCDIR)/"$$hf" $(DESTDIR)$(headersdir)/include/$$hf || exit 1; \
	done
	@for hf in $(INSTALLEDBUILTINSHEADERS) ; do \
		${INSTALLCMD} $(BUILTIN_SRCDIR)/"$$hf" $(DESTDIR)$(headersdir)/builtins/$$hf || exit 1; \
	done
	@for hf in $(CREATEDHEADERS) ; do \
		if test -f $(BUILD_DIR)/"$$hf" ; then \
			${INSTALLCMD} $(BUILD_DIR)/"$$hf" $(DESTDIR)$(headersdir)/$$hf || exit 1; \
		else \
			${INSTALLCMD} $(srcdir)/"$$hf" $(DESTDIR)$(headersdir)/$$hf || exit 1; \
		fi ; \
	done
	-$(INSTALLCMD) $(SDIR)/bash.pc $(DESTDIR)$(pkgconfigdir)/bash.pc

uninstall-headers:
	-( cd $(DESTDIR)$(headersdir) && $(RM) $(INSTALLEDHEADERS) )
	-( cd $(DESTDIR)$(headersdir)/include && $(RM) $(INSTALLED_INCFILES) )
	-( cd $(DESTDIR)$(headersdir)/builtins && $(RM) $(INSTALLEDBUILTINSHEADERS) )
	-( cd $(DESTDIR)$(headersdir) && $(RM) $(CREATEDHEADERS) )
	-( $(RM) $(DESTDIR)$(pkgconfigdir)/bash.pc )

uninstall:	.made
	$(RM) $(DESTDIR)$(bindir)/$(Program) $(DESTDIR)$(bindir)/bashbug
	-( cd $(DESTDIR)$(docdir) && ${RM} ${OTHER_INSTALLED_DOCS} )
	-( cd $(DOCDIR) ; $(MAKE) $(MFLAGS) \
		man1dir=$(man1dir) man1ext=$(man1ext) \
		man3dir=$(man3dir) man3ext=$(man3ext) \
		infodir=$(infodir) htmldir=$(htmldir) DESTDIR=$(DESTDIR) $@ )
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

.PHONY: basic-clean clean realclean maintainer-clean distclean mostlyclean maybe-clean
LIB_SUBDIRS = 
#LIB_SUBDIRS = ${RL_LIBDIR}  ${HIST_LIBDIR} ${TERM_LIBDIR} ${GLOB_LIBDIR} \
#		${INTL_LIBDIR} ${TILDE_LIBDIR} ${MALLOC_LIBDIR} ${SH_LIBDIR}

basic-clean:
	$(RM) $(Program) bashbug
	find -name "*.$(OBJEXT)" -exec rm "{}" ";"
	$(RM) .build .made version.h 

clean:	basic-clean
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd builtins && $(MAKE) $(MFLAGS) $@ )
	-( cd $(SDIR) && $(MAKE) $(MFLAGS) $@ )
	-for libdir in ${LIB_SUBDIRS}; do \
		(cd $$libdir && test -f Makefile && $(MAKE) $(MFLAGS) $@) ;\
	done
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	$(RM) $(CREATED_SUPPORT)

mostlyclean: basic-clean
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd builtins && $(MAKE) $(MFLAGS) $@ )
	-( cd $(SDIR) && $(MAKE) $(MFLAGS) $@ )
	-for libdir in ${LIB_SUBDIRS}; do \
		(cd $$libdir && test -f Makefile && $(MAKE) $(MFLAGS) $@) ;\
	done
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )

distclean:	basic-clean maybe-clean
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd builtins && $(MAKE) $(MFLAGS) $@ )
	-( cd $(SDIR) && $(MAKE) $(MFLAGS) $@ )
	-for libdir in ${LIB_SUBDIRS}; do \
		(cd $$libdir && test -f Makefile && $(MAKE) $(MFLAGS) $@) ;\
	done
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	$(RM) $(CREATED_CONFIGURE) tags TAGS 
	$(RM) $(CREATED_SUPPORT) Makefile $(CREATED_MAKEFILES) pathnames.h

maintainer-clean:	basic-clean
	@echo This command is intended for maintainers to use.
	@echo It deletes files that may require special tools to rebuild.
	$(RM) y.tab.c y.tab.h parser-built tags TAGS
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd builtins && $(MAKE) $(MFLAGS) $@ )
	( cd $(SDIR) && $(MAKE) $(MFLAGS) $@ )
	-for libdir in ${LIB_SUBDIRS}; do \
		(cd $$libdir && test -f Makefile && $(MAKE) $(MFLAGS) $@) ;\
	done
	-( cd $(PO_DIR) ; $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	-( cd $(LOADABLES_DIR) && $(MAKE) $(MFLAGS) DESTDIR=$(DESTDIR) $@ )
	$(RM) $(CREATED_CONFIGURE) $(CREATED_MAKEFILES)
	$(RM) $(CREATED_SUPPORT) Makefile pathnames.h

maybe-clean:
	-if test X"`cd $(topdir) && pwd -P`" != X"`cd $(BUILD_DIR) && pwd -P`" ; then \
		$(RM) parser-built y.tab.c y.tab.h ; \
	fi

recho$(EXEEXT):		$(SUPPORT_SRC)recho.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)recho.c ${LIBS_FOR_BUILD}

zecho$(EXEEXT):		$(SUPPORT_SRC)zecho.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)zecho.c ${LIBS_FOR_BUILD}

printenv$(EXEEXT):	$(SUPPORT_SRC)printenv.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)printenv.c ${LIBS_FOR_BUILD}

xcase$(EXEEXT):	$(SUPPORT_SRC)xcase.c
	@$(CC_FOR_BUILD) $(CCFLAGS_FOR_BUILD) ${LDFLAGS_FOR_BUILD} -o $@ $(SUPPORT_SRC)xcase.c ${LIBS_FOR_BUILD}

symlinks:
	$(SHELL) $(SUPPORT_SRC)fixlinks -s $(srcdir)

xdist:	force
	( cd $(DOCDIR) && $(MAKE) $(MFLAGS) $@ )
	( cd po && $(MAKE) $(MFLAGS) $@ )

depend:	depends

depends: force
	$(Program) $(SUPPORT_SRC)mkdep -c ${CC} -- ${CCFLAGS} ${CSOURCES}

#### PRIVATE TARGETS ####
hashtest:	hashlib.c
	$(CC) -DTEST_HASHING $(CCFLAGS) $(TEST_NBUCKETS) -o $@ $(srcdir)/hashlib.c xmalloc.$(OBJEXT) $(INTL_LIB) $(MALLOC_LIBRARY)
