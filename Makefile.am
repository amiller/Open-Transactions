# -*- fill-column: 72 -*-
AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I build-aux/m4
EXTRA_DIST = GETTING-STARTED.txt INSTALL-Android.txt			\
             INSTALL-DebianStable.txt INSTALL-Mac-Linux-FreeBSD.txt	\
             INSTALL-Windows.txt LICENSE-AND-CREDITS.txt		\
             PUBKEY-FellowTraveler.asc README.md VERSION

lib_LTLIBRARIES = libOTLib.la
bin_PROGRAMS = ot ot_server otcreatemint signcontract
AM_CPPFLAGS = $(DEPS_CFLAGS) $(BOOST_CPPFLAGS)
libOTLib_la_CPPFLAGS = -I$(top_srcdir)/OTLib/bigint -I$(top_srcdir)/OTLib/Lucre -I$(top_scdir)/irrxml
libOTLib_la_LIBADD = $(DEPS_LIBS) $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB)
client_ldadd = $(DEPS_LIBS) libOTLib.la $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB)
ot_CPPFLAGS = -I$(top_srcdir)/OTLib -I$(top_srcdir)/OTLib/simpleini
ot_LDADD = $(client_ldadd)
ot_server_CPPFLAGS = -I$(top_srcdir)/OTLib -I$(top_srcdir)/OTLib/simpleini
ot_server_LDADD = $(client_ldadd)
otcreatemint_CPPFLAGS = -I$(top_srcdir)/OTLib
signcontract_CPPFLAGS = -I$(top_srcdir)/OTLib
otcreatemint_LDADD = $(client_ldadd)
signcontract_LDADD = $(client_ldadd)
if TRANSPORT_ZMQ
transport_client_api = testwallet/xmlrpcxx_client.cpp
transport_server_api = transaction/xmlrpcxx_server.cpp
ot_CXXFLAGS = -DOT_ZMQ_MODE
endif

if TRANSPORT_TESTCLIENT
transport_client_api = testwallet/testclient.cpp
transport_server_api = transaction/testserver.cpp
endif

ot_SOURCES = testwallet/OpenTransactions.cpp			\
                     testwallet/OTAPI.cpp testwallet/OTAPI_Wrapper.cpp	\
                     testwallet/OTServerConnection.cpp			\
                     testwallet/OTClient.cpp				\
                     testwallet/SSL-Example/SFSocket.c			\
                     $(transport_client_api)

EXTRA_ot_SOURCES = testwallet/xmlrpcxx_client.cpp	\
                           testwallet/testclient.cpp

ot_server_SOURCES = transaction/OTClientConnection.cpp	\
                          transaction/OTServer.cpp		\
                          transaction/SSL-Example/SFSocket.c	\
                          $(transport_server_api)

EXTRA_ot_server_SOURCES = testwallet/xmlrpcxx_client.cpp	\
                            testwallet/testclient.cpp

otcreatemint_SOURCES = util/otcreatemint/main.cpp
signcontract_SOURCES = util/signcontract/main.cpp

bigintsources = OTLib/bigint/BigUnsigned.cc OTLib/bigint/BigInteger.cc	\
                OTLib/bigint/BigIntegerAlgorithms.cc			\
                OTLib/bigint/BigUnsignedInABase.cc			\
                OTLib/bigint/BigIntegerUtils.cc

bigintheaders = OTLib/bigint/BigUnsigned.hh OTLib/bigint/BigInteger.hh	\
		OTLib/bigint/BigUnsignedInABase.hh			\
		OTLib/bigint/BigIntegerUtils.hh				\
		OTLib/bigint/BigIntegerLibrary.hh

lucresources = OTLib/Lucre/bankimp.cpp
lucreheaders = OTLib/Lucre/bank.h
irrxmlsources = OTLib/irrxml/irrXML.cpp
irrxmlheaders = OTLib/irrxml/irrXML.h

libOTLib_la_SOURCES = $(bigintsources) $(lucresources) $(irrxmlsources)	\
                      OTLib/OTData.cpp OTLib/OTString.cpp		\
                      OTLib/OTStringXML.cpp OTLib/OTASCIIArmor.cpp	\
                      OTLib/OTContract.cpp OTLib/OTSmartContract.cpp	\
                      OTLib/OTWallet.cpp OTLib/OTSignedFile.cpp		\
                      OTLib/OTPseudonym.cpp OTLib/OTMint.cpp		\
                      OTLib/OTInstrument.cpp OTLib/OTCheque.cpp		\
                      OTLib/OTPurse.cpp OTLib/OTLog.cpp			\
                      OTLib/OTToken.cpp OTLib/OTTransactionType.cpp	\
                      OTLib/OTItem.cpp OTLib/OTBasket.cpp		\
                      OTLib/OTTransaction.cpp OTLib/OTLedger.cpp	\
                      OTLib/OTAccount.cpp OTLib/OTEnvelope.cpp		\
                      OTLib/OTAssetContract.cpp				\
                      OTLib/OTServerContract.cpp OTLib/OTOffer.cpp	\
                      OTLib/OTAgreement.cpp OTLib/OTTrackable.cpp	\
                      OTLib/OTCron.cpp OTLib/OTCronItem.cpp		\
                      OTLib/OTTrade.cpp OTLib/OTPaymentPlan.cpp		\
                      OTLib/OTMarket.cpp OTLib/OTPayload.cpp		\
                      OTLib/OTMessage.cpp OTLib/OTMessageBuffer.cpp	\
                      OTLib/OTIdentifier.cpp OTLib/OTAsymmetricKey.cpp	\
                      OTLib/OTSignature.cpp OTLib/OTScript.cpp		\
                      OTLib/OTScriptable.cpp OTLib/OTBylaw.cpp		\
                      OTLib/OTStorage.cpp OTLib/OTDataCheck.cpp		\
                      OTLib/Generics.pb.cpp OTLib/Markets.pb.cpp	\
                      OTLib/Bitcoin.pb.cpp OTLib/Moneychanger.pb.cpp	\
                      OTLib/anyoption.cpp OTLib/Timer.cpp		\
                      OTLib/easyzlib.c OTLib/mkcert.c			\
                      OTLib/simpleini/ConvertUTF.c

include_HEADERS = $(bigintheaders) $(lucreheaders) $(irrxmlheaders)	\
                  OTLib/anyoption.h OTLib/Bitcoin.pb.h OTLib/easyzlib.h	\
                  OTLib/Generics.pb.h OTLib/Markets.pb.h		\
                  OTLib/Moneychanger.pb.h OTLib/OTAccount.h		\
                  OTLib/OTAgreement.h OTLib/OTASCIIArmor.h		\
                  OTLib/OTAssetContract.h OTLib/OTAsymmetricKey.h	\
                  OTLib/OTBasket.h OTLib/OTBylaw.h OTLib/OTCheque.h	\
                  OTLib/OTContract.h OTLib/OTCron.h OTLib/OTCronItem.h	\
                  OTLib/OTDataCheck.h OTLib/OTData.h OTLib/OTEnvelope.h	\
                  OTLib/OTglobal.h OTLib/OTIdentifier.h			\
                  OTLib/OTInstrument.h OTLib/OTItem.h OTLib/OTLedger.h	\
                  OTLib/OTLib.h OTLib/OTLibPriv.h OTLib/OTLog.h		\
                  OTLib/OTMarket.h OTLib/OTMessageBuffer.h		\
                  OTLib/OTMessage.h OTLib/OTMint.h OTLib/OTOffer.h	\
                  OTLib/OTPayload.h OTLib/OTPaymentPlan.h		\
                  OTLib/OTPseudonym.h OTLib/OTPurse.h			\
                  OTLib/OTScriptable.h OTLib/OTScript.h			\
                  OTLib/OTServerContract.h OTLib/OTSignature.h		\
                  OTLib/OTSignedFile.h OTLib/OTSmartContract.h		\
                  OTLib/OTStorage.h OTLib/OTString.h			\
                  OTLib/OTStringXML.h OTLib/OTToken.h			\
                  OTLib/OTTrackable.h OTLib/OTTrade.h			\
                  OTLib/OTTransaction.h OTLib/OTTransactionType.h	\
                  OTLib/OTWallet.h OTLib/stacktrace.h OTLib/Timer.h
