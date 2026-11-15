#ifndef PHASE3_CONNECTTORESOURCEARG
#define PHASE3_CONNECTTORESOURCEARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_ConnectToResourceArg
{
	ConnectToResourceArg_RESOURCEADDRESS	=  1 << 0,
	ConnectToResourceArg_EXTENSIONS	=  1 << 1,
	ConnectToResourceArg_SERVICEINTERACTIONINDICATORSTWO	=  1 << 2,
	ConnectToResourceArg_TAG_NULL	=  0x0000
}ConnectToResourceArg_tags;

		//! Class Definition
		/*!		ClassName is ConnectToResourceArg
		*/
class ConnectToResourceArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		ResourceAddress*		mresourceAddress;

		Extensions*		mextensions;

		ServiceInteractionIndicatorsTwo*		mserviceInteractionIndicatorsTwo;


	public:
		ConnectToResourceArg();

		~ConnectToResourceArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set ResourceAddress type of argument resourceAddress for datatype ConnectToResourceArg
		*/
		bool setresourceAddress(ResourceAddress* resourceAddress);

		//! Function to set values
		/*!		Function to set ResourceAddress type of argument resourceAddress for datatype ConnectToResourceArg
		*/
		ResourceAddress* setresourceAddress();

		//! Function to get values
		/*!		Function to set ResourceAddress type of argument resourceAddress for datatype ConnectToResourceArg
		Throws exception of which type and Summary of Exception
		*/
		ResourceAddress* getresourceAddress() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectToResourceArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectToResourceArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype ConnectToResourceArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectToResourceArg
		*/
		bool setserviceInteractionIndicatorsTwo(ServiceInteractionIndicatorsTwo* serviceInteractionIndicatorsTwo);

		//! Function to set values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectToResourceArg
		*/
		ServiceInteractionIndicatorsTwo* setserviceInteractionIndicatorsTwo();

		//! Function to get values
		/*!		Function to set ServiceInteractionIndicatorsTwo type of argument serviceInteractionIndicatorsTwo for datatype ConnectToResourceArg
		Throws exception of which type and Summary of Exception
		*/
		ServiceInteractionIndicatorsTwo* getserviceInteractionIndicatorsTwo() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ConnectToResourceArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ConnectToResourceArg
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ConnectToResourceArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ConnectToResourceArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
