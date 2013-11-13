#############################################################################
# Makefile for building: SPGrab
# Generated by qmake (2.01a) (Qt 4.8.2) on: sre 20. mar 10:26:34 2013
# Project:  SPGrab.pro
# Template: app
# Command: c:/qtsdksource/bin/qmake.exe -spec ../../../qtSDKsource/mkspecs/win32-g++ -o Makefile SPGrab.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = c:/qtsdksource/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = cp -r
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: SPGrab.pro  ../../../qtSDKsource/mkspecs/win32-g++/qmake.conf ../../../qtSDKsource/mkspecs/qconfig.pri \
		../../../qtSDKsource/mkspecs/features/qt_functions.prf \
		../../../qtSDKsource/mkspecs/features/qt_config.prf \
		../../../qtSDKsource/mkspecs/features/exclusive_builds.prf \
		../../../qtSDKsource/mkspecs/features/default_pre.prf \
		../../../qtSDKsource/mkspecs/features/win32/default_pre.prf \
		../../../qtSDKsource/mkspecs/features/release.prf \
		../../../qtSDKsource/mkspecs/features/debug_and_release.prf \
		../../../qtSDKsource/mkspecs/features/default_post.prf \
		../../../qtSDKsource/mkspecs/features/win32/default_post.prf \
		../../../qtSDKsource/mkspecs/features/static.prf \
		../../../qtSDKsource/mkspecs/features/win32/rtti.prf \
		../../../qtSDKsource/mkspecs/features/win32/exceptions_off.prf \
		../../../qtSDKsource/mkspecs/features/win32/stl.prf \
		../../../qtSDKsource/mkspecs/features/warn_on.prf \
		../../../qtSDKsource/mkspecs/features/qt.prf \
		../../../qtSDKsource/mkspecs/features/win32/thread.prf \
		../../../qtSDKsource/mkspecs/features/moc.prf \
		../../../qtSDKsource/mkspecs/features/win32/windows.prf \
		../../../qtSDKsource/mkspecs/features/resources.prf \
		../../../qtSDKsource/mkspecs/features/uic.prf \
		../../../qtSDKsource/mkspecs/features/yacc.prf \
		../../../qtSDKsource/mkspecs/features/lex.prf \
		../../../qtSDKsource/mkspecs/features/include_source_dir.prf \
		c:/qtSDKsource/lib/qtmain.prl \
		c:/qtSDKsource/lib/QtGui.prl \
		c:/qtSDKsource/lib/QtNetwork.prl \
		c:/qtSDKsource/lib/QtCore.prl
	$(QMAKE) -spec ../../../qtSDKsource/mkspecs/win32-g++ -o Makefile SPGrab.pro
../../../qtSDKsource/mkspecs/qconfig.pri:
../../../qtSDKsource/mkspecs/features/qt_functions.prf:
../../../qtSDKsource/mkspecs/features/qt_config.prf:
../../../qtSDKsource/mkspecs/features/exclusive_builds.prf:
../../../qtSDKsource/mkspecs/features/default_pre.prf:
../../../qtSDKsource/mkspecs/features/win32/default_pre.prf:
../../../qtSDKsource/mkspecs/features/release.prf:
../../../qtSDKsource/mkspecs/features/debug_and_release.prf:
../../../qtSDKsource/mkspecs/features/default_post.prf:
../../../qtSDKsource/mkspecs/features/win32/default_post.prf:
../../../qtSDKsource/mkspecs/features/static.prf:
../../../qtSDKsource/mkspecs/features/win32/rtti.prf:
../../../qtSDKsource/mkspecs/features/win32/exceptions_off.prf:
../../../qtSDKsource/mkspecs/features/win32/stl.prf:
../../../qtSDKsource/mkspecs/features/warn_on.prf:
../../../qtSDKsource/mkspecs/features/qt.prf:
../../../qtSDKsource/mkspecs/features/win32/thread.prf:
../../../qtSDKsource/mkspecs/features/moc.prf:
../../../qtSDKsource/mkspecs/features/win32/windows.prf:
../../../qtSDKsource/mkspecs/features/resources.prf:
../../../qtSDKsource/mkspecs/features/uic.prf:
../../../qtSDKsource/mkspecs/features/yacc.prf:
../../../qtSDKsource/mkspecs/features/lex.prf:
../../../qtSDKsource/mkspecs/features/include_source_dir.prf:
c:\qtSDKsource\lib\qtmain.prl:
c:\qtSDKsource\lib\QtGui.prl:
c:\qtSDKsource\lib\QtNetwork.prl:
c:\qtSDKsource\lib\QtCore.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ../../../qtSDKsource/mkspecs/win32-g++ -o Makefile SPGrab.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile