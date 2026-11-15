//  @(#) $Id: MoveLegArg.h,v 1.1.2.3 2019/06/29 02:24:30 mrafi Exp $";

#ifndef MOVELEGARG
#define MOVELEGARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_MoveLegArg
{
	MoveLegArg_LEGIDTOMOVE	=  1 << 0,
	MoveLegArg_EXTENSIONS	=  1 << 1,
	MoveLegArg_TAG_NULL	=  0x0000
}MoveLegArg_tags;

		//! Class Definition
		/*!		ClassName is MoveLegArg
		*/
class MoveLegArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		LegID*		mlegIDToMove;

		Extensions*		mextensions;


	public:
		MoveLegArg();

		~MoveLegArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set LegID type of argument legIDToMove for datatype MoveLegArg
		*/
		bool setlegIDToMove(LegID* legIDToMove);

		//! Function to set values
		/*!		Function to set LegID type of argument legIDToMove for datatype MoveLegArg
		*/
		LegID* setlegIDToMove();

		//! Function to get values
		/*!		Function to set LegID type of argument legIDToMove for datatype MoveLegArg
		Throws exception of which type and Summary of Exception
		*/
		LegID* getlegIDToMove() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype MoveLegArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype MoveLegArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype MoveLegArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype MoveLegArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype MoveLegArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MoveLegArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags MoveLegArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
