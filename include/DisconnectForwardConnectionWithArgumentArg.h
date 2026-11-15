//  @(#) $Id: DisconnectForwardConnectionWithArgumentArg.h,v 1.1.2.3 2019/06/29 02:24:29 mrafi Exp $";

#ifndef DISCONNECTFORWARDCONNECTIONWITHARGUMENTARG
#define DISCONNECTFORWARDCONNECTIONWITHARGUMENTARG
#include "cap/common/src/AsnEncDec.cc"

#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapDataTypes.h"

namespace capphase3{
typedef enum _tags_DisconnectForwardConnectionWithArgumentArg
{
	DisconnectForwardConnectionWithArgumentArg_CALLSEGMENTID	=  1 << 0,
	DisconnectForwardConnectionWithArgumentArg_EXTENSIONS	=  1 << 1,
	DisconnectForwardConnectionWithArgumentArg_TAG_NULL	=  0x0000
}DisconnectForwardConnectionWithArgumentArg_tags;

		//! Class Definition
		/*!		ClassName is DisconnectForwardConnectionWithArgumentArg
		*/
class DisconnectForwardConnectionWithArgumentArg:public capstd::CapEncDecLib
{
	private:

		vector<capstd::capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::capstd::INTEGER*		mcallSegmentID;

		Extensions*		mextensions;


	public:
		DisconnectForwardConnectionWithArgumentArg();

		~DisconnectForwardConnectionWithArgumentArg();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument callSegmentID for datatype DisconnectForwardConnectionWithArgumentArg
		*/
		bool setcallSegmentID(capstd::capstd::INTEGER* callSegmentID);

		//! Function to set values
		/*!		Function to set INTEGER type of argument callSegmentID for datatype DisconnectForwardConnectionWithArgumentArg
		*/
		capstd::capstd::INTEGER* setcallSegmentID();

		//! Function to get values
		/*!		Function to set INTEGER type of argument callSegmentID for datatype DisconnectForwardConnectionWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		capstd::capstd::INTEGER* getcallSegmentID() ; //;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectForwardConnectionWithArgumentArg
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectForwardConnectionWithArgumentArg
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype DisconnectForwardConnectionWithArgumentArg
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ; //;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype DisconnectForwardConnectionWithArgumentArg
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype DisconnectForwardConnectionWithArgumentArg
		*/
		int Encode(capstd::capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DisconnectForwardConnectionWithArgumentArg
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags DisconnectForwardConnectionWithArgumentArg
		*/
		bool ValidateMandatory(char *errStr);

};

}


#endif
