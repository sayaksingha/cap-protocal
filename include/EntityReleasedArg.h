//  @(#) $Id: EntityReleasedArg.h,v 1.1.2.3 2019/06/29 02:24:29 mrafi Exp $";

#ifndef ENTITYRELEASEDARG
#define ENTITYRELEASEDARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_EntityReleasedArg
{
	EntityReleasedArg_CALLSEGMENTFAILURE	=  1 << 0,
	EntityReleasedArg_BCSM_FAILURE	=  1 << 1,
	EntityReleasedArg_TAG_NULL	=  0x0000
}EntityReleasedArg_tags;

		//! Class Definition
		/*!		ClassName is EntityReleasedArg
		*/
class EntityReleasedArg:public capstd::CapEncDecLib
{
	private:

		bool mParamSet;

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CallSegmentFailure*		mcallSegmentFailure;

		BCSM_Failure*		mbCSM_Failure;


	public:
		EntityReleasedArg();

		~EntityReleasedArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CallSegmentFailure type of argument callSegmentFailure for datatype EntityReleasedArg
		*/
		bool setcallSegmentFailure(CallSegmentFailure* callSegmentFailure);

		//! Function to set values
		/*!		Function to set CallSegmentFailure type of argument callSegmentFailure for datatype EntityReleasedArg
		*/
		CallSegmentFailure* setcallSegmentFailure();

		//! Function to get values
		/*!		Function to set CallSegmentFailure type of argument callSegmentFailure for datatype EntityReleasedArg
		Throws exception of which type and Summary of Exception
		*/
		CallSegmentFailure* getcallSegmentFailure() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set BCSM_Failure type of argument bCSM_Failure for datatype EntityReleasedArg
		*/
		bool setbCSM_Failure(BCSM_Failure* bCSM_Failure);

		//! Function to set values
		/*!		Function to set BCSM_Failure type of argument bCSM_Failure for datatype EntityReleasedArg
		*/
		BCSM_Failure* setbCSM_Failure();

		//! Function to get values
		/*!		Function to set BCSM_Failure type of argument bCSM_Failure for datatype EntityReleasedArg
		Throws exception of which type and Summary of Exception
		*/
		BCSM_Failure* getbCSM_Failure() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype EntityReleasedArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype EntityReleasedArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype EntityReleasedArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags EntityReleasedArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
