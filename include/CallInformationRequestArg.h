#ifndef PHASE3_CALLINFORMATIONREQUESTARG
#define PHASE3_CALLINFORMATIONREQUESTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_CallInformationRequestArg
{
	CallInformationRequestArg_REQUESTEDINFORMATIONTYPELIST	=  1 << 0,
	CallInformationRequestArg_EXTENSIONS	=  1 << 1,
	CallInformationRequestArg_LEGID	=  1 << 2,
	CallInformationRequestArg_TAG_NULL	=  0x0000
}CallInformationRequestArg_tags;

		//! Class Definition
		/*!		ClassName is CallInformationRequestArg
		*/
class CallInformationRequestArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		RequestedInformationTypeList*		mrequestedInformationTypeList;

		Extensions*		mextensions;

		SendingSideID*		mlegID;


	public:
		CallInformationRequestArg();

		~CallInformationRequestArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set RequestedInformationTypeList type of argument requestedInformationTypeList for datatype CallInformationRequestArg
		*/
		bool setrequestedInformationTypeList(RequestedInformationTypeList* requestedInformationTypeList);

		//! Function to set values
		/*!		Function to set RequestedInformationTypeList type of argument requestedInformationTypeList for datatype CallInformationRequestArg
		*/
		RequestedInformationTypeList* setrequestedInformationTypeList();

		//! Function to get values
		/*!		Function to set RequestedInformationTypeList type of argument requestedInformationTypeList for datatype CallInformationRequestArg
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationTypeList* getrequestedInformationTypeList() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationRequestArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationRequestArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationRequestArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SendingSideID type of argument legID for datatype CallInformationRequestArg
		*/
		bool setlegID(SendingSideID* legID);

		//! Function to set values
		/*!		Function to set SendingSideID type of argument legID for datatype CallInformationRequestArg
		*/
		SendingSideID* setlegID();

		//! Function to get values
		/*!		Function to set SendingSideID type of argument legID for datatype CallInformationRequestArg
		Throws exception of which type and Summary of Exception
		*/
		SendingSideID* getlegID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CallInformationRequestArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CallInformationRequestArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CallInformationRequestArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CallInformationRequestArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
