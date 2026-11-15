//  @(#) $Id: CollectInformationArg.h,v 1.1.2.3 2019/06/29 02:24:29 mrafi Exp $";

#ifndef COLLECTINFORMATIONARG
#define COLLECTINFORMATIONARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_CollectInformationArg
{
	CollectInformationArg_EXTENSIONS	=  1 << 0,
	CollectInformationArg_TAG_NULL	=  0x0000
}CollectInformationArg_tags;

		//! Class Definition
		/*!		ClassName is CollectInformationArg
		*/
class CollectInformationArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		Extensions*		mextensions;


	public:
		CollectInformationArg();

		~CollectInformationArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CollectInformationArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype CollectInformationArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype CollectInformationArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CollectInformationArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CollectInformationArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CollectInformationArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CollectInformationArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
