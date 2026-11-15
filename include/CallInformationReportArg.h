#ifndef PHASE3_CALLINFORMATIONREPORTARG
#define PHASE3_CALLINFORMATIONREPORTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_CallInformationReportArg
{
	CallInformationReportArg_REQUESTEDINFORMATIONLIST	=  1 << 0,
	CallInformationReportArg_EXTENSIONS	=  1 << 1,
	CallInformationReportArg_LEGID	=  1 << 2,
	CallInformationReportArg_TAG_NULL	=  0x0000
}CallInformationReportArg_tags;

		//! Class Definition
		/*!		ClassName is CallInformationReportArg
		*/
class CallInformationReportArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		RequestedInformationList*		mrequestedInformationList;

		Extensions*		mextensions;

		ReceivingSideID*		mlegID;


	public:
		CallInformationReportArg();

		~CallInformationReportArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set RequestedInformationList type of argument requestedInformationList for datatype CallInformationReportArg
		*/
		bool setrequestedInformationList(RequestedInformationList* requestedInformationList);

		//! Function to set values
		/*!		Function to set RequestedInformationList type of argument requestedInformationList for datatype CallInformationReportArg
		*/
		RequestedInformationList* setrequestedInformationList();

		//! Function to get values
		/*!		Function to set RequestedInformationList type of argument requestedInformationList for datatype CallInformationReportArg
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationList* getrequestedInformationList() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationReportArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationReportArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype CallInformationReportArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ReceivingSideID type of argument legID for datatype CallInformationReportArg
		*/
		bool setlegID(ReceivingSideID* legID);

		//! Function to set values
		/*!		Function to set ReceivingSideID type of argument legID for datatype CallInformationReportArg
		*/
		ReceivingSideID* setlegID();

		//! Function to get values
		/*!		Function to set ReceivingSideID type of argument legID for datatype CallInformationReportArg
		Throws exception of which type and Summary of Exception
		*/
		ReceivingSideID* getlegID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CallInformationReportArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CallInformationReportArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CallInformationReportArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CallInformationReportArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
