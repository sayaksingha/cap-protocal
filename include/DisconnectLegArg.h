//  @(#) $Id: DisconnectLegArg.h,v 1.1.2.3 2019/06/29 02:24:29 mrafi Exp $";

#ifndef DISCONNECTLEGARG
#define DISCONNECTLEGARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_DisconnectLegArg
{
	DisconnectLegArg_LEGTOBERELEASED	=  1 << 0,
	DisconnectLegArg_RELEASECAUSE	=  1 << 1,
	DisconnectLegArg_EXTENSIONS	=  1 << 2,
	DisconnectLegArg_TAG_NULL	=  0x0000
}DisconnectLegArg_tags;

		//! Class Definition
		/*!		ClassName is DisconnectLegArg
		*/
class DisconnectLegArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		LegID*		mlegToBeReleased;

		capstd::capstd::OctetString*		mreleaseCause;

		Extensions*		mextensions;


	public:
		DisconnectLegArg();

		~DisconnectLegArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set LegID type of argument legToBeReleased for datatype DisconnectLegArg
		*/
		bool setlegToBeReleased(LegID* legToBeReleased);

		//! Function to set values
		/*!		Function to set LegID type of argument legToBeReleased for datatype DisconnectLegArg
		*/
		LegID* setlegToBeReleased();

		//! Function to get values
		/*!		Function to set LegID type of argument legToBeReleased for datatype DisconnectLegArg
		Throws exception of which type and Summary of Exception
		*/
		LegID* getlegToBeReleased() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument releaseCause for datatype DisconnectLegArg
		*/
		bool setreleaseCause(capstd::capstd::OctetString* releaseCause);

		//! Function to set values
		/*!		Function to set OctetString type of argument releaseCause for datatype DisconnectLegArg
		*/
		capstd::capstd::OctetString* setreleaseCause();

		//! Function to get values
		/*!		Function to set OctetString type of argument releaseCause for datatype DisconnectLegArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::OctetString* getreleaseCause() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectLegArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectLegArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectLegArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype DisconnectLegArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype DisconnectLegArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DisconnectLegArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags DisconnectLegArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
