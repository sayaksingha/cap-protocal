#ifndef CONNECTSMSARG
#define CONNECTSMSARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ConnectSMSArg
{
	ConnectSMSArg_CALLINGPARTYSNUMBER	=  1 << 0,
	ConnectSMSArg_DESTINATIONSUBSCRIBERNUMBER	=  1 << 1,
	ConnectSMSArg_SMSCADDRESS	=  1 << 2,
	ConnectSMSArg_EXTENSIONS	=  1 << 3,
	ConnectSMSArg_TAG_NULL	=  0x0000
}ConnectSMSArg_tags;

		//! Class Definition
		/*!		ClassName is ConnectSMSArg
		*/
class ConnectSMSArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		ISDN_AddressString*		mcallingPartysNumber;

		capstd::capstd::OctetString*		mdestinationSubscriberNumber;

		ISDN_AddressString*		msMSCAddress;

		Extensions*		mextensions;


	public:
		ConnectSMSArg();

		~ConnectSMSArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set ISDN_AddressString type of argument callingPartysNumber for datatype ConnectSMSArg
		*/
		bool setcallingPartysNumber(ISDN_AddressString* callingPartysNumber);

		//! Function to set values
		/*!		Function to set ISDN_AddressString type of argument callingPartysNumber for datatype ConnectSMSArg
		*/
		ISDN_AddressString* setcallingPartysNumber();

		//! Function to get values
		/*!		Function to set ISDN_AddressString type of argument callingPartysNumber for datatype ConnectSMSArg
		Throws exception of which type and Summary of Exception
		*/
		ISDN_AddressString* getcallingPartysNumber() ;

		//!Function to set values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype ConnectSMSArg
		*/
		bool setdestinationSubscriberNumber(capstd::capstd::OctetString* destinationSubscriberNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype ConnectSMSArg
		*/
		capstd::capstd::OctetString* setdestinationSubscriberNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument destinationSubscriberNumber for datatype ConnectSMSArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getdestinationSubscriberNumber() ;

		//!Function to set values
		/*!		Function to set ISDN_AddressString type of argument sMSCAddress for datatype ConnectSMSArg
		*/
		bool setsMSCAddress(ISDN_AddressString* sMSCAddress);

		//! Function to set values
		/*!		Function to set ISDN_AddressString type of argument sMSCAddress for datatype ConnectSMSArg
		*/
		ISDN_AddressString* setsMSCAddress();

		//! Function to get values
		/*!		Function to set ISDN_AddressString type of argument sMSCAddress for datatype ConnectSMSArg
		Throws exception of which type and Summary of Exception
		*/
		ISDN_AddressString* getsMSCAddress() ;

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectSMSArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectSMSArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectSMSArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;

		//! Function to Decode
		/*!		Function to Decode datatype ConnectSMSArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ConnectSMSArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ConnectSMSArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ConnectSMSArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
