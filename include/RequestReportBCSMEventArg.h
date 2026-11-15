#ifndef PHASE3_REQUESTREPORTBCSMEVENTARG
#define PHASE3_REQUESTREPORTBCSMEVENTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_RequestReportBCSMEventArg
{
	RequestReportBCSMEventArg_BCSMEVENTS	=  1 << 0,
	RequestReportBCSMEventArg_EXTENSIONS	=  1 << 1,
	RequestReportBCSMEventArg_TAG_NULL	=  0x0000
}RequestReportBCSMEventArg_tags;

		//! Class Definition
		/*!		ClassName is RequestReportBCSMEventArg
		*/
class RequestReportBCSMEventArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bcsmEvents*		mbcsmEvents;

		Extensions*		mextensions;


	public:
		RequestReportBCSMEventArg();

		~RequestReportBCSMEventArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set bcsmEvents type of argument bcsmEvents for datatype RequestReportBCSMEventArg
		*/
		bool setbcsmEvents(bcsmEvents* bcsmEvents);

		//! Function to set values
		/*!		Function to set bcsmEvents type of argument bcsmEvents for datatype RequestReportBCSMEventArg
		*/
		bcsmEvents* setbcsmEvents();

		//! Function to get values
		/*!		Function to set bcsmEvents type of argument bcsmEvents for datatype RequestReportBCSMEventArg
		Throws exception of which type and Summary of Exception
		*/
		bcsmEvents* getbcsmEvents() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportBCSMEventArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportBCSMEventArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype RequestReportBCSMEventArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype RequestReportBCSMEventArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RequestReportBCSMEventArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RequestReportBCSMEventArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RequestReportBCSMEventArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
