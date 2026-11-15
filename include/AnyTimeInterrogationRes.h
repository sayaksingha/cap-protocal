#ifndef PHASE3_ANYTIMEINTERROGATIONRES
#define PHASE3_ANYTIMEINTERROGATIONRES
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_AnyTimeInterrogationRes
{
	AnyTimeInterrogationRes_SUBSCRIBERINFO	=  1 << 0,
	AnyTimeInterrogationRes_EXTENSIONCONTAINER	=  1 << 1,
	AnyTimeInterrogationRes_TAG_NULL	=  0x0000
}AnyTimeInterrogationRes_tags;

		//! Class Definition
		/*!		ClassName is AnyTimeInterrogationRes
		*/
class AnyTimeInterrogationRes:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		SubscriberInfo*		msubscriberInfo;

		capstd::GENERIC*		mextensionContainer;


	public:
		AnyTimeInterrogationRes();

		~AnyTimeInterrogationRes();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set SubscriberInfo type of argument subscriberInfo for datatype AnyTimeInterrogationRes
		*/
		bool setsubscriberInfo(SubscriberInfo* subscriberInfo);

		//! Function to set values
		/*!		Function to set SubscriberInfo type of argument subscriberInfo for datatype AnyTimeInterrogationRes
		*/
		SubscriberInfo* setsubscriberInfo();

		//! Function to get values
		/*!		Function to set SubscriberInfo type of argument subscriberInfo for datatype AnyTimeInterrogationRes
		Throws exception of which type and Summary of Exception
		*/
		SubscriberInfo* getsubscriberInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationRes
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationRes
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype AnyTimeInterrogationRes
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AnyTimeInterrogationRes
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AnyTimeInterrogationRes
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AnyTimeInterrogationRes
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AnyTimeInterrogationRes
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
