/**************************************************************
 *    
 *  OTAsymmetricKey.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


extern "C" 
{
#include <memory.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
}

#include <cstdio>
#include <cstring>
#include <cmath>


#include <string>
#include <iostream>


#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"
#include "OTAsymmetricKey.h"
#include "OTPayload.h"
#include "OTASCIIArmor.h"
#include "OTLog.h"


#define FALSE 0
#define TRUE 1






// --------------------------------------------------------

// static
OT_OPENSSL_CALLBACK * OTAsymmetricKey::s_pwCallback = NULL;

//static void SetPasswordCallback(p_OT_OPENSSL_CALLBACK pCallback);
//static p_OT_OPENSSL_CALLBACK GetPasswordCallback();
//static bool IsPasswordCallbackSet() { (NULL == s_pwCallback) ? false : true; }


void OTAsymmetricKey::SetPasswordCallback(OT_OPENSSL_CALLBACK * pCallback)
{
	if (NULL != s_pwCallback)
		OTLog::Output(0, "OTAsymmetricKey::SetPasswordCallback: WARNING: re-setting the password callback (one was already there)...\n");
	else
		OTLog::Output(0, "OTAsymmetricKey::SetPasswordCallback: FYI, setting the password callback to a non-NULL pointer (which is what we want.)\n");
	// -----------------------------------
	if (NULL == pCallback)
		OTLog::Error("OTAsymmetricKey::SetPasswordCallback: WARNING, setting the password callback to NULL! (OpenSSL will thus be forced to ask for the passphase "
					 "on the console, until this is called again and set properly.)\n");
	// -----------------------------------
	s_pwCallback = pCallback; // no need to delete function pointer that came before this function pointer.
}



OT_OPENSSL_CALLBACK * OTAsymmetricKey::GetPasswordCallback()
{
#if defined (OT_TEST_PASSWORD)
	OTLog::Output(2, "OTAsymmetricKey::GetPasswordCallback: WARNING, OT_TEST_PASSWORD *is* defined. The internal 'C'-based password callback was just "
				  "requested by OT (to pass to OpenSSL). So, returning the default_pass_cb password callback, which will automatically return "
				  "the 'test' password to OpenSSL, if/when it calls that callback function.\n");
	return &default_pass_cb;
#else
	if (IsPasswordCallbackSet())
	{
		OTLog::Output(2, "OTAsymmetricKey::GetPasswordCallback: FYI, the internal 'C'-based password callback is now being returning to OT, "
					  "which is passing it to OpenSSL "
					  "during a crypto operation. (If OpenSSL invokes it, then we should see other logs after this from when it triggers "
					  "whatever password-collection dialog is provided at startup by the (probably Java) OTAPI client.)\n");
		return s_pwCallback;
	}
	else
	{
		OTLog::Output(2, "OTAsymmetricKey::GetPasswordCallback: FYI, the internal 'C'-based password callback was requested by OT (to pass to OpenSSL), "
					  "but the callback hasn't been set yet. (Returning NULL CALLBACK to OpenSSL!! Thus causing it to instead ask for the passphrase on the CONSOLE, "
					  "since no Java password dialog was apparently available.)\n");
		return static_cast<OT_OPENSSL_CALLBACK *>(NULL);
	}
#endif	
}



// --------------------------------------------------------
//static
OTCaller * OTAsymmetricKey::s_pCaller = NULL;


// Takes ownership. UPDATE: doesn't, since he assumes the Java side
// created it and will therefore delete it when the time comes.
// I keep a pointer, but I don't delete the thing. Let Java do it.
//
bool OTAsymmetricKey::SetPasswordCaller(OTCaller & theCaller)
{
	OTLog::Output(0, "OTAsymmetricKey::SetPasswordCaller: Attempting to set the password caller... "
				  "(the Java code has passed us its custom password dialog object for later use if/when the "
				  "OT 'C'-based password callback is triggered by openssl.)\n");
	
	if (!theCaller.isCallbackSet())
	{
		OTLog::Error("OTAsymmetricKey::SetPasswordCaller: ERROR: OTCaller::setCallback() "
					 "MUST be called first, with an OTCallback-extended object passed to it,\n"
					 "BEFORE calling this function with that OTCaller. (Returning false.)\n");
		return false;
	}
	
	if (NULL != s_pCaller)
	{
		OTLog::Error("OTAsymmetricKey::SetPasswordCaller: WARNING: Setting the password caller again, even though "
					 "it was apparently ALREADY set... (Meaning Java has probably erroneously called this twice, "
					 "possibly passing the same OTCaller both times.)\n");
//		delete s_pCaller; // Let Java delete it.
	}
	
	s_pCaller = &theCaller;
	// ---------------------------
	
	OTAsymmetricKey::SetPasswordCallback(&souped_up_pass_cb);
	
	OTLog::Output(0, "OTAsymmetricKey::SetPasswordCaller: FYI, Successfully set the password caller object from "
				  "Java, and set the souped_up_pass_cb in C for OpenSSL (which triggers that Java object when the time is right.) Returning true.\n");

	return true;
}
// --------------------------------------------------------

OTCaller * OTAsymmetricKey::GetPasswordCaller()
{
	OTLog::vOutput(2, "OTAsymmetricKey::GetPasswordCaller(): FYI, this was just called by souped_up_pass_cb "
				   "(which must have just been called by OpenSSL.) "
				   "Returning s_pCaller == %s (Hopefully NOT NULL, so the custom password dialog can be triggered.)\n",
				   (NULL == s_pCaller) ? "NULL" : "VALID POINTER");
	
	return s_pCaller;
}




bool OT_API_Set_PasswordCallback(OTCaller & theCaller) // Caller must have Callback attached already.
{
	if (!theCaller.isCallbackSet())
	{
		OTLog::Error("ERROR in OT_API_Set_PasswordCallback:\nOTCaller::setCallback() "
					 "MUST be called first, with an OTCallback-extended class passed to it,\n"
					 "before then invoking this function (and passing that OTCaller as a parameter into this function.)\n");
		return false;
	}
	
	OTLog::Output(0, "OT_API_Set_PasswordCallback: FYI, calling OTAsymmetricKey::SetPasswordCaller(theCaller) now... (which is where "
				   "OT internally sets its pointer to the Java caller object, which must have been passed in as a parameter to this function. "
				   "This is also where OT either sets its internal 'C'-based password callback to the souped_up version which uses that Java caller object, "
				   "OR where OT sets its internal callback to NULL--which causes OpenSSL to ask for the passphrase on the CONSOLE instead.)\n");

	const bool bSuccess = OTAsymmetricKey::SetPasswordCaller(theCaller);
	
	OTLog::vOutput(0, "OT_API_Set_PasswordCallback: RESULT of call to OTAsymmetricKey::SetPasswordCaller: %s",
				   bSuccess ? "SUCCESS" : "FAILURE");
	
	return bSuccess;
}

// ***************************************************

/*
 extern "C"
 {
 typedef int OT_OPENSSL_CALLBACK(char *buf, int size, int rwflag, void *u); // <== Callback type, used for declaring.
 }
 
 // Used for the actual function definition (in the .cpp file).
 #define OPENSSL_CALLBACK_FUNC(name) extern \"C\" int (name)(char *buf, int size, int rwflag, void *u)
 */


// If the password callback isn't set, then it uses the default ("test") password.
//
OPENSSL_CALLBACK_FUNC(default_pass_cb)
{
	int len=0;
	
	// We'd probably do something else if 'rwflag' is 1

	const std::string str_userdata((NULL == userdata) ? "" : static_cast<char *>(userdata));

//	OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC: (Password callback hasn't been set yet...) Using 'test' pass phrase for \"%s\"\n", (char *)u);
	OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC (default_pass_cb): Using DEFAULT TEST PASSWORD: 'test' (for \"%s\")\n", str_userdata.c_str());
	
	// get pass phrase, length 'len' into 'tmp'
	//
//	std::string str_Password;
//	std::getline (std::cin, str_Password);

//	const char *tmp=""; // For now removing any possibility that "test" password can slip through.
	const char *tmp="test";
//	const char *tmp = str_Password.c_str();

	len = strlen(tmp);
//	len = str_Password.size();
	
	if (len <= 0)
	{
		OTLog::Output(0, "OPENSSL_CALLBACK_FUNC (default_pass_cb): Problem? Returning 0...\n");
		return 0;
	}
	
	// if too long, truncate
	if (len > size) 
		len = size;
	
	memcpy(buf, tmp, len);
	return len;
}


// --------------------------------------------------------


// This is the function that OpenSSL calls when it wants to ask the user for his password.
// If we return 0, that's bad, that means the password caller and callback failed somehow.
//
//typedef
//int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata); // <== Callback type, used for declaring.
OPENSSL_CALLBACK_FUNC(souped_up_pass_cb)
{		
	const std::string str_userdata((NULL == userdata) ? "" : static_cast<char *>(userdata));
	
	OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): Using OT Password Callback for \"%s\"\n", str_userdata.c_str());
	
	OTCaller * pCaller = OTAsymmetricKey::GetPasswordCaller();
	
	if (NULL == pCaller)
	{
		OTLog::Error("OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): OTCaller is NULL. Try calling OT_API_Set_PasswordCallback() first.\n");
		
		OT_ASSERT(0); // This will never actually happen, since SetPasswordCaller() and souped_up_pass_cb are activated in same place.
		
		// get pass phrase, length 'len' into 'tmp'
		/*
		int len=0;
		char *tmp=NULL;
//		tmp = "test";
		len = strlen(tmp);
		
		if (len <= 0) 
			return 0;
		
		// if too long, truncate
		if (len > size) 
			len = size;
		
		memcpy(buf, tmp, len);
		return len;		
		 */
	}
	// ---------------------------------------
	// The dialog should display this string (so the user knows what he is authorizing.)
	//
	pCaller->SetDisplay(str_userdata.c_str(), str_userdata.size());
	
	// ---------------------------------------
	if (1 == rwflag)
	{
		OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): Using OT Password Callback (asks twice) for \"%s\"...\n", 
					   str_userdata.c_str());
		pCaller->callTwo(); // This is where Java pops up a modal dialog and asks for password twice...
	}
	else
	{
		OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): Using OT Password Callback (asks once) for \"%s\"...\n", 
					   str_userdata.c_str());
		pCaller->callOne(); // This is where Java pops up a modal dialog and asks for password once...
	}
	// ---------------------------------------

	/*
	 NOTICE: (For security...)
	 
	 We are using an OTPassword object to collect the password from the caller. 
	 (We're not passing strings back and forth.) The OTPassword object is where we
	 can centralize our efforts to scrub the memory clean as soon as we're done with
	 the password. It's also designed to be light (no baggage) and to be passed around
	 easily, with a set-size array for the data.

	 Notice I am copying the password directly from the OTPassword object into the buffer
	 provided to me by OpenSSL. When the OTPassword object goes out of scope, then it cleans
	 up automatically.
	 */
	
	OTPassword thePassword;
	const bool bPassword = pCaller->GetPassword(thePassword);
	
	if (false == bPassword)
	{
		OTLog::Output(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): Failure in the API password callback. (Returning 0.)\n");
		return 0;
	}
	// --------------------------------------	
	/* 
	 http://openssl.org/docs/crypto/pem.html#
	 "The callback must return the number of characters in the passphrase or 0 if an error occurred."
	 */
	int len	= thePassword.getPasswordSize();
	
	if (len <= 0) 
	{
		OTLog::Output(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): 0 length (or less) password was "
					  "returned from the API password callback :-( Returning 0.\n");
		return 0;
	}
	
	// if too long, truncate
	if (len > size) 
		len = size;
	
	memcpy(buf, thePassword.getPassword(), len);
	return len;
}


//typedef
//int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata);


// ***************************************************

void OTAsymmetricKey::SetKey(EVP_PKEY * pKey, bool bIsPrivateKey/*=false*/)
{ 
	OT_ASSERT(NULL != pKey);
	
	Release(); 
	
	m_pKey			= pKey;
	m_bIsPublicKey	= !bIsPrivateKey;
	m_bIsPrivateKey	= bIsPrivateKey;
}



// Get the public key in ASCII-armored format with bookends  - ------- BEGIN PUBLIC KEY --------
// This version, so far, is escaped-only. Notice the "- " before the rest of the bookend starts.
bool OTAsymmetricKey::GetPublicKey(OTString & strKey, bool bEscaped/*=true*/) const
{
	OTASCIIArmor theArmor;
	
	if (GetPublicKey(theArmor))
	{
		if (bEscaped)
		{
			strKey.Concatenate("- -----BEGIN PUBLIC KEY-----\n"
							   "%s"
							   "- -----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
			
		}
		else {
			strKey.Concatenate("-----BEGIN PUBLIC KEY-----\n"
							   "%s"
							   "-----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
			
		}
		return true;
	}
	else {
		return false;
	}
}


/*
void OTbase64Decode(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
*/
/*
EVP_PKEY * pKey	OTGetPublicKey(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
 */

/*
 BIO* keyBio = BIO_new_mem_buf(TESTING_PUBLIC_KEY, 
 sizeof(TESTING_PUBLIC_KEY)); 
 public_key = d2i_PUBKEY_bio(keyBio, NULL); 
*/


// Decodes a public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This is the version that will handle the bookends ( --------- BEGIN PUBLIC KEY -------)
bool OTAsymmetricKey::SetPublicKey(const OTString & strKey, bool bEscaped/*=false*/)
{
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	// This reads the string into the Armor and removes the bookends. (----- BEGIN ...)
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromString((OTString &)strKey, bEscaped))
	{
		return SetPublicKey(theArmor);
	}
	else
		return false;
};



/*
 * An implementation of convertion from PGP public key format to OpenSSL equivalent
 * Support of RSA, DSA and Elgamal public keys
 *
 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

bool ExportRsaKey::FindPacketLength(unsigned char *pbData, int dataLength)
{
	packetTag = pbData[i++];

	if ((packetTag & 0x80) == 0) 
		return FALSE;

	if ((packetTag & 0x40))	{
		packetTag &= 0x3F;
		packetLength = pbData[i++];

		if( (packetLength >191) && (packetLength <224)) {
			packetLength = ((packetLength-192) << 8) + pbData[i++];
			return TRUE;
		}
		if( (packetLength > 223) && (packetLength < 255)) {
			packetLength = (1 << (packetLength & 0x1f));
			return TRUE;
		}
		if(packetLength == 255) {
			packetLength = (pbData[i]<<24) + (pbData[i+1]<<16) + (pbData[i+2]<<8) + pbData[i+3];
			i+=4;
			return TRUE;
		}
	}

	packetLength = packetTag & 3;
	packetTag = (packetTag >> 2) & 15;

	if(packetLength == 0) {
		packetLength = pbData[i++];
		return TRUE;
	}
	if(packetLength == 1) {
		packetLength = (pbData[i]<<8) + pbData[i+1];
		i+=2;
		return TRUE;
	}
	if(packetLength == 2) {
		packetLength = (pbData[i]<<24) + (pbData[i+1]<<16) + (pbData[i+2]<<8) + pbData[i+3];
		i+=4;
		return TRUE;
	}
	packetLength = dataLength - 1;
	return TRUE;
};

void ExportRsaKey::RSA_Key(unsigned char *pbData, int dataLength)
{
	int modulusLength, exponentLength;
	RSA* pKey = RSA_new();

	// Get the modulus
	modulusLength = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->n = BN_bin2bn (pbData + i + 2, modulusLength, NULL);
	i += modulusLength + 2;

	// Get the exponent
	exponentLength = (pbData[i]*256 + pbData[i+1]+7)/8;
	pKey->e = BN_bin2bn(pbData + i + 2, exponentLength, NULL);
	i += exponentLength + 2;

	pRsa = pKey;
};

void ExportRsaKey::DSA_Key(unsigned char *pbData, int dataLength)
{
	int pLen, qLen, gLen, yLen;
	DSA* pKey = DSA_new();

	// Get Prime P
	pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
	i += pLen + 2;

	// Get Prime Q
	qLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->q = BN_bin2bn(pbData + i + 2, qLen, NULL);
	i += qLen + 2;

	// Get Prime G
	gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
	i += gLen + 2;

	// Get Prime Y
	yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
	i += yLen + 2;

	pDsa = pKey;
};

void ExportRsaKey::Elgamal_Key(unsigned char *pbData, int dataLength)
{
	int pLen, gLen, yLen;
	ELGAMAL* pKey = (ELGAMAL*) malloc(sizeof(ELGAMAL));

	// Get Prime P
	pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
	i += pLen + 2;

	// Get Prime G
	gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
	pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
	i += gLen + 2;

	// Get Prime Y
	yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);       
	pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
	i += yLen + 2;

	pElgamal = pKey;
};

ExportRsaKey::ExportRsaKey(unsigned char *pbData, int dataLength)
{
	OT_ASSERT(NULL != pbData);
	OT_ASSERT(NULL != NULL && sizeof(pbData) == dataLength);

	// Memset insted of fill_n as the OpenSSL pRsa, pDsa and pElgamal do not have a implicit conversion to into or const char *
	std::memset(&pRsa,'\0',sizeof(pRsa));
	std::memset(&pDsa,'\0',sizeof(pDsa));
	std::memset(&pElgamal,'\0',sizeof(pElgamal));

	for (i = 0; i < dataLength; )
	{
		if (FindPacketLength(pbData,dataLength) == FALSE) break;

		if( (packetTag==6) || (packetTag==14) )  //  a public key
		{
			int algorithm;
			int version = pbData[i++];

			i += 4;  // skip time over 4 bytes

			if( (version==2) || (version==3) ) i += 2;  // skip validity over 2 bytes

			algorithm = pbData[i++];

			if( (algorithm == 1) || (algorithm == 2) || (algorithm == 3) ) // an RSA key
			{
				RSA_Key(pbData,dataLength);
				continue;
			}
			if (algorithm == 17) // a DSA key
			{
				DSA_Key(pbData,dataLength);
				continue;
			}
			if ((algorithm == 16) || (algorithm == 20)) // Elgamal key (not supported by OpenSSL)
			{
				Elgamal_Key(pbData,dataLength);
				continue;
			}
			i -= 6;
			if (version == 2 || version == 3) i -= 2;
		}
		i += packetLength;	
	}
};


// Decodes a PGP public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This function expects the bookends to be GONE already
// It just wants the base64 encoded data which is why we have ascii-armor
// object coming in instead of a string.
bool OTAsymmetricKey::LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey)
{	
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	/*
	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;
	
	// This base64 decodes the string into binary object theData
	strKey.GetData(theData);
	
	BIO* keyBio	= BIO_new_mem_buf((void*)theData.GetPayloadPointer(), theData.GetSize());
	
	//TODO Figure out which one of these is right, if any
	//	pReturnKey	= d2i_PUBKEY_bio(keyBio, NULL); 
	pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); // we'll try this one next
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		//		OTLog::vOutput(4, "Success reading public key from ASCII-armored data:\n%s",strKey.Get());
		return true;
	}
	else {
		//		OTLog::vOutput(4, "Failed reading public key from ASCII-armored data:\n%s",strKey.Get());
		return false;
	}
	
	*/
	
	
	/*
	 * An implementation of convertion from PGP public key format to OpenSSL equivalent
	 * Support of RSA, DSA and Elgamal public keys
	 *
	 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
	 *
	 * This program is distributed in the hope that it will be useful, 
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
	 * or FITNESS FOR A PARTICULAR PURPOSE.
	 * 
	 */
	int iRet =-1, len;
	BIO *bio, *b64, *bio_out;
	unsigned char buffer[520]; // Making it a bit bigger than 512 for safety reasons.
	BUF_MEM *bptr;
	PgpKeys pgpKeys;
	
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_mem_buf((void*)strKey.Get(), strKey.GetLength());
	bio_out = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);
	
	while((len = BIO_read(bio, buffer, 512)) > 0)
		BIO_write(bio_out, buffer, len);
	BIO_free_all(bio);
	bio = NULL;
	
	BIO_get_mem_ptr(bio_out, &bptr);
	
	pgpKeys = ExportRsaKey((unsigned char*)bptr->data, bptr->length);
	
	if(!pgpKeys.pRsa)
	{  
		OTLog::Output(5,  "\nNo RSA public key found.\n\n"); 
	}
	else
	{
		char* szModulusHex = BN_bn2hex(pgpKeys.pRsa->n);
		char* szExponentHex = BN_bn2hex(pgpKeys.pRsa->e);
		OTLog::vOutput(5, "RSA public key found : \n  Modulus (%d bits)\n", BN_num_bits(pgpKeys.pRsa->n));
		OTLog::vOutput(5, "  Exponent : 0x%s\n\n", szExponentHex);
		OTLog::vOutput(5, "RSA public key found : \nModulus (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pRsa->n), szModulusHex);
		OTLog::vOutput(5, "Exponent : 0x%s\n\n", szExponentHex);
		
		CRYPTO_free(szModulusHex);
		CRYPTO_free(szExponentHex);
	}
	
	if(!pgpKeys.pDsa)
	{  
		OTLog::Output(5, "No DSA public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pDsa->p);
		char* szQHex = BN_bn2hex(pgpKeys.pDsa->q);
		char* szGHex = BN_bn2hex(pgpKeys.pDsa->g);
		char* szYHex = BN_bn2hex(pgpKeys.pDsa->pub_key);
		OTLog::vOutput(5, "DSA public key found : \n  p (%d bits)\n", BN_num_bits(pgpKeys.pDsa->p));
		OTLog::vOutput(5, "  q (%d bits)\n", BN_num_bits(pgpKeys.pDsa->q));
		OTLog::vOutput(5, "  g (%d bits)\n", BN_num_bits(pgpKeys.pDsa->g));
		OTLog::vOutput(5, "public key (%d bits)\n\n", BN_num_bits(pgpKeys.pDsa->pub_key));
		OTLog::vOutput(5, "DSA public key found : \np (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->p), szPHex);
		OTLog::vOutput(5, "q (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->q),szQHex);
		OTLog::vOutput(5, "g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->g),szGHex);
		OTLog::vOutput(5, "public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pDsa->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szQHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	if(!pgpKeys.pElgamal)
	{  
		OTLog::Output(5, "No Elgamal public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pElgamal->p);
		char* szGHex = BN_bn2hex(pgpKeys.pElgamal->g);
		char* szYHex = BN_bn2hex(pgpKeys.pElgamal->pub_key);
		OTLog::vOutput(5, "Elgamal public key found : \n  p (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->p), szPHex);
		OTLog::vOutput(5, "  g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->g),szGHex);
		OTLog::vOutput(5, "  public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pElgamal->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	iRet = 0;
	
	BIO_free(bio_out);
	bio_out = NULL;
	
	/*
	if (pgpKeys.pRsa)
		RSA_free(pgpKeys.pRsa);
	if (pgpKeys.pDsa)
		DSA_free(pgpKeys.pDsa);
	if (pgpKeys.pElgamal)
		free(pgpKeys.pElgamal);
	*/
	
	
	Release();
	
	bool		bReturnValue	= false;
	EVP_PKEY *	pkey			= EVP_PKEY_new();
	
	OT_ASSERT(NULL != pkey);
	
	if (pgpKeys.pRsa)
	{
		if (EVP_PKEY_assign_RSA(pkey, pgpKeys.pRsa))
		{
			m_pKey			= pkey;
			bReturnValue	= true;
			OTLog::Output(4, "Successfully extracted RSA public key from PGP public key block.\n");
		}
		else
		{
			RSA_free(pgpKeys.pRsa);
			OTLog::Output(0, "Extracted RSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}

		pgpKeys.pRsa = NULL;
	}
	else if (pgpKeys.pDsa)
	{
		if (EVP_PKEY_assign_DSA(pkey, pgpKeys.pDsa))
		{
			m_pKey			= pkey;
			bReturnValue	= true;
			OTLog::Output(4, "Successfully extracted DSA public key from PGP public key block.\n");
		}
		else
		{
			DSA_free(pgpKeys.pDsa);
			OTLog::Output(0, "Extracted DSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}
		
		pgpKeys.pDsa = NULL;
	}
	else if (pgpKeys.pElgamal)
	{
		OTLog::Output(0, "Extracted ElGamal Key from PGP public key block, but currently do not support it (sorry))\n");
		//int EVP_PKEY_assign_EC_KEY(EVP_PKEY *pkey,EC_KEY *key); // Here is the assign function for El Gamal 
		// (assuming that "EC" stands for eliptical curve... kind of hard to tell with the OpenSSL docs...)
		free(pgpKeys.pElgamal); 
		pgpKeys.pElgamal = NULL;
		
		EVP_PKEY_free(pkey);
		pkey = NULL;
	}
	
	pkey = NULL; // This is either stored on m_pKey, or deleted. I'm setting pointer to NULL here just for completeness.
		
	return bReturnValue;
	//	EVP_cleanup(); // removes digests from the table
	//	ERR_free_strings(); // removes error strings.
}


// Decodes a public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
bool OTAsymmetricKey::SetPublicKey(const OTASCIIArmor & strKey)
{	
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;
	
	// This base64 decodes the string into binary object theData
	strKey.GetData(theData);
	
	BIO* keyBio	= BIO_new_mem_buf((void*)theData.GetPayloadPointer(), theData.GetSize());
	
	OT_ASSERT(NULL != keyBio);
	
	//TODO Figure out which one of these is right, if any
	//	pReturnKey	= d2i_PUBKEY_bio(keyBio, NULL); 
	pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); // we'll try this one next
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	keyBio = NULL;
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		OTLog::vOutput(4, "Success reading public key from ASCII-armored data:\n%s", strKey.Get());
		return true;
	}
	else {
		OTLog::vError("Failed reading public key from ASCII-armored data:\n%s", strKey.Get());
		return false;
	}
}


/*
bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
{	
	EVP_PKEY * pReturnKey = NULL;
	
	// create a memory buffer containing the ascii-armored Key data
	BIO* bmem = BIO_new_mem_buf((void *)strKey.Get(), strKey.GetLength());
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	//BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Reads from a BIO into a public key
	pReturnKey = PEM_read_bio_PUBKEY(bmem, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		OTLog::vOutput(4, "Success reading public key from ASCII-armored data:\n%s", strKey.Get());
		return true;
	}
	else {
		OTLog::vError("Failed reading public key from ASCII-armored data:\n%s", strKey.Get());
		return false;
	}
}
*/
/*
 
 bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
 {
 OTPayload theData;
 
 // This base64 decodes the string into binary object theData
 strKey.GetData(theData);
 
 // Next I ask OpenSSL to allocate a public key handle for me,
 // based on the binary key data that I show in memory.
 //	const unsigned char * pChar	= (const unsigned char*)theData.GetPayloadPointer();
 
 EVP_PKEY * pKey	= NULL;
 EVP_PKEY * pReturnKey = NULL;
 
 // create a memory buffer containing the (already decoded) binary Key data
 BIO* bmem = BIO_new_mem_buf(theData.GetPayloadPointer(), theData.GetSize());
 
 // Reads from a BIO into a public key
 pReturnKey = PEM_read_bio_PUBKEY(bmem, &pKey, OTAsymmetricKey::GetPasswordCallback(), NULL);
 
 // Free the BIO and related buffers, filters, etc.
 BIO_free_all(bmem);
 
 Release();
 
 if (NULL != pReturnKey)
 {
 m_pKey = pReturnKey;
		OTLog::vOutput(4,  "Success reading public key from ASCII-armored data.\n");
 return true;
 }
 else {
		OTLog::Error("Failed reading public key from ASCII-armored data.\n");
 return false;
 }
 }
 
 */

// Get the public key in ASCII-armored format
// i2d == EVP_PKEY* converted to normal binary in RAM
bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & strKey) const
{
	if (NULL == m_pKey)
		return false;
	
	bool bReturnVal = false;

	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());
	//BIO_puts(bmem, Get());

	OT_ASSERT(NULL != bmem);
	
	// write a public key to that buffer from our member variable m_pKey
	int nWriteBio = PEM_write_bio_PUBKEY(bmem, m_pKey);
	
	if (0 == nWriteBio)
	{
		OTLog::Error("Failed writing EVP_PKEY* to memory buffer in OTAsymmetricKey::GetPublicKey\n");
	}
	else 
	{
		OTLog::Output(5, "Success writing EVP_PKEY* to memory buffer in OTAsymmetricKey::GetPublicKey\n");
		
		OTPayload theData;
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the public key supposedly is,
		// and lSize will contain the size of that memory.
		long lSize = BIO_get_mem_data(bmem, &pChar);
		int  nSize = lSize;
		
		if (nSize > 0)
		{
			// Set the buffer size in our own memory.
			theData.SetPayloadSize(nSize);
			
			// copy it over from OpenSSL to our own memory
			memcpy((char*)theData.GetPayloadPointer(), pChar, nSize);
			
			// This base64 encodes the public key data
			strKey.SetData(theData);
			
		OTLog::Output(5, "Success copying public key into memory in OTAsymmetricKey::GetPublicKey\n");
			bReturnVal = true;
		}
		else 
		{
			OTLog::Error("Failed copying public key into memory in OTAsymmetricKey::GetPublicKey\n");
		}
	}

	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	bmem = NULL;
	
	return bReturnVal;	
}

/*
 bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & strKey)
 {
 if (NULL == m_pKey)
 return false;
 
 // I assume the 0 passed in here is what tells it to give us the length
 OTPayload theData;
 unsigned char *next;
 
 int nLength = i2d_PublicKey(m_pKey, 0);
 
 theData.SetPayloadSize(nLength);
 
 next = (unsigned char *) theData.GetPayloadPointer();
 
 i2d_PublicKey(m_pKey, &next); // If we use buf here, return buf; becomes wrong. So we use next.
 
 // This base64 encodes the public key data
 strKey.SetData(theData);
 
 return true;
 
 }
 */



/*
 BIO *infile;
 infile = BIO_new_file(strFilename.Get(), "r");
 
 if (!infile)
 //Error
 ;
 
 BIO_printf(infile, "Hello World\n");
 BIO_free(infile); 
 */

// Does public key only.
OTAsymmetricKey & OTAsymmetricKey::operator=(const OTAsymmetricKey & rhs)
{
	// Already done in SetPublicKey()
//	m_bIsPublicKey	= true;
//	m_bIsPrivateKey	= false;

	if (&rhs != this)
	{
		OTASCIIArmor ascTransfer;
		
		// Get the Issuer's public key in ASCII-armored format
		rhs.GetPublicKey(ascTransfer);
		
		// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
		this->SetPublicKey(ascTransfer);		
	}
	
	return *this;
}


// Does public key only.
OTAsymmetricKey::OTAsymmetricKey(const OTAsymmetricKey & rhs) : m_pKey(NULL), m_bIsPublicKey(true), m_bIsPrivateKey(false)
{
	if (&rhs != this)
	{
		OTASCIIArmor ascTransfer;
		
		// Get the Issuer's public key in ASCII-armored format
		rhs.GetPublicKey(ascTransfer);
		
		// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
		this->SetPublicKey(ascTransfer);
	}
}


OTAsymmetricKey::OTAsymmetricKey() : m_pKey(NULL), m_bIsPublicKey(false), m_bIsPrivateKey(false)
{

}

OTAsymmetricKey::~OTAsymmetricKey()
{
	Release();
}

void OTAsymmetricKey::Release()
{
	if (NULL != m_pKey)
	{
		EVP_PKEY_free (m_pKey); 
	}	
	m_pKey = NULL;
//	m_bIsPrivateKey = false;  // Every time this Releases, I don't want to lose what kind of key it was. (Once we know, we know.)
}



// Load the public key from a x509 stored in a bookended string
// If the string is escaped (- ----BEGIN is prefixed with dash space: "- ") then make
// sure to pass true.  (Keys that appear inside contracts are escaped after signing.)
// This function will remove the escapes.
bool OTAsymmetricKey::LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/)
{
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;
	
	bool bReturnValue = false;
	
	Release();

	// Read public key
	OTLog::Output(3,  "\nReading public key from x509 stored in bookended string...\n"); 

	OTString	strWithBookends;
	
	if (bEscaped)
	{
		OTASCIIArmor	theArmor;

		// I only have a CERTIFICATE 'if' here, not a PUBLIC KEY 'if'.
		// That's because this function is called "LoadPublicKeyFrom*CERT*String"
		// If you want to load a public key from a public key string, then call the
		// other function that does that.
		if (theArmor.LoadFromString((OTString &)strCert, true)) // passing bEscaped in as true explicitly here.
			strWithBookends.Format("-----BEGIN CERTIFICATE-----\n%s-----END CERTIFICATE-----\n", 
								   theArmor.Get());
		else 
		{
			OTLog::Error("Error extracting ASCII-Armored text from Cert String in "
					"OTAsymmetricKey::LoadPublicKeyFromCertString\n");
			return false;
		}
	}
	else {
		strWithBookends = strCert;
	}

	
	// toook out the +1 on the length since null terminater only
	// needed in string form, not binary form as OpenSSL treats it.
	BIO  * keyBio = BIO_new_mem_buf((void*)strWithBookends.Get(), strWithBookends.GetLength() /*+1*/); 
//	BIO  * keyBio = BIO_new_mem_buf((void*)strCert.Get(), strCert.GetLength() /*+1*/); 
	
	OT_ASSERT(NULL != keyBio);
	
	X509 * x509 = PEM_read_bio_X509(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL);
	
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	keyBio = NULL;

	
	// TODO: At some point need to switch to using X509_AUX functions.
	// The current x509 functions will read a trust certificate but discard the trust structure.
	// The X509_AUX functions will process the trust structure.
	if (NULL != x509) 
	{		
		m_pKey = X509_get_pubkey(x509); 
		
		X509_free(x509);
		x509 = NULL;

		if (m_pKey == NULL) 
		{ 
			OTLog::Error("Error reading public key from x509 in LoadPublicKeyFromCertArmor.\n"); 
		}
		else
		{
			OTLog::Output(3, "\nSuccessfully extracted a public key from an x509 certificate.\n"); 
			bReturnValue = true; 
		}
	}
	else
	{ 
		OTLog::Error("Error reading x509 out of certificate in LoadPublicKeyFromCertArmor.\n"); 
	}
		
	return bReturnValue;
}






// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(const OTString & strFoldername, const OTString & strFilename)
{
	// Already done in SetPublicKey()
//	m_bIsPublicKey	= true;
//	m_bIsPrivateKey	= false;

	Release();
	
	// This doesn't use assert on the arguments, but theArmor.LoadFromFile DOES.
	// -----------------------
	
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromFile(strFoldername, strFilename))
	{
		if (SetPublicKey(theArmor))
		{
			OTLog::Output(4, "Success setting public key from OTASCIIArmor in OTAsymmetricKey::LoadPublicKey.\n"); 
			return true; 			
		}
		else
		{
			OTLog::vError("Unable to convert from OTASCIIArmor to public key in "
					 "OTAsymmetricKey::LoadPublicKey: %s\n",
					 strFilename.Get()); 
			return false; 			
		}
	}
	else 
	{
		OTLog::vError("Unable to read pubkey file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}

	return false;
}

/*
// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(OTString & strFilename)
{
	Release();
	
	FILE * fp; 
	
	// Read public key 
	fp = fopen (strFilename.Get(), "r"); 
	
	if (NULL == fp)
	{ 
		fprintf (stderr, "Error opening public key file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	} 
	
    m_pKey = PEM_read_PUBKEY(fp, &m_pKey, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	
	fclose (fp); 
	
	if (NULL == m_pKey) 
	{ 
		fprintf (stderr, "Error reading public key from file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}
	
	return true;
}
*/




// Load the public key from a x509 stored in a .pem file
bool OTAsymmetricKey::LoadPublicKeyFromCertFile(const OTString & strFoldername, const OTString & strFilename)
{
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	Release();
	
	// ---------------

	X509 *	x509	= NULL; 

	const char * szFoldername = strFoldername.Get();
	const char * szFilename = strFilename.Get();
	
	OT_ASSERT(strFoldername.Exists());
	OT_ASSERT(strFilename.Exists());

	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTAsymmetricKey::LoadPublicKeyFromCertFile: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTAsymmetricKey::LoadPublicKeyFromCertFile: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); 

//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());
	
	// --------------------------------------------------------------------
	
//	if (nPutsResult > 0)
	{
		x509 = PEM_read_bio_X509(bio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
		
		BIO_free_all(bio);
		bio = NULL;
		// -------------------------------------------------
		
		if (x509 == NULL) 
		{ 
			OTLog::vError("Error reading x509 out of cert file: %s%s%s\n", 
						  szFoldername, OTLog::PathSeparator(), szFilename);
			return false; 
		}
		
		m_pKey = X509_get_pubkey(x509); 
		X509_free(x509);  
		x509 = NULL;
		
		if (m_pKey == NULL) 
		{ 
			OTLog::vError("Error reading public key from x509 from certfile: %s%s%s\n", 
						  szFoldername, OTLog::PathSeparator(), szFilename); 
			return false; 
		}
		else
		{
			OTLog::vOutput(3, "Successfully loaded public key from x509 from certfile: %s%s%s\n", 
						   szFoldername, OTLog::PathSeparator(), szFilename);
			return true; 
		}
	}
	
	if (NULL != bio)
		BIO_free_all(bio);

	return false;
}




// Load the private key from a .pem file
bool OTAsymmetricKey::LoadPrivateKey(const OTString & strFoldername, const OTString & strFilename)
{
	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;

	Release();
	
	const char * szFoldername = strFoldername.Get();
	const char * szFilename = strFilename.Get();
	
	OT_ASSERT(strFoldername.Exists());
	OT_ASSERT(strFilename.Exists());
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vOutput(0, "OTAsymmetricKey::LoadPrivateKey: Unable to find private key file: %s%s%s\n", 
					   szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTAsymmetricKey::LoadPrivateKey: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); 
//	BIO * bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());
	
	// --------------------------------------------------------------------
	
//	if (nPutsResult > 0)
	{
		// TODO security:
		/* The old PrivateKey write routines are retained for compatibility. 
		 New applications should write private keys using the PEM_write_bio_PKCS8PrivateKey() or PEM_write_PKCS8PrivateKey() 
		 routines because they are more secure (they use an iteration count of 2048 whereas the traditional routines use a
		 count of 1) unless compatibility with older versions of OpenSSL is important.
		 NOTE: The PrivateKey read routines can be used in all applications because they handle all formats transparently.
		 */		
		m_pKey = PEM_read_bio_PrivateKey( bio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL );
		
		BIO_free_all(bio);
		bio = NULL;
		// ------------------------------------------------------
		
		if (NULL == m_pKey) 
		{ 
			OTLog::vError("OTAsymmetricKey::LoadPrivateKey: Error reading private key from bio: %s%s%s. Contents:\n\n%s\n\n", 
						  szFoldername, OTLog::PathSeparator(), szFilename, strFileContents.c_str());
			return false; 
		}
		else 
		{
			OTLog::vOutput(3, "Successfully loaded private key: %s%s%s\n", 
						   szFoldername, OTLog::PathSeparator(), szFilename);
			return true;
		}
	}
	
	if (NULL != bio)
		BIO_free_all(bio);
	
	OTLog::vError("OTAsymmetricKey::LoadPrivateKey: STRANGE error while loading private key: %s\n", strFilename.Get());
	return false;
}


const EVP_PKEY * OTAsymmetricKey::GetKey() const
{
	return m_pKey;
}


















