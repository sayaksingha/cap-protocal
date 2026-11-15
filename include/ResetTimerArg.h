#ifndef PHASE3_RESETTIMERARG
#define PHASE3_RESETTIMERARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ResetTimerArg
{
	ResetTimerArg_TIMERID	=  1 << 0,
	ResetTimerArg_TIMERVALUE	=  1 << 1,
	ResetTimerArg_EXTENSIONS	=  1 << 2,
	ResetTimerArg_TAG_NULL	=  0x0000
}ResetTimerArg_tags;

		//! Class Definition
		/*!		ClassName is ResetTimerArg
		*/
class ResetTimerArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		TimerID* timerIDDefault;
		TimerID*		mtimerID;

		capstd::INTEGER*		mtimervalue;

		Extensions*		mextensions;


	public:
		ResetTimerArg();

		~ResetTimerArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerArg
		*/
		bool settimerID(TimerID* timerID);

		//! Function to set values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerArg
		*/
		TimerID* settimerID();

		//! Function to get values
		/*!		Function to set TimerID type of argument timerID for datatype ResetTimerArg
		Throws exception of which type and Summary of Exception
		*/
		TimerID* gettimerID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerArg
		*/
		bool settimervalue(capstd::INTEGER* timervalue);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerArg
		*/
		capstd::INTEGER* settimervalue();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timervalue for datatype ResetTimerArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimervalue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ResetTimerArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ResetTimerArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ResetTimerArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ResetTimerArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ResetTimerArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
