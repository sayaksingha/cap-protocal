#ifndef PHASE3_RELEASECALLARG
#define PHASE3_RELEASECALLARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ReleaseCallArg
{
	ReleaseCallArg_CAUSE	=  1 << 0,
	ReleaseCallArg_TAG_NULL	=  0x0000
}ReleaseCallArg_tags;

		//! Class Definition
		/*!		ClassName is ReleaseCallArg
		*/
class ReleaseCallArg:public capstd::CapEncDecLib
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mcause;


	public:
		ReleaseCallArg();

		~ReleaseCallArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument cause for datatype ReleaseCallArg
		*/
		bool setcause(capstd::GENERIC* cause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument cause for datatype ReleaseCallArg
		*/
		capstd::GENERIC* setcause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument cause for datatype ReleaseCallArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getcause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ReleaseCallArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ReleaseCallArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReleaseCallArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ReleaseCallArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
