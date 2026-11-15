#ifndef PHASE3_CANCELARG
#define PHASE3_CANCELARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_CancelArg
{
	CancelArg_INVOKEID	=  1 << 0,
	CancelArg_ALLREQUESTS	=  1 << 1,
	CancelArg_TAG_NULL	=  0x0000
}CancelArg_tags;

		//! Class Definition
		/*!		ClassName is CancelArg
		*/
class CancelArg:public capstd::CapEncDecLib
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		minvokeID;

		bool 		mallRequests;

		bool 		mNullallRequests;


	public:
		CancelArg();

		~CancelArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument invokeID for datatype CancelArg
		*/
		bool setinvokeID(capstd::INTEGER* invokeID);

		//! Function to set values
		/*!		Function to set INTEGER type of argument invokeID for datatype CancelArg
		*/
		capstd::INTEGER* setinvokeID();

		//! Function to get values
		/*!		Function to set INTEGER type of argument invokeID for datatype CancelArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getinvokeID() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument allRequests for datatype CancelArg
		*/
		bool setallRequests(bool allRequests);

		//! Function to set new values
		/*!		Function to set NULL type of argument allRequests for datatype CancelArg
		*/
		bool* setallRequests();

		//! Function to get values
		/*!		Function to get NULL type of argument allRequests for datatype CancelArg
		Throws exception of which type and Summary of Exception
		*/
		bool getallRequests();

		//! Function to Decode
		/*!		Function to Decode datatype CancelArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CancelArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CancelArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CancelArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
