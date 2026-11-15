#ifndef PHASE3_CALLGAPARG
#define PHASE3_CALLGAPARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_CallGapArg
{
	CallGapArg_GAPCRITERIA	=  1 << 0,
	CallGapArg_GAPINDICATORS	=  1 << 1,
	CallGapArg_CONTROLTYPE	=  1 << 2,
	CallGapArg_GAPTREATMENT	=  1 << 3,
	CallGapArg_EXTENSIONS	=  1 << 4,
	CallGapArg_TAG_NULL	=  0x0000
}CallGapArg_tags;

		//! Class Definition
		/*!		ClassName is CallGapArg
		*/
class CallGapArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		GapCriteria*		mgapCriteria;

		GapIndicators*		mgapIndicators;

		ControlType*		mcontrolType;

		GapTreatment*		mgapTreatment;

		Extensions*		mextensions;


	public:
		CallGapArg();

		~CallGapArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GapCriteria type of argument gapCriteria for datatype CallGapArg
		*/
		bool setgapCriteria(GapCriteria* gapCriteria);

		//! Function to set values
		/*!		Function to set GapCriteria type of argument gapCriteria for datatype CallGapArg
		*/
		GapCriteria* setgapCriteria();

		//! Function to get values
		/*!		Function to set GapCriteria type of argument gapCriteria for datatype CallGapArg
		Throws exception of which type and Summary of Exception
		*/
		GapCriteria* getgapCriteria() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GapIndicators type of argument gapIndicators for datatype CallGapArg
		*/
		bool setgapIndicators(GapIndicators* gapIndicators);

		//! Function to set values
		/*!		Function to set GapIndicators type of argument gapIndicators for datatype CallGapArg
		*/
		GapIndicators* setgapIndicators();

		//! Function to get values
		/*!		Function to set GapIndicators type of argument gapIndicators for datatype CallGapArg
		Throws exception of which type and Summary of Exception
		*/
		GapIndicators* getgapIndicators() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ControlType type of argument controlType for datatype CallGapArg
		*/
		bool setcontrolType(ControlType* controlType);

		//! Function to set values
		/*!		Function to set ControlType type of argument controlType for datatype CallGapArg
		*/
		ControlType* setcontrolType();

		//! Function to get values
		/*!		Function to set ControlType type of argument controlType for datatype CallGapArg
		Throws exception of which type and Summary of Exception
		*/
		ControlType* getcontrolType() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GapTreatment type of argument gapTreatment for datatype CallGapArg
		*/
		bool setgapTreatment(GapTreatment* gapTreatment);

		//! Function to set values
		/*!		Function to set GapTreatment type of argument gapTreatment for datatype CallGapArg
		*/
		GapTreatment* setgapTreatment();

		//! Function to get values
		/*!		Function to set GapTreatment type of argument gapTreatment for datatype CallGapArg
		Throws exception of which type and Summary of Exception
		*/
		GapTreatment* getgapTreatment() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallGapArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CallGapArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype CallGapArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CallGapArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CallGapArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CallGapArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CallGapArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
