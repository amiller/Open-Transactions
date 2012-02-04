AC_PREREQ(2.64)
LT_PREREQ([2.2.6])
AC_INIT([Open-Transactions], [0.77.0], [Fellow-Traveler], [Open-Transactions], [https://github.com/FellowTraveler/Open-Transactions])
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE([1.11 foreign])
AM_SILENT_RULES([yes])
LT_INIT([dlopen])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADERS([config.h])

PKG_PROG_PKG_CONFIG([0.26])
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AX_BOOST_BASE([1.46.0])
AX_BOOST_THREAD

AC_ARG_WITH([transport],
        [AS_HELP_STRING([--with-transport@<:@=zmq@:>@],
          [Choose a transport backend (available: zmq, testclient)])],
            [# using 'case' with empty bodies just to catch invalid values for now.
             case "${withval}" in
                   zmq) true ;;
                   testclient) true ;;
                   *) AC_MSG_ERROR([bad value ${withval} for --with-transport]) ;;
             esac],
            [with_transport=zmq])
AM_CONDITIONAL([TRANSPORT_ZMQ], [test "$with_transport" == zmq])
AM_CONDITIONAL([TRANSPORT_TESTCLIENT], [test "$with_transport" == testclient])
AS_IF([test "$with_transport" == zmq],
   [PKG_CHECK_MODULES([DEPS], [protobuf >= 2.4.0 openssl >= 1.0.0
                               chaiscript >= 3.1.0 libzmq >= 2.1.10])],
   [PKG_CHECK_MODULES([DEPS], [protobuf >= 2.4.0 openssl >= 1.0.0
                               chaiscript >= 3.1.0])])

AC_CONFIG_SRCDIR([OTLib/OTPurse.cpp])

AC_CHECK_HEADERS([msgpack.h], [],
                [AC_MSG_ERROR([No header files for libmsgpack found.])])
AC_CHECK_LIB(msgpack, msgpack_unpack)



AC_CONFIG_FILES([Makefile])
AC_OUTPUT
