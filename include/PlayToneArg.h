//  @(#) $Id: PlayToneArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef PLAYTONEARG
#define PLAYTONEARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_PlayToneArg
{
	PlayToneArg_LEGORCALLSEGMENT	=  1 << 0,
	PlayToneArg_BURSTS	=  1 << 1,
	PlayToneArg_EXTENSIONS	=  1 << 2,
	PlayToneArg_TAG_NULL	=  0x0000
}PlayToneArg_tags;

		//! Class Definition
		/*!		ClassName is PlayToneArg
		*/
class PlayToneArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		LegOrCallSegment*		mlegOrCallSegment;

		Burst*		mbursts;

		Extensions*		mextensions;


	public:
		PlayToneArg();

		~PlayToneArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set LegOrCallSegment type of argument legOrCallSegment for datatype PlayToneArg
		*/
		bool setlegOrCallSegment(LegOrCallSegment* legOrCallSegment);

		//! Function to set values
		/*!		Function to set LegOrCallSegment type of argument legOrCallSegment for datatype PlayToneArg
		*/
		LegOrCallSegment* setlegOrCallSegment();

		//! Function to get values
		/*!		Function to set LegOrCallSegment type of argument legOrCallSegment for datatype PlayToneArg
		Throws exception of which type and Summary of Exception
		*/
		LegOrCallSegment* getlegOrCallSegment() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Burst type of argument bursts for datatype PlayToneArg
		*/
		bool setbursts(Burst* bursts);

		//! Function to set values
		/*!		Function to set Burst type of argument bursts for datatype PlayToneArg
		*/
		Burst* setbursts();

		//! Function to get values
		/*!		Function to set Burst type of argument bursts for datatype PlayToneArg
		Throws exception of which type and Summary of Exception
		*/
		Burst* getbursts() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype PlayToneArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype PlayToneArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype PlayToneArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype PlayToneArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype PlayToneArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PlayToneArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags PlayToneArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
