#ifndef PHASE3_ASSISTREQUESTINSTRUCTIONSARG
#define PHASE3_ASSISTREQUESTINSTRUCTIONSARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_AssistRequestInstructionsArg
{
	AssistRequestInstructionsArg_CORRELATIONID	=  1 << 0,
	AssistRequestInstructionsArg_IPSSPCAPABILITIES	=  1 << 1,
	AssistRequestInstructionsArg_EXTENSIONS	=  1 << 2,
	AssistRequestInstructionsArg_TAG_NULL	=  0x0000
}AssistRequestInstructionsArg_tags;

		//! Class Definition
		/*!		ClassName is AssistRequestInstructionsArg
		*/
class AssistRequestInstructionsArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mcorrelationID;

		capstd::OctetString*		miPSSPCapabilities;

		Extensions*		mextensions;


	public:
		AssistRequestInstructionsArg();

		~AssistRequestInstructionsArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument correlationID for datatype AssistRequestInstructionsArg
		*/
		bool setcorrelationID(capstd::OctetString* correlationID);

		//! Function to set values
		/*!		Function to set OctetString type of argument correlationID for datatype AssistRequestInstructionsArg
		*/
		capstd::OctetString* setcorrelationID();

		//! Function to get values
		/*!		Function to set OctetString type of argument correlationID for datatype AssistRequestInstructionsArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcorrelationID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype AssistRequestInstructionsArg
		*/
		bool setiPSSPCapabilities(capstd::OctetString* iPSSPCapabilities);

		//! Function to set values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype AssistRequestInstructionsArg
		*/
		capstd::OctetString* setiPSSPCapabilities();

		//! Function to get values
		/*!		Function to set OctetString type of argument iPSSPCapabilities for datatype AssistRequestInstructionsArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getiPSSPCapabilities() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype AssistRequestInstructionsArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype AssistRequestInstructionsArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype AssistRequestInstructionsArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AssistRequestInstructionsArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AssistRequestInstructionsArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AssistRequestInstructionsArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AssistRequestInstructionsArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
