#ifndef PHASE3_ANYTIMEINTERROGATIONARG
#define PHASE3_ANYTIMEINTERROGATIONARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_AnyTimeInterrogationArg
{
	AnyTimeInterrogationArg_SUBSCRIBERIDENTITY	=  1 << 0,
	AnyTimeInterrogationArg_REQUESTEDINFO	=  1 << 1,
	AnyTimeInterrogationArg_EXTENSIONCONTAINER	=  1 << 2,
	AnyTimeInterrogationArg_GSMSCF_ADDRESS	=  1 << 3,
	AnyTimeInterrogationArg_TAG_NULL	=  0x0000
}AnyTimeInterrogationArg_tags;

		//! Class Definition
		/*!		ClassName is AnyTimeInterrogationArg
		*/
class AnyTimeInterrogationArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		SubscriberIdentity*		msubscriberIdentity;

		RequestedInfo*		mrequestedInfo;

		capstd::GENERIC*		mextensionContainer;

		capstd::OctetString*		mgsmSCF_Address;


	public:
		AnyTimeInterrogationArg();

		~AnyTimeInterrogationArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set SubscriberIdentity type of argument subscriberIdentity for datatype AnyTimeInterrogationArg
		*/
		bool setsubscriberIdentity(SubscriberIdentity* subscriberIdentity);

		//! Function to set values
		/*!		Function to set SubscriberIdentity type of argument subscriberIdentity for datatype AnyTimeInterrogationArg
		*/
		SubscriberIdentity* setsubscriberIdentity();

		//! Function to get values
		/*!		Function to set SubscriberIdentity type of argument subscriberIdentity for datatype AnyTimeInterrogationArg
		Throws exception of which type and Summary of Exception
		*/
		SubscriberIdentity* getsubscriberIdentity() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set RequestedInfo type of argument requestedInfo for datatype AnyTimeInterrogationArg
		*/
		bool setrequestedInfo(RequestedInfo* requestedInfo);

		//! Function to set values
		/*!		Function to set RequestedInfo type of argument requestedInfo for datatype AnyTimeInterrogationArg
		*/
		RequestedInfo* setrequestedInfo();

		//! Function to get values
		/*!		Function to set RequestedInfo type of argument requestedInfo for datatype AnyTimeInterrogationArg
		Throws exception of which type and Summary of Exception
		*/
		RequestedInfo* getrequestedInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationArg
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationArg
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument gsmSCF_Address for datatype AnyTimeInterrogationArg
		*/
		bool setgsmSCF_Address(capstd::OctetString* gsmSCF_Address);

		//! Function to set values
		/*!		Function to set OctetString type of argument gsmSCF_Address for datatype AnyTimeInterrogationArg
		*/
		capstd::OctetString* setgsmSCF_Address();

		//! Function to get values
		/*!		Function to set OctetString type of argument gsmSCF_Address for datatype AnyTimeInterrogationArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgsmSCF_Address() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AnyTimeInterrogationArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AnyTimeInterrogationArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AnyTimeInterrogationArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AnyTimeInterrogationArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
