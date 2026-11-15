//  @(#) $Id: SplitLegArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef SPLITLEGARG
#define SPLITLEGARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_SplitLegArg
{
	SplitLegArg_LEGTOBESPLIT	=  1 << 0,
	SplitLegArg_NEWCALLSEGMENT	=  1 << 1,
	SplitLegArg_EXTENSIONS	=  1 << 2,
	SplitLegArg_TAG_NULL	=  0x0000
}SplitLegArg_tags;

		//! Class Definition
		/*!		ClassName is SplitLegArg
		*/
class SplitLegArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		LegID*		mlegToBeSplit;

		capstd::capstd::INTEGER*		mnewCallSegment;

		Extensions*		mextensions;


	public:
		SplitLegArg();

		~SplitLegArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set LegID type of argument legToBeSplit for datatype SplitLegArg
		*/
		bool setlegToBeSplit(LegID* legToBeSplit);

		//! Function to set values
		/*!		Function to set LegID type of argument legToBeSplit for datatype SplitLegArg
		*/
		LegID* setlegToBeSplit();

		//! Function to get values
		/*!		Function to set LegID type of argument legToBeSplit for datatype SplitLegArg
		Throws exception of which type and Summary of Exception
		*/
		LegID* getlegToBeSplit() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument newCallSegment for datatype SplitLegArg
		*/
		bool setnewCallSegment(capstd::capstd::INTEGER* newCallSegment);

		//! Function to set values
		/*!		Function to set INTEGER type of argument newCallSegment for datatype SplitLegArg
		*/
		capstd::capstd::INTEGER* setnewCallSegment();

		//! Function to get values
		/*!		Function to set INTEGER type of argument newCallSegment for datatype SplitLegArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::INTEGER* getnewCallSegment() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype SplitLegArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype SplitLegArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype SplitLegArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype SplitLegArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SplitLegArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SplitLegArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SplitLegArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
