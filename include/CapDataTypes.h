#ifndef PHASE3_CAPDATATYPES
#define PHASE3_CAPDATATYPES
//#include "cap/common/src/AsnEncDec.cc"

//#include "cap/common/include/BasicDecoder.h"

#include "cap/common/include/CapEncDecLib.h"

#include "CapTypes.h"
namespace capphase3{
typedef enum _tags_AOCBeforeAnswer
{
	AOCBeforeAnswer_AOCINITIAL	=  1 << 0,
	AOCBeforeAnswer_AOCSUBSEQUENT	=  1 << 1,
	AOCBeforeAnswer_TAG_NULL	=  0x0000
}AOCBeforeAnswer_tags;

		//! Class Definition
		/*!		ClassName is AOCBeforeAnswer
		*/
class AOCBeforeAnswer
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAI_GSM0224*		maOCInitial;

		AOCSubsequent*		maOCSubsequent;


	public:
		AOCBeforeAnswer();

		~AOCBeforeAnswer();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCBeforeAnswer
		*/
		bool setaOCInitial(CAI_GSM0224* aOCInitial);

		//! Function to set values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCBeforeAnswer
		*/
		CAI_GSM0224* setaOCInitial();

		//! Function to get values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCBeforeAnswer
		Throws exception of which type and Summary of Exception
		*/
		CAI_GSM0224* getaOCInitial() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCBeforeAnswer
		*/
		bool setaOCSubsequent(AOCSubsequent* aOCSubsequent);

		//! Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCBeforeAnswer
		*/
		AOCSubsequent* setaOCSubsequent();

		//! Function to get values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCBeforeAnswer
		Throws exception of which type and Summary of Exception
		*/
		AOCSubsequent* getaOCSubsequent() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AOCBeforeAnswer
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AOCBeforeAnswer
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AOCBeforeAnswer
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AOCBeforeAnswer
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_AOCGPRS
{
	AOCGPRS_AOCINITIAL	=  1 << 0,
	AOCGPRS_AOCSUBSEQUENT	=  1 << 1,
	AOCGPRS_TAG_NULL	=  0x0000
}AOCGPRS_tags;

		//! Class Definition
		/*!		ClassName is AOCGPRS
		*/
class AOCGPRS
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAI_GSM0224*		maOCInitial;

		AOCSubsequent*		maOCSubsequent;


	public:
		AOCGPRS();

		~AOCGPRS();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCGPRS
		*/
		bool setaOCInitial(CAI_GSM0224* aOCInitial);

		//! Function to set values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCGPRS
		*/
		CAI_GSM0224* setaOCInitial();

		//! Function to get values
		/*!		Function to set CAI_GSM0224 type of argument aOCInitial for datatype AOCGPRS
		Throws exception of which type and Summary of Exception
		*/
		CAI_GSM0224* getaOCInitial() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCGPRS
		*/
		bool setaOCSubsequent(AOCSubsequent* aOCSubsequent);

		//! Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCGPRS
		*/
		AOCSubsequent* setaOCSubsequent();

		//! Function to get values
		/*!		Function to set AOCSubsequent type of argument aOCSubsequent for datatype AOCGPRS
		Throws exception of which type and Summary of Exception
		*/
		AOCSubsequent* getaOCSubsequent() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AOCGPRS
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AOCGPRS
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AOCGPRS
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AOCGPRS
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_AOCSubsequent
{
	AOCSubsequent_CAI_GSM0224	=  1 << 0,
	AOCSubsequent_TARIFFSWITCHINTERVAL	=  1 << 1,
	AOCSubsequent_TAG_NULL	=  0x0000
}AOCSubsequent_tags;

		//! Class Definition
		/*!		ClassName is AOCSubsequent
		*/
class AOCSubsequent
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CAI_GSM0224*		mcAI_GSM0224;

		capstd::INTEGER*		mtariffSwitchInterval;


	public:
		AOCSubsequent();

		~AOCSubsequent();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CAI_GSM0224 type of argument cAI_GSM0224 for datatype AOCSubsequent
		*/
		bool setcAI_GSM0224(CAI_GSM0224* cAI_GSM0224);

		//! Function to set values
		/*!		Function to set CAI_GSM0224 type of argument cAI_GSM0224 for datatype AOCSubsequent
		*/
		CAI_GSM0224* setcAI_GSM0224();

		//! Function to get values
		/*!		Function to set CAI_GSM0224 type of argument cAI_GSM0224 for datatype AOCSubsequent
		Throws exception of which type and Summary of Exception
		*/
		CAI_GSM0224* getcAI_GSM0224() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype AOCSubsequent
		*/
		bool settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype AOCSubsequent
		*/
		capstd::INTEGER* settariffSwitchInterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype AOCSubsequent
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettariffSwitchInterval() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype AOCSubsequent
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype AOCSubsequent
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AOCSubsequent
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags AOCSubsequent
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(APPENDFREEFORMATDATA,
	(overwrite, "overwrite", 	 0X0000)
	(append, "append", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype AppendFreeFormatData
		*/
class AppendFreeFormatData
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		APPENDFREEFORMATDATA mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype AppendFreeFormatData
		*/
		AppendFreeFormatData();

		//!Destructor Function
		/*!		Destructor for datatype GENERIC
		*/
		~AppendFreeFormatData();

		//!Function to set values
		/*!		Function to set ENUM type for datatype AppendFreeFormatData
		*/
		bool setValue(APPENDFREEFORMATDATA val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype AppendFreeFormatData
		*/
		APPENDFREEFORMATDATA getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype AppendFreeFormatData
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype AppendFreeFormatData
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype AppendFreeFormatData
		*/
		int Display(int tab);

};
typedef enum _tags_BCSMEvent
{
	BCSMEvent_EVENTTYPEBCSM	=  1 << 0,
	BCSMEvent_MONITORMODE	=  1 << 1,
	BCSMEvent_LEGID	=  1 << 2,
	BCSMEvent_DPSPECIFICCRITERIA	=  1 << 3,
	BCSMEvent_TAG_NULL	=  0x0000
}BCSMEvent_tags;

		//! Class Definition
		/*!		ClassName is BCSMEvent
		*/
class BCSMEvent
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		EventTypeBCSM*		meventTypeBCSM;

		MonitorMode*		mmonitorMode;

		LegID*		mlegID;

		DpSpecificCriteria*		mdpSpecificCriteria;


	public:
		BCSMEvent();

		~BCSMEvent();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype BCSMEvent
		*/
		bool seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM);

		//! Function to set values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype BCSMEvent
		*/
		EventTypeBCSM* seteventTypeBCSM();

		//! Function to get values
		/*!		Function to set EventTypeBCSM type of argument eventTypeBCSM for datatype BCSMEvent
		Throws exception of which type and Summary of Exception
		*/
		EventTypeBCSM* geteventTypeBCSM() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set MonitorMode type of argument monitorMode for datatype BCSMEvent
		*/
		bool setmonitorMode(MonitorMode* monitorMode);

		//! Function to set values
		/*!		Function to set MonitorMode type of argument monitorMode for datatype BCSMEvent
		*/
		MonitorMode* setmonitorMode();

		//! Function to get values
		/*!		Function to set MonitorMode type of argument monitorMode for datatype BCSMEvent
		Throws exception of which type and Summary of Exception
		*/
		MonitorMode* getmonitorMode() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set LegID type of argument legID for datatype BCSMEvent
		*/
		bool setlegID(LegID* legID);

		//! Function to set values
		/*!		Function to set LegID type of argument legID for datatype BCSMEvent
		*/
		LegID* setlegID();

		//! Function to get values
		/*!		Function to set LegID type of argument legID for datatype BCSMEvent
		Throws exception of which type and Summary of Exception
		*/
		LegID* getlegID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set DpSpecificCriteria type of argument dpSpecificCriteria for datatype BCSMEvent
		*/
		bool setdpSpecificCriteria(DpSpecificCriteria* dpSpecificCriteria);

		//! Function to set values
		/*!		Function to set DpSpecificCriteria type of argument dpSpecificCriteria for datatype BCSMEvent
		*/
		DpSpecificCriteria* setdpSpecificCriteria();

		//! Function to get values
		/*!		Function to set DpSpecificCriteria type of argument dpSpecificCriteria for datatype BCSMEvent
		Throws exception of which type and Summary of Exception
		*/
		DpSpecificCriteria* getdpSpecificCriteria() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype BCSMEvent
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype BCSMEvent
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype BCSMEvent
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags BCSMEvent
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_BackwardServiceInteractionInd
{
	BackwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR	=  1 << 0,
	BackwardServiceInteractionInd_CALLCOMPLETIONTREATMENTINDICATOR	=  1 << 1,
	BackwardServiceInteractionInd_TAG_NULL	=  0x0000
}BackwardServiceInteractionInd_tags;

		//! Class Definition
		/*!		ClassName is BackwardServiceInteractionInd
		*/
class BackwardServiceInteractionInd
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mconferenceTreatmentIndicator;

		capstd::OctetString*		mcallCompletionTreatmentIndicator;


	public:
		BackwardServiceInteractionInd();

		~BackwardServiceInteractionInd();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype BackwardServiceInteractionInd
		*/
		bool setconferenceTreatmentIndicator(capstd::OctetString* conferenceTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype BackwardServiceInteractionInd
		*/
		capstd::OctetString* setconferenceTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype BackwardServiceInteractionInd
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getconferenceTreatmentIndicator() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callCompletionTreatmentIndicator for datatype BackwardServiceInteractionInd
		*/
		bool setcallCompletionTreatmentIndicator(capstd::OctetString* callCompletionTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument callCompletionTreatmentIndicator for datatype BackwardServiceInteractionInd
		*/
		capstd::OctetString* setcallCompletionTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument callCompletionTreatmentIndicator for datatype BackwardServiceInteractionInd
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallCompletionTreatmentIndicator() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype BackwardServiceInteractionInd
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype BackwardServiceInteractionInd
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype BackwardServiceInteractionInd
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags BackwardServiceInteractionInd
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_BasicGapCriteria
{
	BasicGapCriteria_CALLEDADDRESSVALUE	=  1 << 0,
	BasicGapCriteria_GAPONSERVICE	=  1 << 1,
	BasicGapCriteria_CALLEDADDRESSANDSERVICE	=  1 << 2,
	BasicGapCriteria_CALLINGADDRESSANDSERVICE	=  1 << 3,
	BasicGapCriteria_TAG_NULL	=  0x0000
}BasicGapCriteria_tags;

		//! Class Definition
		/*!		ClassName is BasicGapCriteria
		*/
class BasicGapCriteria
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mcalledAddressValue;

		GapOnService*		mgapOnService;

		CalledAddressAndService*		mcalledAddressAndService;

		CallingAddressAndService*		mcallingAddressAndService;


	public:
		BasicGapCriteria();

		~BasicGapCriteria();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype BasicGapCriteria
		*/
		bool setcalledAddressValue(capstd::OctetString* calledAddressValue);

		//! Function to set values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype BasicGapCriteria
		*/
		capstd::OctetString* setcalledAddressValue();

		//! Function to get values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype BasicGapCriteria
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcalledAddressValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GapOnService type of argument gapOnService for datatype BasicGapCriteria
		*/
		bool setgapOnService(GapOnService* gapOnService);

		//! Function to set values
		/*!		Function to set GapOnService type of argument gapOnService for datatype BasicGapCriteria
		*/
		GapOnService* setgapOnService();

		//! Function to get values
		/*!		Function to set GapOnService type of argument gapOnService for datatype BasicGapCriteria
		Throws exception of which type and Summary of Exception
		*/
		GapOnService* getgapOnService() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CalledAddressAndService type of argument calledAddressAndService for datatype BasicGapCriteria
		*/
		bool setcalledAddressAndService(CalledAddressAndService* calledAddressAndService);

		//! Function to set values
		/*!		Function to set CalledAddressAndService type of argument calledAddressAndService for datatype BasicGapCriteria
		*/
		CalledAddressAndService* setcalledAddressAndService();

		//! Function to get values
		/*!		Function to set CalledAddressAndService type of argument calledAddressAndService for datatype BasicGapCriteria
		Throws exception of which type and Summary of Exception
		*/
		CalledAddressAndService* getcalledAddressAndService() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CallingAddressAndService type of argument callingAddressAndService for datatype BasicGapCriteria
		*/
		bool setcallingAddressAndService(CallingAddressAndService* callingAddressAndService);

		//! Function to set values
		/*!		Function to set CallingAddressAndService type of argument callingAddressAndService for datatype BasicGapCriteria
		*/
		CallingAddressAndService* setcallingAddressAndService();

		//! Function to get values
		/*!		Function to set CallingAddressAndService type of argument callingAddressAndService for datatype BasicGapCriteria
		Throws exception of which type and Summary of Exception
		*/
		CallingAddressAndService* getcallingAddressAndService() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype BasicGapCriteria
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype BasicGapCriteria
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype BasicGapCriteria
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags BasicGapCriteria
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_BearerCapability
{
	BearerCapability_BEARERCAP	=  1 << 0,
	BearerCapability_TAG_NULL	=  0x0000
}BearerCapability_tags;

		//! Class Definition
		/*!		ClassName is BearerCapability
		*/
class BearerCapability
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mbearerCap;


	public:
		BearerCapability();

		~BearerCapability();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument bearerCap for datatype BearerCapability
		*/
		bool setbearerCap(capstd::OctetString* bearerCap);

		//! Function to set values
		/*!		Function to set OctetString type of argument bearerCap for datatype BearerCapability
		*/
		capstd::OctetString* setbearerCap();

		//! Function to get values
		/*!		Function to set OctetString type of argument bearerCap for datatype BearerCapability
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getbearerCap() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype BearerCapability
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype BearerCapability
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype BearerCapability
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags BearerCapability
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(BOTHWAYTHROUGHCONNECTIONIND,
	(bothwayPathRequired, "bothwayPathRequired", 	 0X0000)
	(bothwayPathNotRequired, "bothwayPathNotRequired", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype BothwayThroughConnectionInd
		*/
class BothwayThroughConnectionInd
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		BOTHWAYTHROUGHCONNECTIONIND mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype BothwayThroughConnectionInd
		*/
		BothwayThroughConnectionInd();

		//!Destructor Function
		/*!		Destructor for datatype CalledAddressAndService
		*/
		~BothwayThroughConnectionInd();

		//!Function to set values
		/*!		Function to set ENUM type for datatype BothwayThroughConnectionInd
		*/
		bool setValue(BOTHWAYTHROUGHCONNECTIONIND val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype BothwayThroughConnectionInd
		*/
		BOTHWAYTHROUGHCONNECTIONIND getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype BothwayThroughConnectionInd
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype BothwayThroughConnectionInd
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype BothwayThroughConnectionInd
		*/
		int Display(int tab);

};
typedef enum _tags_CAI_GSM0224
{
	CAI_GSM0224_E1	=  1 << 0,
	CAI_GSM0224_E2	=  1 << 1,
	CAI_GSM0224_E3	=  1 << 2,
	CAI_GSM0224_E4	=  1 << 3,
	CAI_GSM0224_E5	=  1 << 4,
	CAI_GSM0224_E6	=  1 << 5,
	CAI_GSM0224_E7	=  1 << 6,
	CAI_GSM0224_TAG_NULL	=  0x0000
}CAI_GSM0224_tags;

		//! Class Definition
		/*!		ClassName is CAI_GSM0224
		*/
class CAI_GSM0224
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		me1;

		capstd::INTEGER*		me2;

		capstd::INTEGER*		me3;

		capstd::INTEGER*		me4;

		capstd::INTEGER*		me5;

		capstd::INTEGER*		me6;

		capstd::INTEGER*		me7;


	public:
		CAI_GSM0224();

		~CAI_GSM0224();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument e1 for datatype CAI_GSM0224
		*/
		bool sete1(capstd::INTEGER* e1);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e1 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete1();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e1 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete1() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e2 for datatype CAI_GSM0224
		*/
		bool sete2(capstd::INTEGER* e2);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e2 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete2();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e2 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete2() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e3 for datatype CAI_GSM0224
		*/
		bool sete3(capstd::INTEGER* e3);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e3 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete3();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e3 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete3() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e4 for datatype CAI_GSM0224
		*/
		bool sete4(capstd::INTEGER* e4);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e4 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete4();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e4 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete4() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e5 for datatype CAI_GSM0224
		*/
		bool sete5(capstd::INTEGER* e5);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e5 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete5();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e5 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete5() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e6 for datatype CAI_GSM0224
		*/
		bool sete6(capstd::INTEGER* e6);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e6 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete6();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e6 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete6() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument e7 for datatype CAI_GSM0224
		*/
		bool sete7(capstd::INTEGER* e7);

		//! Function to set values
		/*!		Function to set INTEGER type of argument e7 for datatype CAI_GSM0224
		*/
		capstd::INTEGER* sete7();

		//! Function to get values
		/*!		Function to set INTEGER type of argument e7 for datatype CAI_GSM0224
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gete7() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CAI_GSM0224
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CAI_GSM0224
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CAI_GSM0224
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CAI_GSM0224
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CAMEL_AChBillingChargingCharacteristics
{
	CAMEL_AChBillingChargingCharacteristics_TIMEDURATIONCHARGING	=  1 << 0,
	CAMEL_AChBillingChargingCharacteristics_TAG_NULL	=  0x0000
}CAMEL_AChBillingChargingCharacteristics_tags;

		//! Class Definition
		/*!		ClassName is CAMEL_AChBillingChargingCharacteristics
		*/
class CAMEL_AChBillingChargingCharacteristics
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		TimeDurationCharging*		mtimeDurationCharging;


	public:
		CAMEL_AChBillingChargingCharacteristics();

		~CAMEL_AChBillingChargingCharacteristics();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set TimeDurationCharging type of argument timeDurationCharging for datatype CAMEL_AChBillingChargingCharacteristics
		*/
		bool settimeDurationCharging(TimeDurationCharging* timeDurationCharging);

		//! Function to set values
		/*!		Function to set TimeDurationCharging type of argument timeDurationCharging for datatype CAMEL_AChBillingChargingCharacteristics
		*/
		TimeDurationCharging* settimeDurationCharging();

		//! Function to get values
		/*!		Function to set TimeDurationCharging type of argument timeDurationCharging for datatype CAMEL_AChBillingChargingCharacteristics
		Throws exception of which type and Summary of Exception
		*/
		TimeDurationCharging* gettimeDurationCharging() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CAMEL_AChBillingChargingCharacteristics
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CAMEL_AChBillingChargingCharacteristics
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CAMEL_AChBillingChargingCharacteristics
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CAMEL_AChBillingChargingCharacteristics
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CAMEL_CallResult
{
	CAMEL_CallResult_TIMEDURATIONCHARGINGRESULT	=  1 << 0,
	CAMEL_CallResult_TAG_NULL	=  0x0000
}CAMEL_CallResult_tags;

		//! Class Definition
		/*!		ClassName is CAMEL_CallResult
		*/
class CAMEL_CallResult
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		TimeDurationChargingResult*		mtimeDurationChargingResult;


	public:
		CAMEL_CallResult();

		~CAMEL_CallResult();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set TimeDurationChargingResult type of argument timeDurationChargingResult for datatype CAMEL_CallResult
		*/
		bool settimeDurationChargingResult(TimeDurationChargingResult* timeDurationChargingResult);

		//! Function to set values
		/*!		Function to set TimeDurationChargingResult type of argument timeDurationChargingResult for datatype CAMEL_CallResult
		*/
		TimeDurationChargingResult* settimeDurationChargingResult();

		//! Function to get values
		/*!		Function to set TimeDurationChargingResult type of argument timeDurationChargingResult for datatype CAMEL_CallResult
		Throws exception of which type and Summary of Exception
		*/
		TimeDurationChargingResult* gettimeDurationChargingResult() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CAMEL_CallResult
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CAMEL_CallResult
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CAMEL_CallResult
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CAMEL_CallResult
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CAMEL_FCIBillingChargingCharacteristics
{
	CAMEL_FCIBillingChargingCharacteristics_FCIBCCCAMELSEQUENCE1	=  1 << 0,
	CAMEL_FCIBillingChargingCharacteristics_TAG_NULL	=  0x0000
}CAMEL_FCIBillingChargingCharacteristics_tags;

		//! Class Definition
		/*!		ClassName is CAMEL_FCIBillingChargingCharacteristics
		*/
class CAMEL_FCIBillingChargingCharacteristics
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		FCIBCCCAMELsequence1*		mfCIBCCCAMELsequence1;


	public:
		CAMEL_FCIBillingChargingCharacteristics();

		~CAMEL_FCIBillingChargingCharacteristics();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set FCIBCCCAMELsequence1 type of argument fCIBCCCAMELsequence1 for datatype CAMEL_FCIBillingChargingCharacteristics
		*/
		bool setfCIBCCCAMELsequence1(FCIBCCCAMELsequence1* fCIBCCCAMELsequence1);

		//! Function to set values
		/*!		Function to set FCIBCCCAMELsequence1 type of argument fCIBCCCAMELsequence1 for datatype CAMEL_FCIBillingChargingCharacteristics
		*/
		FCIBCCCAMELsequence1* setfCIBCCCAMELsequence1();

		//! Function to get values
		/*!		Function to set FCIBCCCAMELsequence1 type of argument fCIBCCCAMELsequence1 for datatype CAMEL_FCIBillingChargingCharacteristics
		Throws exception of which type and Summary of Exception
		*/
		FCIBCCCAMELsequence1* getfCIBCCCAMELsequence1() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CAMEL_FCIBillingChargingCharacteristics
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CAMEL_FCIBillingChargingCharacteristics
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CAMEL_FCIBillingChargingCharacteristics
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CAMEL_FCIBillingChargingCharacteristics
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CAMEL_SCIBillingChargingCharacteristics
{
	CAMEL_SCIBillingChargingCharacteristics_AOCBEFOREANSWER	=  1 << 0,
	CAMEL_SCIBillingChargingCharacteristics_AOCAFTERANSWER	=  1 << 1,
	CAMEL_SCIBillingChargingCharacteristics_TAG_NULL	=  0x0000
}CAMEL_SCIBillingChargingCharacteristics_tags;

		//! Class Definition
		/*!		ClassName is CAMEL_SCIBillingChargingCharacteristics
		*/
class CAMEL_SCIBillingChargingCharacteristics
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		AOCBeforeAnswer*		maOCBeforeAnswer;

		AOCSubsequent*		maOCAfterAnswer;


	public:
		CAMEL_SCIBillingChargingCharacteristics();

		~CAMEL_SCIBillingChargingCharacteristics();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set AOCBeforeAnswer type of argument aOCBeforeAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		bool setaOCBeforeAnswer(AOCBeforeAnswer* aOCBeforeAnswer);

		//! Function to set values
		/*!		Function to set AOCBeforeAnswer type of argument aOCBeforeAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		AOCBeforeAnswer* setaOCBeforeAnswer();

		//! Function to get values
		/*!		Function to set AOCBeforeAnswer type of argument aOCBeforeAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		Throws exception of which type and Summary of Exception
		*/
		AOCBeforeAnswer* getaOCBeforeAnswer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCAfterAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		bool setaOCAfterAnswer(AOCSubsequent* aOCAfterAnswer);

		//! Function to set values
		/*!		Function to set AOCSubsequent type of argument aOCAfterAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		AOCSubsequent* setaOCAfterAnswer();

		//! Function to get values
		/*!		Function to set AOCSubsequent type of argument aOCAfterAnswer for datatype CAMEL_SCIBillingChargingCharacteristics
		Throws exception of which type and Summary of Exception
		*/
		AOCSubsequent* getaOCAfterAnswer() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CAMEL_SCIBillingChargingCharacteristics
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CAMEL_SCIBillingChargingCharacteristics
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CAMEL_SCIBillingChargingCharacteristics
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(CGENCOUNTERED,
	(noCGencountered, "noCGencountered", 	 0X0000)
	(manualCGencountered, "manualCGencountered", 	 0X0001)
	(scpOverload, "scpOverload", 0X0002)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype CGEncountered
		*/
class CGEncountered
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		CGENCOUNTERED mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype CGEncountered
		*/
		CGEncountered();

		//!Destructor Function
		/*!		Destructor for datatype INTEGER
		*/
		~CGEncountered();

		//!Function to set values
		/*!		Function to set ENUM type for datatype CGEncountered
		*/
		bool setValue(CGENCOUNTERED val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype CGEncountered
		*/
		CGENCOUNTERED getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype CGEncountered
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype CGEncountered
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype CGEncountered
		*/
		int Display(int tab);

};
typedef enum _tags_CalledAddressAndService
{
	CalledAddressAndService_CALLEDADDRESSVALUE	=  1 << 0,
	CalledAddressAndService_SERVICEKEY	=  1 << 1,
	CalledAddressAndService_TAG_NULL	=  0x0000
}CalledAddressAndService_tags;

		//! Class Definition
		/*!		ClassName is CalledAddressAndService
		*/
class CalledAddressAndService
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mcalledAddressValue;

		capstd::INTEGER*		mserviceKey;


	public:
		CalledAddressAndService();

		~CalledAddressAndService();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype CalledAddressAndService
		*/
		bool setcalledAddressValue(capstd::OctetString* calledAddressValue);

		//! Function to set values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype CalledAddressAndService
		*/
		capstd::OctetString* setcalledAddressValue();

		//! Function to get values
		/*!		Function to set OctetString type of argument calledAddressValue for datatype CalledAddressAndService
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcalledAddressValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CalledAddressAndService
		*/
		bool setserviceKey(capstd::INTEGER* serviceKey);

		//! Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CalledAddressAndService
		*/
		capstd::INTEGER* setserviceKey();

		//! Function to get values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CalledAddressAndService
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getserviceKey() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CalledAddressAndService
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CalledAddressAndService
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CalledAddressAndService
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CalledAddressAndService
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CallingAddressAndService
{
	CallingAddressAndService_CALLINGADDRESSVALUE	=  1 << 0,
	CallingAddressAndService_SERVICEKEY	=  1 << 1,
	CallingAddressAndService_TAG_NULL	=  0x0000
}CallingAddressAndService_tags;

		//! Class Definition
		/*!		ClassName is CallingAddressAndService
		*/
class CallingAddressAndService
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mcallingAddressValue;

		capstd::INTEGER*		mserviceKey;


	public:
		CallingAddressAndService();

		~CallingAddressAndService();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument callingAddressValue for datatype CallingAddressAndService
		*/
		bool setcallingAddressValue(capstd::OctetString* callingAddressValue);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingAddressValue for datatype CallingAddressAndService
		*/
		capstd::OctetString* setcallingAddressValue();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingAddressValue for datatype CallingAddressAndService
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingAddressValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CallingAddressAndService
		*/
		bool setserviceKey(capstd::INTEGER* serviceKey);

		//! Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CallingAddressAndService
		*/
		capstd::INTEGER* setserviceKey();

		//! Function to get values
		/*!		Function to set INTEGER type of argument serviceKey for datatype CallingAddressAndService
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getserviceKey() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CallingAddressAndService
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CallingAddressAndService
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CallingAddressAndService
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CallingAddressAndService
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CellGlobalIdOrServiceAreaIdOrLAI
{
	CellGlobalIdOrServiceAreaIdOrLAI_CELLGLOBALIDORSERVICEAREAIDFIXEDLENGTH	=  1 << 0,
	CellGlobalIdOrServiceAreaIdOrLAI_LAIFIXEDLENGTH	=  1 << 1,
	CellGlobalIdOrServiceAreaIdOrLAI_TAG_NULL	=  0x0000
}CellGlobalIdOrServiceAreaIdOrLAI_tags;

		//! Class Definition
		/*!		ClassName is CellGlobalIdOrServiceAreaIdOrLAI
		*/
class CellGlobalIdOrServiceAreaIdOrLAI
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::CellGlobalIdOrServiceAreaIdFixedLength*		mcellGlobalIdOrServiceAreaIdFixedLength;

		capstd::LAIFixedLength*		mlaiFixedLength;


	public:
		CellGlobalIdOrServiceAreaIdOrLAI();

		~CellGlobalIdOrServiceAreaIdOrLAI();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdFixedLength type of argument cellGlobalIdOrServiceAreaIdFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		bool setcellGlobalIdOrServiceAreaIdFixedLength(capstd::CellGlobalIdOrServiceAreaIdFixedLength* cellGlobalIdOrServiceAreaIdFixedLength);

		//! Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdFixedLength type of argument cellGlobalIdOrServiceAreaIdFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		capstd::CellGlobalIdOrServiceAreaIdFixedLength* setcellGlobalIdOrServiceAreaIdFixedLength();

		//! Function to get values
		/*!		Function to set CellGlobalIdOrServiceAreaIdFixedLength type of argument cellGlobalIdOrServiceAreaIdFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		Throws exception of which type and Summary of Exception
		*/
		capstd::CellGlobalIdOrServiceAreaIdFixedLength* getcellGlobalIdOrServiceAreaIdFixedLength() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set LAIFixedLength type of argument laiFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		bool setlaiFixedLength(capstd::LAIFixedLength* laiFixedLength);

		//! Function to set values
		/*!		Function to set LAIFixedLength type of argument laiFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		capstd::LAIFixedLength* setlaiFixedLength();

		//! Function to get values
		/*!		Function to set LAIFixedLength type of argument laiFixedLength for datatype CellGlobalIdOrServiceAreaIdOrLAI
		Throws exception of which type and Summary of Exception
		*/
		capstd::LAIFixedLength* getlaiFixedLength() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CellGlobalIdOrServiceAreaIdOrLAI
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CellGlobalIdOrServiceAreaIdOrLAI
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CellGlobalIdOrServiceAreaIdOrLAI
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_Code
{
	Code_LOCAL	=  1 << 0,
	Code_GLOBAL	=  1 << 1,
	Code_TAG_NULL	=  0x0000
}Code_tags;

		//! Class Definition
		/*!		ClassName is Code
		*/
class Code
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mlocal;

		capstd::ObjectIdentifier*		mglobal;


	public:
		Code();

		~Code();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument local for datatype Code
		*/
		bool setlocal(capstd::INTEGER* local);

		//! Function to set values
		/*!		Function to set INTEGER type of argument local for datatype Code
		*/
		capstd::INTEGER* setlocal();

		//! Function to get values
		/*!		Function to set INTEGER type of argument local for datatype Code
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getlocal() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ObjectIdentifier type of argument global for datatype Code
		*/
		bool setglobal(capstd::ObjectIdentifier* global);

		//! Function to set values
		/*!		Function to set ObjectIdentifier type of argument global for datatype Code
		*/
		capstd::ObjectIdentifier* setglobal();

		//! Function to get values
		/*!		Function to set ObjectIdentifier type of argument global for datatype Code
		Throws exception of which type and Summary of Exception
		*/
		capstd::ObjectIdentifier* getglobal() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype Code
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype Code
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Code
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags Code
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CollectedDigits
{
	CollectedDigits_MINIMUMNBOFDIGITS	=  1 << 0,
	CollectedDigits_MAXIMUMNBOFDIGITS	=  1 << 1,
	CollectedDigits_ENDOFREPLYDIGIT	=  1 << 2,
	CollectedDigits_CANCELDIGIT	=  1 << 3,
	CollectedDigits_STARTDIGIT	=  1 << 4,
	CollectedDigits_FIRSTDIGITTIMEOUT	=  1 << 5,
	CollectedDigits_INTERDIGITTIMEOUT	=  1 << 6,
	CollectedDigits_ERRORTREATMENT	=  1 << 7,
	CollectedDigits_INTERRUPTABLEANNIND	=  1 << 8,
	CollectedDigits_VOICEINFORMATION	=  1 << 9,
	CollectedDigits_VOICEBACK	=  1 << 10,
	CollectedDigits_TAG_NULL	=  0x0000
}CollectedDigits_tags;

		//! Class Definition
		/*!		ClassName is CollectedDigits
		*/
class CollectedDigits
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER* minimumNbOfDigitsDefault;
		capstd::INTEGER*		mminimumNbOfDigits;

		capstd::INTEGER*		mmaximumNbOfDigits;

		capstd::OctetString*		mendOfReplyDigit;

		capstd::OctetString*		mcancelDigit;

		capstd::OctetString*		mstartDigit;

		capstd::INTEGER*		mfirstDigitTimeOut;

		capstd::INTEGER*		minterDigitTimeOut;

		ErrorTreatment* errorTreatmentDefault;
		ErrorTreatment*		merrorTreatment;

		capstd::Boolean* interruptableAnnIndDefault;
		capstd::Boolean*		minterruptableAnnInd;

		capstd::Boolean* voiceInformationDefault;
		capstd::Boolean*		mvoiceInformation;

		capstd::Boolean* voiceBackDefault;
		capstd::Boolean*		mvoiceBack;


	public:
		CollectedDigits();

		~CollectedDigits();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument minimumNbOfDigits for datatype CollectedDigits
		*/
		bool setminimumNbOfDigits(capstd::INTEGER* minimumNbOfDigits);

		//! Function to set values
		/*!		Function to set INTEGER type of argument minimumNbOfDigits for datatype CollectedDigits
		*/
		capstd::INTEGER* setminimumNbOfDigits();

		//! Function to get values
		/*!		Function to set INTEGER type of argument minimumNbOfDigits for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getminimumNbOfDigits() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument maximumNbOfDigits for datatype CollectedDigits
		*/
		bool setmaximumNbOfDigits(capstd::INTEGER* maximumNbOfDigits);

		//! Function to set values
		/*!		Function to set INTEGER type of argument maximumNbOfDigits for datatype CollectedDigits
		*/
		capstd::INTEGER* setmaximumNbOfDigits();

		//! Function to get values
		/*!		Function to set INTEGER type of argument maximumNbOfDigits for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getmaximumNbOfDigits() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument endOfReplyDigit for datatype CollectedDigits
		*/
		bool setendOfReplyDigit(capstd::OctetString* endOfReplyDigit);

		//! Function to set values
		/*!		Function to set OctetString type of argument endOfReplyDigit for datatype CollectedDigits
		*/
		capstd::OctetString* setendOfReplyDigit();

		//! Function to get values
		/*!		Function to set OctetString type of argument endOfReplyDigit for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getendOfReplyDigit() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument cancelDigit for datatype CollectedDigits
		*/
		bool setcancelDigit(capstd::OctetString* cancelDigit);

		//! Function to set values
		/*!		Function to set OctetString type of argument cancelDigit for datatype CollectedDigits
		*/
		capstd::OctetString* setcancelDigit();

		//! Function to get values
		/*!		Function to set OctetString type of argument cancelDigit for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcancelDigit() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument startDigit for datatype CollectedDigits
		*/
		bool setstartDigit(capstd::OctetString* startDigit);

		//! Function to set values
		/*!		Function to set OctetString type of argument startDigit for datatype CollectedDigits
		*/
		capstd::OctetString* setstartDigit();

		//! Function to get values
		/*!		Function to set OctetString type of argument startDigit for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getstartDigit() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument firstDigitTimeOut for datatype CollectedDigits
		*/
		bool setfirstDigitTimeOut(capstd::INTEGER* firstDigitTimeOut);

		//! Function to set values
		/*!		Function to set INTEGER type of argument firstDigitTimeOut for datatype CollectedDigits
		*/
		capstd::INTEGER* setfirstDigitTimeOut();

		//! Function to get values
		/*!		Function to set INTEGER type of argument firstDigitTimeOut for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getfirstDigitTimeOut() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument interDigitTimeOut for datatype CollectedDigits
		*/
		bool setinterDigitTimeOut(capstd::INTEGER* interDigitTimeOut);

		//! Function to set values
		/*!		Function to set INTEGER type of argument interDigitTimeOut for datatype CollectedDigits
		*/
		capstd::INTEGER* setinterDigitTimeOut();

		//! Function to get values
		/*!		Function to set INTEGER type of argument interDigitTimeOut for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getinterDigitTimeOut() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ErrorTreatment type of argument errorTreatment for datatype CollectedDigits
		*/
		bool seterrorTreatment(ErrorTreatment* errorTreatment);

		//! Function to set values
		/*!		Function to set ErrorTreatment type of argument errorTreatment for datatype CollectedDigits
		*/
		ErrorTreatment* seterrorTreatment();

		//! Function to get values
		/*!		Function to set ErrorTreatment type of argument errorTreatment for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		ErrorTreatment* geterrorTreatment() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument interruptableAnnInd for datatype CollectedDigits
		*/
		bool setinterruptableAnnInd(capstd::Boolean* interruptableAnnInd);

		//! Function to set values
		/*!		Function to set Boolean type of argument interruptableAnnInd for datatype CollectedDigits
		*/
		capstd::Boolean* setinterruptableAnnInd();

		//! Function to get values
		/*!		Function to set Boolean type of argument interruptableAnnInd for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* getinterruptableAnnInd() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument voiceInformation for datatype CollectedDigits
		*/
		bool setvoiceInformation(capstd::Boolean* voiceInformation);

		//! Function to set values
		/*!		Function to set Boolean type of argument voiceInformation for datatype CollectedDigits
		*/
		capstd::Boolean* setvoiceInformation();

		//! Function to get values
		/*!		Function to set Boolean type of argument voiceInformation for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* getvoiceInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument voiceBack for datatype CollectedDigits
		*/
		bool setvoiceBack(capstd::Boolean* voiceBack);

		//! Function to set values
		/*!		Function to set Boolean type of argument voiceBack for datatype CollectedDigits
		*/
		capstd::Boolean* setvoiceBack();

		//! Function to get values
		/*!		Function to set Boolean type of argument voiceBack for datatype CollectedDigits
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* getvoiceBack() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CollectedDigits
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CollectedDigits
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CollectedDigits
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CollectedDigits
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CollectedInfo
{
	CollectedInfo_COLLECTEDDIGITS	=  1 << 0,
	CollectedInfo_TAG_NULL	=  0x0000
}CollectedInfo_tags;

		//! Class Definition
		/*!		ClassName is CollectedInfo
		*/
class CollectedInfo
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CollectedDigits*		mcollectedDigits;


	public:
		CollectedInfo();

		~CollectedInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CollectedDigits type of argument collectedDigits for datatype CollectedInfo
		*/
		bool setcollectedDigits(CollectedDigits* collectedDigits);

		//! Function to set values
		/*!		Function to set CollectedDigits type of argument collectedDigits for datatype CollectedInfo
		*/
		CollectedDigits* setcollectedDigits();

		//! Function to get values
		/*!		Function to set CollectedDigits type of argument collectedDigits for datatype CollectedInfo
		Throws exception of which type and Summary of Exception
		*/
		CollectedDigits* getcollectedDigits() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CollectedInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CollectedInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CollectedInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CollectedInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_CompoundCriteria
{
	CompoundCriteria_BASICGAPCRITERIA	=  1 << 0,
	CompoundCriteria_SCFID	=  1 << 1,
	CompoundCriteria_TAG_NULL	=  0x0000
}CompoundCriteria_tags;

		//! Class Definition
		/*!		ClassName is CompoundCriteria
		*/
class CompoundCriteria
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		BasicGapCriteria*		mbasicGapCriteria;

		capstd::OctetString*		mscfID;


	public:
		CompoundCriteria();

		~CompoundCriteria();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype CompoundCriteria
		*/
		bool setbasicGapCriteria(BasicGapCriteria* basicGapCriteria);

		//! Function to set values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype CompoundCriteria
		*/
		BasicGapCriteria* setbasicGapCriteria();

		//! Function to get values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype CompoundCriteria
		Throws exception of which type and Summary of Exception
		*/
		BasicGapCriteria* getbasicGapCriteria() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument scfID for datatype CompoundCriteria
		*/
		bool setscfID(capstd::OctetString* scfID);

		//! Function to set values
		/*!		Function to set OctetString type of argument scfID for datatype CompoundCriteria
		*/
		capstd::OctetString* setscfID();

		//! Function to get values
		/*!		Function to set OctetString type of argument scfID for datatype CompoundCriteria
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getscfID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype CompoundCriteria
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype CompoundCriteria
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CompoundCriteria
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags CompoundCriteria
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(CONNECTEDNUMBERTREATMENTIND,
	(noINImpact, "noINImpact", 	 0X0000)
	(presentationRestricted, "presentationRestricted", 	 0X0001)
	(presentCalledINNumber, "presentCalledINNumber", 	 0X0002)
	(presentCallINNumberRestricted, "presentCallINNumberRestricted", 0X0003)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype ConnectedNumberTreatmentInd
		*/
class ConnectedNumberTreatmentInd
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		CONNECTEDNUMBERTREATMENTIND mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype ConnectedNumberTreatmentInd
		*/
		ConnectedNumberTreatmentInd();

		//!Destructor Function
		/*!		Destructor for datatype OctetString
		*/
		~ConnectedNumberTreatmentInd();

		//!Function to set values
		/*!		Function to set ENUM type for datatype ConnectedNumberTreatmentInd
		*/
		bool setValue(CONNECTEDNUMBERTREATMENTIND val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype ConnectedNumberTreatmentInd
		*/
		CONNECTEDNUMBERTREATMENTIND getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype ConnectedNumberTreatmentInd
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype ConnectedNumberTreatmentInd
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype ConnectedNumberTreatmentInd
		*/
		int Display(int tab);

};

TSS_ENUM(CONTROLTYPE,
	(sCPOverloaded, "sCPOverloaded", 	 0X0000)
	(manuallyInitiated, "manuallyInitiated", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype ControlType
		*/
class ControlType
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		CONTROLTYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype ControlType
		*/
		ControlType();

		//!Destructor Function
		/*!		Destructor for datatype ServiceInteractionIndicatorsTwo
		*/
		~ControlType();

		//!Function to set values
		/*!		Function to set ENUM type for datatype ControlType
		*/
		bool setValue(CONTROLTYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype ControlType
		*/
		CONTROLTYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype ControlType
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype ControlType
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype ControlType
		*/
		int Display(int tab);

};

TSS_ENUM(CRITICALITYTYPE,
	(ignore, "ignore", 	 0X0000)
	(ctabort, "ctabort", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype CriticalityType
		*/
class CriticalityType
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		CRITICALITYTYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype CriticalityType
		*/
		CriticalityType();

		//!Destructor Function
		/*!		Destructor for datatype ServiceInteractionIndicatorsTwo
		*/
		~CriticalityType();

		//!Function to set values
		/*!		Function to set ENUM type for datatype CriticalityType
		*/
		bool setValue(CRITICALITYTYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype CriticalityType
		*/
		CRITICALITYTYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype CriticalityType
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype CriticalityType
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype CriticalityType
		*/
		int Display(int tab);

};

class DestinationRoutingAddress
{
	private:

		vector<capstd::OctetString *> mParamList;

		capstd::OctetString*  mOctetString;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		DestinationRoutingAddress();

		~DestinationRoutingAddress();

		bool setOctetString(capstd::OctetString* octetString);

		capstd::OctetString* setOctetString();

		capstd::OctetString* setNewOctetString();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First OctetString type of argument OctetString for datatype DestinationRoutingAddress list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetString() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value OctetString type of argument OctetString for datatype DestinationRoutingAddress at given location
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetStringAtLocation(unsigned location) ;//throw(const char*)

		capstd::OctetString* setNextOctetString();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next OctetString type of argument OctetString for datatype DestinationRoutingAddress list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getNextOctetString() ;//throw(const char*)

		unsigned getNoOfOctetString();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};

TSS_ENUM(DOMAINTYPE,
	(cs_Domain, "cs_Domain", 	 0X0000)
	(ps_Domain, "ps_Domain", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype DomainType
		*/
class DomainType
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		DOMAINTYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype DomainType
		*/
		DomainType();

		//!Destructor Function
		/*!		Destructor for datatype ServiceInteractionIndicatorsTwo
		*/
		~DomainType();

		//!Function to set values
		/*!		Function to set ENUM type for datatype DomainType
		*/
		bool setValue(DOMAINTYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype DomainType
		*/
		DOMAINTYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype DomainType
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype DomainType
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype DomainType
		*/
		int Display(int tab);

};
typedef enum _tags_DpSpecificCriteria
{
	DpSpecificCriteria_APPLICATIONTIMER	=  1 << 0,
	DpSpecificCriteria_TAG_NULL	=  0x0000
}DpSpecificCriteria_tags;

		//! Class Definition
		/*!		ClassName is DpSpecificCriteria
		*/
class DpSpecificCriteria
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mapplicationTimer;


	public:
		DpSpecificCriteria();

		~DpSpecificCriteria();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument applicationTimer for datatype DpSpecificCriteria
		*/
		bool setapplicationTimer(capstd::INTEGER* applicationTimer);

		//! Function to set values
		/*!		Function to set INTEGER type of argument applicationTimer for datatype DpSpecificCriteria
		*/
		capstd::INTEGER* setapplicationTimer();

		//! Function to get values
		/*!		Function to set INTEGER type of argument applicationTimer for datatype DpSpecificCriteria
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getapplicationTimer() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype DpSpecificCriteria
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype DpSpecificCriteria
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DpSpecificCriteria
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags DpSpecificCriteria
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ElapsedTime
{
	ElapsedTime_TIMEGPRSIFNOTARIFFSWITCH	=  1 << 0,
	ElapsedTime_TIMEGPRSIFTARIFFSWITCH	=  1 << 1,
	ElapsedTime_TAG_NULL	=  0x0000
}ElapsedTime_tags;

		//! Class Definition
		/*!		ClassName is ElapsedTime
		*/
class ElapsedTime
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mtimeGPRSIfNoTariffSwitch;

		TimeGPRSIfTariffSwitch*		mtimeGPRSIfTariffSwitch;


	public:
		ElapsedTime();

		~ElapsedTime();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSIfNoTariffSwitch for datatype ElapsedTime
		*/
		bool settimeGPRSIfNoTariffSwitch(capstd::INTEGER* timeGPRSIfNoTariffSwitch);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSIfNoTariffSwitch for datatype ElapsedTime
		*/
		capstd::INTEGER* settimeGPRSIfNoTariffSwitch();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timeGPRSIfNoTariffSwitch for datatype ElapsedTime
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimeGPRSIfNoTariffSwitch() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeGPRSIfTariffSwitch type of argument timeGPRSIfTariffSwitch for datatype ElapsedTime
		*/
		bool settimeGPRSIfTariffSwitch(TimeGPRSIfTariffSwitch* timeGPRSIfTariffSwitch);

		//! Function to set values
		/*!		Function to set TimeGPRSIfTariffSwitch type of argument timeGPRSIfTariffSwitch for datatype ElapsedTime
		*/
		TimeGPRSIfTariffSwitch* settimeGPRSIfTariffSwitch();

		//! Function to get values
		/*!		Function to set TimeGPRSIfTariffSwitch type of argument timeGPRSIfTariffSwitch for datatype ElapsedTime
		Throws exception of which type and Summary of Exception
		*/
		TimeGPRSIfTariffSwitch* gettimeGPRSIfTariffSwitch() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ElapsedTime
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ElapsedTime
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ElapsedTime
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ElapsedTime
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(ERRORTREATMENT,
	(stdErrorAndInfo, "stdErrorAndInfo", 	 0X0000)
	(help, "help", 	 0X0001)
	(repeatPrompt, "repeatPrompt", 0X0002)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype ErrorTreatment
		*/
class ErrorTreatment
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		ERRORTREATMENT mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype ErrorTreatment
		*/
		ErrorTreatment();

		//!Destructor Function
		/*!		Destructor for datatype OctetString
		*/
		~ErrorTreatment();

		//!Function to set values
		/*!		Function to set ENUM type for datatype ErrorTreatment
		*/
		bool setValue(ERRORTREATMENT val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype ErrorTreatment
		*/
		ERRORTREATMENT getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype ErrorTreatment
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype ErrorTreatment
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype ErrorTreatment
		*/
		int Display(int tab);

};
typedef enum _tags_EventSpecificInformationBCSM
{
	EventSpecificInformationBCSM_ROUTESELECTFAILURESPECIFICINFO	=  1 << 0,
	EventSpecificInformationBCSM_OCALLEDPARTYBUSYSPECIFICINFO	=  1 << 1,
	EventSpecificInformationBCSM_OANSWERSPECIFICINFO	=  1 << 2,
	EventSpecificInformationBCSM_ODISCONNECTSPECIFICINFO	=  1 << 3,
	EventSpecificInformationBCSM_TBUSYSPECIFICINFO	=  1 << 4,
	EventSpecificInformationBCSM_TNOANSWERSPECIFICINFO	=  1 << 5,
	EventSpecificInformationBCSM_TANSWERSPECIFICINFO	=  1 << 6,
	EventSpecificInformationBCSM_TDISCONNECTSPECIFICINFO	=  1 << 7,
	EventSpecificInformationBCSM_TAG_NULL	=  0x0000
}EventSpecificInformationBCSM_tags;

		//! Class Definition
		/*!		ClassName is EventSpecificInformationBCSM
		*/
class EventSpecificInformationBCSM
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		RouteSelectFailureSpecificInfo*		mrouteSelectFailureSpecificInfo;

		OCalledPartyBusySpecificInfo*		moCalledPartyBusySpecificInfo;

		OAnswerSpecificInfo*		moAnswerSpecificInfo;

		ODisconnectSpecificInfo*		moDisconnectSpecificInfo;

		TBusySpecificInfo*		mtBusySpecificInfo;

		TNoAnswerSpecificInfo*		mtNoAnswerSpecificInfo;

		TAnswerSpecificInfo*		mtAnswerSpecificInfo;

		TDisconnectSpecificInfo*		mtDisconnectSpecificInfo;


	public:
		EventSpecificInformationBCSM();

		~EventSpecificInformationBCSM();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set RouteSelectFailureSpecificInfo type of argument routeSelectFailureSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool setrouteSelectFailureSpecificInfo(RouteSelectFailureSpecificInfo* routeSelectFailureSpecificInfo);

		//! Function to set values
		/*!		Function to set RouteSelectFailureSpecificInfo type of argument routeSelectFailureSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		RouteSelectFailureSpecificInfo* setrouteSelectFailureSpecificInfo();

		//! Function to get values
		/*!		Function to set RouteSelectFailureSpecificInfo type of argument routeSelectFailureSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		RouteSelectFailureSpecificInfo* getrouteSelectFailureSpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OCalledPartyBusySpecificInfo type of argument oCalledPartyBusySpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool setoCalledPartyBusySpecificInfo(OCalledPartyBusySpecificInfo* oCalledPartyBusySpecificInfo);

		//! Function to set values
		/*!		Function to set OCalledPartyBusySpecificInfo type of argument oCalledPartyBusySpecificInfo for datatype EventSpecificInformationBCSM
		*/
		OCalledPartyBusySpecificInfo* setoCalledPartyBusySpecificInfo();

		//! Function to get values
		/*!		Function to set OCalledPartyBusySpecificInfo type of argument oCalledPartyBusySpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		OCalledPartyBusySpecificInfo* getoCalledPartyBusySpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OAnswerSpecificInfo type of argument oAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool setoAnswerSpecificInfo(OAnswerSpecificInfo* oAnswerSpecificInfo);

		//! Function to set values
		/*!		Function to set OAnswerSpecificInfo type of argument oAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		OAnswerSpecificInfo* setoAnswerSpecificInfo();

		//! Function to get values
		/*!		Function to set OAnswerSpecificInfo type of argument oAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		OAnswerSpecificInfo* getoAnswerSpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ODisconnectSpecificInfo type of argument oDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool setoDisconnectSpecificInfo(ODisconnectSpecificInfo* oDisconnectSpecificInfo);

		//! Function to set values
		/*!		Function to set ODisconnectSpecificInfo type of argument oDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		ODisconnectSpecificInfo* setoDisconnectSpecificInfo();

		//! Function to get values
		/*!		Function to set ODisconnectSpecificInfo type of argument oDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		ODisconnectSpecificInfo* getoDisconnectSpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TBusySpecificInfo type of argument tBusySpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool settBusySpecificInfo(TBusySpecificInfo* tBusySpecificInfo);

		//! Function to set values
		/*!		Function to set TBusySpecificInfo type of argument tBusySpecificInfo for datatype EventSpecificInformationBCSM
		*/
		TBusySpecificInfo* settBusySpecificInfo();

		//! Function to get values
		/*!		Function to set TBusySpecificInfo type of argument tBusySpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		TBusySpecificInfo* gettBusySpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TNoAnswerSpecificInfo type of argument tNoAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool settNoAnswerSpecificInfo(TNoAnswerSpecificInfo* tNoAnswerSpecificInfo);

		//! Function to set values
		/*!		Function to set TNoAnswerSpecificInfo type of argument tNoAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		TNoAnswerSpecificInfo* settNoAnswerSpecificInfo();

		//! Function to get values
		/*!		Function to set TNoAnswerSpecificInfo type of argument tNoAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		TNoAnswerSpecificInfo* gettNoAnswerSpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TAnswerSpecificInfo type of argument tAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool settAnswerSpecificInfo(TAnswerSpecificInfo* tAnswerSpecificInfo);

		//! Function to set values
		/*!		Function to set TAnswerSpecificInfo type of argument tAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		TAnswerSpecificInfo* settAnswerSpecificInfo();

		//! Function to get values
		/*!		Function to set TAnswerSpecificInfo type of argument tAnswerSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		TAnswerSpecificInfo* gettAnswerSpecificInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TDisconnectSpecificInfo type of argument tDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		bool settDisconnectSpecificInfo(TDisconnectSpecificInfo* tDisconnectSpecificInfo);

		//! Function to set values
		/*!		Function to set TDisconnectSpecificInfo type of argument tDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		*/
		TDisconnectSpecificInfo* settDisconnectSpecificInfo();

		//! Function to get values
		/*!		Function to set TDisconnectSpecificInfo type of argument tDisconnectSpecificInfo for datatype EventSpecificInformationBCSM
		Throws exception of which type and Summary of Exception
		*/
		TDisconnectSpecificInfo* gettDisconnectSpecificInfo() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype EventSpecificInformationBCSM
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype EventSpecificInformationBCSM
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype EventSpecificInformationBCSM
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags EventSpecificInformationBCSM
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(EVENTTYPEBCSM,
	(collectedInfo, "collectedInfo", 	 0X0002)
	(analyzedInformation, "analyzedInformation", 	 0X0003)
	(routeSelectFailure, "routeSelectFailure", 	 0X0004)
	(oCalledPartyBusy, "oCalledPartyBusy", 	 0X0005)
	(oNoAnswer, "oNoAnswer", 	 0X0006)
	(oAnswer, "oAnswer", 	 0X0007)
	(oDisconnect, "oDisconnect", 	 0X0009)
	(oAbandon, "oAbandon", 	 0X000A)
	(termAttemptAuthorized, "termAttemptAuthorized", 	 0X000C)
	(tBusy, "tBusy", 	 0X000D)
	(tNoAnswer, "tNoAnswer", 	 0X000E)
	(tAnswer, "tAnswer", 	 0X000F)
	(tDisconnect, "tDisconnect", 	 0X0011)
	(tAbandon, "tAbandon", 0X0012)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype EventTypeBCSM
		*/
class EventTypeBCSM
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		EVENTTYPEBCSM mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype EventTypeBCSM
		*/
		EventTypeBCSM();

		//!Destructor Function
		/*!		Destructor for datatype NULL
		*/
		~EventTypeBCSM();

		//!Function to set values
		/*!		Function to set ENUM type for datatype EventTypeBCSM
		*/
		bool setValue(EVENTTYPEBCSM val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype EventTypeBCSM
		*/
		EVENTTYPEBCSM getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype EventTypeBCSM
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype EventTypeBCSM
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype EventTypeBCSM
		*/
		int Display(int tab);

};
typedef enum _tags_Ext_BasicServiceCode
{
	Ext_BasicServiceCode_EXT_BEARERSERVICE	=  1 << 0,
	Ext_BasicServiceCode_EXT_TELESERVICE	=  1 << 1,
	Ext_BasicServiceCode_TAG_NULL	=  0x0000
}Ext_BasicServiceCode_tags;

		//! Class Definition
		/*!		ClassName is Ext_BasicServiceCode
		*/
class Ext_BasicServiceCode
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mext_BearerService;

		capstd::OctetString*		mext_Teleservice;


	public:
		Ext_BasicServiceCode();

		~Ext_BasicServiceCode();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument ext_BearerService for datatype Ext_BasicServiceCode
		*/
		bool setext_BearerService(capstd::OctetString* ext_BearerService);

		//! Function to set values
		/*!		Function to set OctetString type of argument ext_BearerService for datatype Ext_BasicServiceCode
		*/
		capstd::OctetString* setext_BearerService();

		//! Function to get values
		/*!		Function to set OctetString type of argument ext_BearerService for datatype Ext_BasicServiceCode
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getext_BearerService() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ext_Teleservice for datatype Ext_BasicServiceCode
		*/
		bool setext_Teleservice(capstd::OctetString* ext_Teleservice);

		//! Function to set values
		/*!		Function to set OctetString type of argument ext_Teleservice for datatype Ext_BasicServiceCode
		*/
		capstd::OctetString* setext_Teleservice();

		//! Function to get values
		/*!		Function to set OctetString type of argument ext_Teleservice for datatype Ext_BasicServiceCode
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getext_Teleservice() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype Ext_BasicServiceCode
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype Ext_BasicServiceCode
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Ext_BasicServiceCode
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags Ext_BasicServiceCode
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ExtensionContainer
{
	ExtensionContainer_PRIVATEEXTENSIONLIST	=  1 << 0,
	ExtensionContainer_TAG_NULL	=  0x0000
}ExtensionContainer_tags;

		//! Class Definition
		/*!		ClassName is ExtensionContainer
		*/
class ExtensionContainer
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		PrivateExtensionList*		mprivateExtensionList;


	public:
		ExtensionContainer();

		~ExtensionContainer();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set PrivateExtensionList type of argument privateExtensionList for datatype ExtensionContainer
		*/
		bool setprivateExtensionList(PrivateExtensionList* privateExtensionList);

		//! Function to set values
		/*!		Function to set PrivateExtensionList type of argument privateExtensionList for datatype ExtensionContainer
		*/
		PrivateExtensionList* setprivateExtensionList();

		//! Function to get values
		/*!		Function to set PrivateExtensionList type of argument privateExtensionList for datatype ExtensionContainer
		Throws exception of which type and Summary of Exception
		*/
		PrivateExtensionList* getprivateExtensionList() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ExtensionContainer
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ExtensionContainer
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ExtensionContainer
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ExtensionContainer
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ExtensionField
{
	ExtensionField_TYPE	=  1 << 0,
	ExtensionField_CRITICALITY	=  1 << 1,
	ExtensionField_VALUE	=  1 << 2,
	ExtensionField_TAG_NULL	=  0x0000
}ExtensionField_tags;

		//! Class Definition
		/*!		ClassName is ExtensionField
		*/
class ExtensionField
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		Code*		mtype;

		CriticalityType* criticalityDefault;
		CriticalityType*		mcriticality;

		SupportedExtensionsExtensionType*		mvalue;


	public:
		ExtensionField();

		~ExtensionField();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set Code type of argument type for datatype ExtensionField
		*/
		bool settype(Code* type);

		//! Function to set values
		/*!		Function to set Code type of argument type for datatype ExtensionField
		*/
		Code* settype();

		//! Function to get values
		/*!		Function to set Code type of argument type for datatype ExtensionField
		Throws exception of which type and Summary of Exception
		*/
		Code* gettype() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CriticalityType type of argument criticality for datatype ExtensionField
		*/
		bool setcriticality(CriticalityType* criticality);

		//! Function to set values
		/*!		Function to set CriticalityType type of argument criticality for datatype ExtensionField
		*/
		CriticalityType* setcriticality();

		//! Function to get values
		/*!		Function to set CriticalityType type of argument criticality for datatype ExtensionField
		Throws exception of which type and Summary of Exception
		*/
		CriticalityType* getcriticality() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SupportedExtensionsExtensionType type of argument value for datatype ExtensionField
		*/
		bool setvalue(SupportedExtensionsExtensionType* value);

		//! Function to set values
		/*!		Function to set SupportedExtensionsExtensionType type of argument value for datatype ExtensionField
		*/
		SupportedExtensionsExtensionType* setvalue();

		//! Function to get values
		/*!		Function to set SupportedExtensionsExtensionType type of argument value for datatype ExtensionField
		Throws exception of which type and Summary of Exception
		*/
		SupportedExtensionsExtensionType* getvalue() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ExtensionField
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ExtensionField
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ExtensionField
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ExtensionField
		*/
		bool ValidateMandatory(char *errStr);

};

class Extensions
{
	private:

		vector<ExtensionField *> mParamList;

		ExtensionField*  mExtensionField;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		Extensions();

		~Extensions();

		bool setExtensionField(ExtensionField* extensionField);

		ExtensionField* setExtensionField();

		ExtensionField* setNewExtensionField();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First ExtensionField type of argument ExtensionField for datatype Extensions list
		Throws exception of which type and Summary of Exception
		*/
		ExtensionField* getExtensionField() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value ExtensionField type of argument ExtensionField for datatype Extensions at given location
		Throws exception of which type and Summary of Exception
		*/
		ExtensionField* getExtensionFieldAtLocation(unsigned location) ;//throw(const char*)

		ExtensionField* setNextExtensionField();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next ExtensionField type of argument ExtensionField for datatype Extensions list
		Throws exception of which type and Summary of Exception
		*/
		ExtensionField* getNextExtensionField() ;//throw(const char*)

		unsigned getNoOfExtensionField();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};
typedef enum _tags_FCIBCCCAMELsequence1
{
	FCIBCCCAMELsequence1_FREEFORMATDATA	=  1 << 0,
	FCIBCCCAMELsequence1_PARTYTOCHARGE	=  1 << 1,
	FCIBCCCAMELsequence1_APPENDFREEFORMATDATA	=  1 << 2,
	FCIBCCCAMELsequence1_TAG_NULL	=  0x0000
}FCIBCCCAMELsequence1_tags;

		//! Class Definition
		/*!		ClassName is FCIBCCCAMELsequence1
		*/
class FCIBCCCAMELsequence1
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mfreeFormatData;

		SendingSideID* partyToChargeDefault;
		SendingSideID*		mpartyToCharge;

		AppendFreeFormatData* appendFreeFormatDataDefault;
		AppendFreeFormatData*		mappendFreeFormatData;


	public:
		FCIBCCCAMELsequence1();

		~FCIBCCCAMELsequence1();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument freeFormatData for datatype FCIBCCCAMELsequence1
		*/
		bool setfreeFormatData(capstd::OctetString* freeFormatData);

		//! Function to set values
		/*!		Function to set OctetString type of argument freeFormatData for datatype FCIBCCCAMELsequence1
		*/
		capstd::OctetString* setfreeFormatData();

		//! Function to get values
		/*!		Function to set OctetString type of argument freeFormatData for datatype FCIBCCCAMELsequence1
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getfreeFormatData() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype FCIBCCCAMELsequence1
		*/
		bool setpartyToCharge(SendingSideID* partyToCharge);

		//! Function to set values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype FCIBCCCAMELsequence1
		*/
		SendingSideID* setpartyToCharge();

		//! Function to get values
		/*!		Function to set SendingSideID type of argument partyToCharge for datatype FCIBCCCAMELsequence1
		Throws exception of which type and Summary of Exception
		*/
		SendingSideID* getpartyToCharge() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set AppendFreeFormatData type of argument appendFreeFormatData for datatype FCIBCCCAMELsequence1
		*/
		bool setappendFreeFormatData(AppendFreeFormatData* appendFreeFormatData);

		//! Function to set values
		/*!		Function to set AppendFreeFormatData type of argument appendFreeFormatData for datatype FCIBCCCAMELsequence1
		*/
		AppendFreeFormatData* setappendFreeFormatData();

		//! Function to get values
		/*!		Function to set AppendFreeFormatData type of argument appendFreeFormatData for datatype FCIBCCCAMELsequence1
		Throws exception of which type and Summary of Exception
		*/
		AppendFreeFormatData* getappendFreeFormatData() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype FCIBCCCAMELsequence1
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype FCIBCCCAMELsequence1
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FCIBCCCAMELsequence1
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags FCIBCCCAMELsequence1
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ForwardServiceInteractionInd
{
	ForwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR	=  1 << 0,
	ForwardServiceInteractionInd_CALLDIVERSIONTREATMENTINDICATOR	=  1 << 1,
	ForwardServiceInteractionInd_CALLINGPARTYRESTRICTIONINDICATOR	=  1 << 2,
	ForwardServiceInteractionInd_TAG_NULL	=  0x0000
}ForwardServiceInteractionInd_tags;

		//! Class Definition
		/*!		ClassName is ForwardServiceInteractionInd
		*/
class ForwardServiceInteractionInd
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mconferenceTreatmentIndicator;

		capstd::OctetString*		mcallDiversionTreatmentIndicator;

		capstd::OctetString*		mcallingPartyRestrictionIndicator;


	public:
		ForwardServiceInteractionInd();

		~ForwardServiceInteractionInd();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype ForwardServiceInteractionInd
		*/
		bool setconferenceTreatmentIndicator(capstd::OctetString* conferenceTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype ForwardServiceInteractionInd
		*/
		capstd::OctetString* setconferenceTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument conferenceTreatmentIndicator for datatype ForwardServiceInteractionInd
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getconferenceTreatmentIndicator() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callDiversionTreatmentIndicator for datatype ForwardServiceInteractionInd
		*/
		bool setcallDiversionTreatmentIndicator(capstd::OctetString* callDiversionTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument callDiversionTreatmentIndicator for datatype ForwardServiceInteractionInd
		*/
		capstd::OctetString* setcallDiversionTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument callDiversionTreatmentIndicator for datatype ForwardServiceInteractionInd
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallDiversionTreatmentIndicator() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument callingPartyRestrictionIndicator for datatype ForwardServiceInteractionInd
		*/
		bool setcallingPartyRestrictionIndicator(capstd::OctetString* callingPartyRestrictionIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument callingPartyRestrictionIndicator for datatype ForwardServiceInteractionInd
		*/
		capstd::OctetString* setcallingPartyRestrictionIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument callingPartyRestrictionIndicator for datatype ForwardServiceInteractionInd
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcallingPartyRestrictionIndicator() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ForwardServiceInteractionInd
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ForwardServiceInteractionInd
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ForwardServiceInteractionInd
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ForwardServiceInteractionInd
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_GPRSMSClass
{
	GPRSMSClass_MSNETWORKCAPABILITY	=  1 << 0,
	GPRSMSClass_MSRADIOACCESSCAPABILITY	=  1 << 1,
	GPRSMSClass_TAG_NULL	=  0x0000
}GPRSMSClass_tags;

		//! Class Definition
		/*!		ClassName is GPRSMSClass
		*/
class GPRSMSClass
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mmSNetworkCapability;

		capstd::OctetString*		mmSRadioAccessCapability;


	public:
		GPRSMSClass();

		~GPRSMSClass();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument mSNetworkCapability for datatype GPRSMSClass
		*/
		bool setmSNetworkCapability(capstd::OctetString* mSNetworkCapability);

		//! Function to set values
		/*!		Function to set OctetString type of argument mSNetworkCapability for datatype GPRSMSClass
		*/
		capstd::OctetString* setmSNetworkCapability();

		//! Function to get values
		/*!		Function to set OctetString type of argument mSNetworkCapability for datatype GPRSMSClass
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmSNetworkCapability() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument mSRadioAccessCapability for datatype GPRSMSClass
		*/
		bool setmSRadioAccessCapability(capstd::OctetString* mSRadioAccessCapability);

		//! Function to set values
		/*!		Function to set OctetString type of argument mSRadioAccessCapability for datatype GPRSMSClass
		*/
		capstd::OctetString* setmSRadioAccessCapability();

		//! Function to get values
		/*!		Function to set OctetString type of argument mSRadioAccessCapability for datatype GPRSMSClass
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmSRadioAccessCapability() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype GPRSMSClass
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype GPRSMSClass
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GPRSMSClass
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags GPRSMSClass
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_GapCriteria
{
	GapCriteria_BASICGAPCRITERIA	=  1 << 0,
	GapCriteria_COMPOUNDGAPCRITERIA	=  1 << 1,
	GapCriteria_TAG_NULL	=  0x0000
}GapCriteria_tags;

		//! Class Definition
		/*!		ClassName is GapCriteria
		*/
class GapCriteria
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		BasicGapCriteria*		mbasicGapCriteria;

		CompoundCriteria*		mcompoundGapCriteria;


	public:
		GapCriteria();

		~GapCriteria();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype GapCriteria
		*/
		bool setbasicGapCriteria(BasicGapCriteria* basicGapCriteria);

		//! Function to set values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype GapCriteria
		*/
		BasicGapCriteria* setbasicGapCriteria();

		//! Function to get values
		/*!		Function to set BasicGapCriteria type of argument basicGapCriteria for datatype GapCriteria
		Throws exception of which type and Summary of Exception
		*/
		BasicGapCriteria* getbasicGapCriteria() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CompoundCriteria type of argument compoundGapCriteria for datatype GapCriteria
		*/
		bool setcompoundGapCriteria(CompoundCriteria* compoundGapCriteria);

		//! Function to set values
		/*!		Function to set CompoundCriteria type of argument compoundGapCriteria for datatype GapCriteria
		*/
		CompoundCriteria* setcompoundGapCriteria();

		//! Function to get values
		/*!		Function to set CompoundCriteria type of argument compoundGapCriteria for datatype GapCriteria
		Throws exception of which type and Summary of Exception
		*/
		CompoundCriteria* getcompoundGapCriteria() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype GapCriteria
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype GapCriteria
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GapCriteria
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags GapCriteria
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_GapIndicators
{
	GapIndicators_DURATION	=  1 << 0,
	GapIndicators_GAPINTERVAL	=  1 << 1,
	GapIndicators_TAG_NULL	=  0x0000
}GapIndicators_tags;

		//! Class Definition
		/*!		ClassName is GapIndicators
		*/
class GapIndicators
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mduration;

		capstd::INTEGER*		mgapInterval;


	public:
		GapIndicators();

		~GapIndicators();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype GapIndicators
		*/
		bool setduration(capstd::INTEGER* duration);

		//! Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype GapIndicators
		*/
		capstd::INTEGER* setduration();

		//! Function to get values
		/*!		Function to set INTEGER type of argument duration for datatype GapIndicators
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getduration() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument gapInterval for datatype GapIndicators
		*/
		bool setgapInterval(capstd::INTEGER* gapInterval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument gapInterval for datatype GapIndicators
		*/
		capstd::INTEGER* setgapInterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument gapInterval for datatype GapIndicators
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getgapInterval() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype GapIndicators
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype GapIndicators
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GapIndicators
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags GapIndicators
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_GapOnService
{
	GapOnService_SERVICEKEY	=  1 << 0,
	GapOnService_TAG_NULL	=  0x0000
}GapOnService_tags;

		//! Class Definition
		/*!		ClassName is GapOnService
		*/
class GapOnService
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mserviceKey;


	public:
		GapOnService();

		~GapOnService();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype GapOnService
		*/
		bool setserviceKey(capstd::INTEGER* serviceKey);

		//! Function to set values
		/*!		Function to set INTEGER type of argument serviceKey for datatype GapOnService
		*/
		capstd::INTEGER* setserviceKey();

		//! Function to get values
		/*!		Function to set INTEGER type of argument serviceKey for datatype GapOnService
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getserviceKey() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype GapOnService
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype GapOnService
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GapOnService
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags GapOnService
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_GapTreatment
{
	GapTreatment_INFORMATIONTOSEND	=  1 << 0,
	GapTreatment_RELEASECAUSE	=  1 << 1,
	GapTreatment_TAG_NULL	=  0x0000
}GapTreatment_tags;

		//! Class Definition
		/*!		ClassName is GapTreatment
		*/
class GapTreatment
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		InformationToSend*		minformationToSend;

		capstd::GENERIC*		mreleaseCause;


	public:
		GapTreatment();

		~GapTreatment();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set InformationToSend type of argument informationToSend for datatype GapTreatment
		*/
		bool setinformationToSend(InformationToSend* informationToSend);

		//! Function to set values
		/*!		Function to set InformationToSend type of argument informationToSend for datatype GapTreatment
		*/
		InformationToSend* setinformationToSend();

		//! Function to get values
		/*!		Function to set InformationToSend type of argument informationToSend for datatype GapTreatment
		Throws exception of which type and Summary of Exception
		*/
		InformationToSend* getinformationToSend() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype GapTreatment
		*/
		bool setreleaseCause(capstd::GENERIC* releaseCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype GapTreatment
		*/
		capstd::GENERIC* setreleaseCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument releaseCause for datatype GapTreatment
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getreleaseCause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype GapTreatment
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype GapTreatment
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GapTreatment
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags GapTreatment
		*/
		bool ValidateMandatory(char *errStr);

};

class GenericNumbers
{
	private:

		vector<capstd::OctetString *> mParamList;

		capstd::OctetString*  mOctetString;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		GenericNumbers();

		~GenericNumbers();

		bool setOctetString(capstd::OctetString* octetString);

		capstd::OctetString* setOctetString();

		capstd::OctetString* setNewOctetString();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First OctetString type of argument OctetString for datatype GenericNumbers list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetString() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value OctetString type of argument OctetString for datatype GenericNumbers at given location
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetStringAtLocation(unsigned location) ;//throw(const char*)

		capstd::OctetString* setNextOctetString();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next OctetString type of argument OctetString for datatype GenericNumbers list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getNextOctetString() ;//throw(const char*)

		unsigned getNoOfOctetString();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};

TSS_ENUM(IMS_VOICEOVERPS_SESSIONSIND,
	(imsVoiceOverPS_SessionsNotSupported, "imsVoiceOverPS_SessionsNotSupported", 	 0X0000)
	(imsVoiceOverPS_SessionsSupported, "imsVoiceOverPS_SessionsSupported", 	 0X0001)
	(unknown, "unknown", 0X0002)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype IMS_VoiceOverPS_SessionsInd
		*/
class IMS_VoiceOverPS_SessionsInd
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		IMS_VOICEOVERPS_SESSIONSIND mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype IMS_VoiceOverPS_SessionsInd
		*/
		IMS_VoiceOverPS_SessionsInd();

		//!Destructor Function
		/*!		Destructor for datatype oCalledPartyBusy
		*/
		~IMS_VoiceOverPS_SessionsInd();

		//!Function to set values
		/*!		Function to set ENUM type for datatype IMS_VoiceOverPS_SessionsInd
		*/
		bool setValue(IMS_VOICEOVERPS_SESSIONSIND val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype IMS_VoiceOverPS_SessionsInd
		*/
		IMS_VOICEOVERPS_SESSIONSIND getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype IMS_VoiceOverPS_SessionsInd
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype IMS_VoiceOverPS_SessionsInd
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype IMS_VoiceOverPS_SessionsInd
		*/
		int Display(int tab);

};
typedef enum _tags_InbandInfo
{
	InbandInfo_MESSAGEID	=  1 << 0,
	InbandInfo_NUMBEROFREPETITIONS	=  1 << 1,
	InbandInfo_DURATION	=  1 << 2,
	InbandInfo_INTERVAL	=  1 << 3,
	InbandInfo_TAG_NULL	=  0x0000
}InbandInfo_tags;

		//! Class Definition
		/*!		ClassName is InbandInfo
		*/
class InbandInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		MessageID*		mmessageID;

		capstd::INTEGER*		mnumberOfRepetitions;

		capstd::INTEGER*		mduration;

		capstd::INTEGER*		minterval;


	public:
		InbandInfo();

		~InbandInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set MessageID type of argument messageID for datatype InbandInfo
		*/
		bool setmessageID(MessageID* messageID);

		//! Function to set values
		/*!		Function to set MessageID type of argument messageID for datatype InbandInfo
		*/
		MessageID* setmessageID();

		//! Function to get values
		/*!		Function to set MessageID type of argument messageID for datatype InbandInfo
		Throws exception of which type and Summary of Exception
		*/
		MessageID* getmessageID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument numberOfRepetitions for datatype InbandInfo
		*/
		bool setnumberOfRepetitions(capstd::INTEGER* numberOfRepetitions);

		//! Function to set values
		/*!		Function to set INTEGER type of argument numberOfRepetitions for datatype InbandInfo
		*/
		capstd::INTEGER* setnumberOfRepetitions();

		//! Function to get values
		/*!		Function to set INTEGER type of argument numberOfRepetitions for datatype InbandInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getnumberOfRepetitions() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype InbandInfo
		*/
		bool setduration(capstd::INTEGER* duration);

		//! Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype InbandInfo
		*/
		capstd::INTEGER* setduration();

		//! Function to get values
		/*!		Function to set INTEGER type of argument duration for datatype InbandInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getduration() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument interval for datatype InbandInfo
		*/
		bool setinterval(capstd::INTEGER* interval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument interval for datatype InbandInfo
		*/
		capstd::INTEGER* setinterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument interval for datatype InbandInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getinterval() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype InbandInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype InbandInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype InbandInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags InbandInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_InformationToSend
{
	InformationToSend_INBANDINFO	=  1 << 0,
	InformationToSend_TONE	=  1 << 1,
	InformationToSend_TAG_NULL	=  0x0000
}InformationToSend_tags;

		//! Class Definition
		/*!		ClassName is InformationToSend
		*/
class InformationToSend
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		InbandInfo*		minbandInfo;

		Tone*		mtone;


	public:
		InformationToSend();

		~InformationToSend();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set InbandInfo type of argument inbandInfo for datatype InformationToSend
		*/
		bool setinbandInfo(InbandInfo* inbandInfo);

		//! Function to set values
		/*!		Function to set InbandInfo type of argument inbandInfo for datatype InformationToSend
		*/
		InbandInfo* setinbandInfo();

		//! Function to get values
		/*!		Function to set InbandInfo type of argument inbandInfo for datatype InformationToSend
		Throws exception of which type and Summary of Exception
		*/
		InbandInfo* getinbandInfo() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Tone type of argument tone for datatype InformationToSend
		*/
		bool settone(Tone* tone);

		//! Function to set values
		/*!		Function to set Tone type of argument tone for datatype InformationToSend
		*/
		Tone* settone();

		//! Function to get values
		/*!		Function to set Tone type of argument tone for datatype InformationToSend
		Throws exception of which type and Summary of Exception
		*/
		Tone* gettone() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype InformationToSend
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype InformationToSend
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype InformationToSend
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags InformationToSend
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_InitialDPArgExtension
{
	InitialDPArgExtension_GMSCADDRESS	=  1 << 0,
	InitialDPArgExtension_TAG_NULL	=  0x0000
}InitialDPArgExtension_tags;

		//! Class Definition
		/*!		ClassName is InitialDPArgExtension
		*/
class InitialDPArgExtension
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mgmscAddress;


	public:
		InitialDPArgExtension();

		~InitialDPArgExtension();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument gmscAddress for datatype InitialDPArgExtension
		*/
		bool setgmscAddress(capstd::OctetString* gmscAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument gmscAddress for datatype InitialDPArgExtension
		*/
		capstd::OctetString* setgmscAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument gmscAddress for datatype InitialDPArgExtension
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgmscAddress() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype InitialDPArgExtension
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype InitialDPArgExtension
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype InitialDPArgExtension
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags InitialDPArgExtension
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(INITIATINGENTITY,
	(mobileStation, "mobileStation", 	 0X0000)
	(sgsn, "sgsn", 	 0X0001)
	(hlr, "hlr", 	 0X0002)
	(ggsn, "ggsn", 0X0003)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype InitiatingEntity
		*/
class InitiatingEntity
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		INITIATINGENTITY mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype InitiatingEntity
		*/
		InitiatingEntity();

		//!Destructor Function
		/*!		Destructor for datatype CGEncountered
		*/
		~InitiatingEntity();

		//!Function to set values
		/*!		Function to set ENUM type for datatype InitiatingEntity
		*/
		bool setValue(INITIATINGENTITY val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype InitiatingEntity
		*/
		INITIATINGENTITY getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype InitiatingEntity
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype InitiatingEntity
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype InitiatingEntity
		*/
		int Display(int tab);

};

class LIPA_AllowedAPNList
{
	private:

		vector<capstd::OctetString *> mParamList;

		capstd::OctetString*  mOctetString;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		LIPA_AllowedAPNList();

		~LIPA_AllowedAPNList();

		bool setOctetString(capstd::OctetString* octetString);

		capstd::OctetString* setOctetString();

		capstd::OctetString* setNewOctetString();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First OctetString type of argument OctetString for datatype LIPA_AllowedAPNList list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetString() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value OctetString type of argument OctetString for datatype LIPA_AllowedAPNList at given location
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getOctetStringAtLocation(unsigned location) ;//throw(const char*)

		capstd::OctetString* setNextOctetString();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next OctetString type of argument OctetString for datatype LIPA_AllowedAPNList list
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getNextOctetString() ;//throw(const char*)

		unsigned getNoOfOctetString();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};
typedef enum _tags_LegID
{
	LegID_SENDINGSIDEID	=  1 << 0,
	LegID_RECEIVINGSIDEID	=  1 << 1,
	LegID_TAG_NULL	=  0x0000
}LegID_tags;

		//! Class Definition
		/*!		ClassName is LegID
		*/
class LegID
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		msendingSideID;

		capstd::OctetString*		mreceivingSideID;


	public:
		LegID();

		~LegID();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument sendingSideID for datatype LegID
		*/
		bool setsendingSideID(capstd::OctetString* sendingSideID);

		//! Function to set values
		/*!		Function to set OctetString type of argument sendingSideID for datatype LegID
		*/
		capstd::OctetString* setsendingSideID();

		//! Function to get values
		/*!		Function to set OctetString type of argument sendingSideID for datatype LegID
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getsendingSideID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument receivingSideID for datatype LegID
		*/
		bool setreceivingSideID(capstd::OctetString* receivingSideID);

		//! Function to set values
		/*!		Function to set OctetString type of argument receivingSideID for datatype LegID
		*/
		capstd::OctetString* setreceivingSideID();

		//! Function to get values
		/*!		Function to set OctetString type of argument receivingSideID for datatype LegID
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getreceivingSideID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype LegID
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype LegID
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LegID
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags LegID
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_LocationInformation
{
	LocationInformation_AGEOFLOCATIONINFORMATION	=  1 << 0,
	LocationInformation_GEOGRAPHICALINFORMATION	=  1 << 1,
	LocationInformation_VLR_NUMBER	=  1 << 2,
	LocationInformation_LOCATIONNUMBER	=  1 << 3,
	LocationInformation_CELLGLOBALIDORSERVICEAREAIDORLAI	=  1 << 4,
	LocationInformation_EXTENSIONCONTAINER	=  1 << 5,
	LocationInformation_SELECTEDLSA_ID	=  1 << 6,
	LocationInformation_MSC_NUMBER	=  1 << 7,
	LocationInformation_GEODETICINFORMATION	=  1 << 8,
	LocationInformation_CURRENTLOCATIONRETRIEVED	=  1 << 9,
	LocationInformation_SAI_PRESENT	=  1 << 10,
	LocationInformation_LOCATIONINFORMATIONEPS	=  1 << 11,
	LocationInformation_USERCSGINFORMATION	=  1 << 12,
	LocationInformation_TAG_NULL	=  0x0000
}LocationInformation_tags;

		//! Class Definition
		/*!		ClassName is LocationInformation
		*/
class LocationInformation
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mageOfLocationInformation;

		capstd::OctetString*		mgeographicalInformation;

		capstd::OctetString*		mvlr_number;

		capstd::OctetString*		mlocationNumber;

		CellGlobalIdOrServiceAreaIdOrLAI*		mcellGlobalIdOrServiceAreaIdOrLAI;

		ExtensionContainer*		mextensionContainer;

		capstd::OctetString*		mselectedLSA_Id;

		capstd::OctetString*		mmsc_Number;

		capstd::OctetString*		mgeodeticInformation;

		bool 		mcurrentLocationRetrieved;

		bool 		mNullcurrentLocationRetrieved;

		bool 		msai_Present;

		bool 		mNullsai_Present;

		LocationInformationEPS*		mlocationInformationEPS;

		capstd::OctetString*		muserCSGInformation;


	public:
		LocationInformation();

		~LocationInformation();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformation
		*/
		bool setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation);

		//! Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformation
		*/
		capstd::INTEGER* setageOfLocationInformation();

		//! Function to get values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getageOfLocationInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformation
		*/
		bool setgeographicalInformation(capstd::OctetString* geographicalInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformation
		*/
		capstd::OctetString* setgeographicalInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeographicalInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument vlr_number for datatype LocationInformation
		*/
		bool setvlr_number(capstd::OctetString* vlr_number);

		//! Function to set values
		/*!		Function to set OctetString type of argument vlr_number for datatype LocationInformation
		*/
		capstd::OctetString* setvlr_number();

		//! Function to get values
		/*!		Function to set OctetString type of argument vlr_number for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getvlr_number() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument locationNumber for datatype LocationInformation
		*/
		bool setlocationNumber(capstd::OctetString* locationNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument locationNumber for datatype LocationInformation
		*/
		capstd::OctetString* setlocationNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument locationNumber for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getlocationNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformation
		*/
		bool setcellGlobalIdOrServiceAreaIdOrLAI(CellGlobalIdOrServiceAreaIdOrLAI* cellGlobalIdOrServiceAreaIdOrLAI);

		//! Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformation
		*/
		CellGlobalIdOrServiceAreaIdOrLAI* setcellGlobalIdOrServiceAreaIdOrLAI();

		//! Function to get values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		CellGlobalIdOrServiceAreaIdOrLAI* getcellGlobalIdOrServiceAreaIdOrLAI() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformation
		*/
		bool setextensionContainer(ExtensionContainer* extensionContainer);

		//! Function to set values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformation
		*/
		ExtensionContainer* setextensionContainer();

		//! Function to get values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		ExtensionContainer* getextensionContainer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument selectedLSA_Id for datatype LocationInformation
		*/
		bool setselectedLSA_Id(capstd::OctetString* selectedLSA_Id);

		//! Function to set values
		/*!		Function to set OctetString type of argument selectedLSA_Id for datatype LocationInformation
		*/
		capstd::OctetString* setselectedLSA_Id();

		//! Function to get values
		/*!		Function to set OctetString type of argument selectedLSA_Id for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getselectedLSA_Id() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument msc_Number for datatype LocationInformation
		*/
		bool setmsc_Number(capstd::OctetString* msc_Number);

		//! Function to set values
		/*!		Function to set OctetString type of argument msc_Number for datatype LocationInformation
		*/
		capstd::OctetString* setmsc_Number();

		//! Function to get values
		/*!		Function to set OctetString type of argument msc_Number for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmsc_Number() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformation
		*/
		bool setgeodeticInformation(capstd::OctetString* geodeticInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformation
		*/
		capstd::OctetString* setgeodeticInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeodeticInformation() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformation
		*/
		bool setcurrentLocationRetrieved(bool currentLocationRetrieved);

		//! Function to set new values
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformation
		*/
		bool* setcurrentLocationRetrieved();

		//! Function to get values
		/*!		Function to get NULL type of argument currentLocationRetrieved for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		bool getcurrentLocationRetrieved();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument sai_Present for datatype LocationInformation
		*/
		bool setsai_Present(bool sai_Present);

		//! Function to set new values
		/*!		Function to set NULL type of argument sai_Present for datatype LocationInformation
		*/
		bool* setsai_Present();

		//! Function to get values
		/*!		Function to get NULL type of argument sai_Present for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		bool getsai_Present();

		//!Function to set values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype LocationInformation
		*/
		bool setlocationInformationEPS(LocationInformationEPS* locationInformationEPS);

		//! Function to set values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype LocationInformation
		*/
		LocationInformationEPS* setlocationInformationEPS();

		//! Function to get values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		LocationInformationEPS* getlocationInformationEPS() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformation
		*/
		bool setuserCSGInformation(capstd::OctetString* userCSGInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformation
		*/
		capstd::OctetString* setuserCSGInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getuserCSGInformation() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype LocationInformation
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype LocationInformation
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LocationInformation
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags LocationInformation
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_LocationInformationEPS
{
	LocationInformationEPS_E_UTRANCELLGLOBALIDENTITY	=  1 << 0,
	LocationInformationEPS_TRACKINGAREAIDENTITY	=  1 << 1,
	LocationInformationEPS_EXTENSIONCONTAINER	=  1 << 2,
	LocationInformationEPS_GEOGRAPHICALINFORMATION	=  1 << 3,
	LocationInformationEPS_GEODETICINFORMATION	=  1 << 4,
	LocationInformationEPS_CURRENTLOCATIONRETRIEVED	=  1 << 5,
	LocationInformationEPS_AGEOFLOCATIONINFORMATION	=  1 << 6,
	LocationInformationEPS_MME_NAME	=  1 << 7,
	LocationInformationEPS_TAG_NULL	=  0x0000
}LocationInformationEPS_tags;

		//! Class Definition
		/*!		ClassName is LocationInformationEPS
		*/
class LocationInformationEPS
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		me_utranCellGlobalIdentity;

		capstd::OctetString*		mtrackingAreaIdentity;

		ExtensionContainer*		mextensionContainer;

		capstd::OctetString*		mgeographicalInformation;

		capstd::OctetString*		mgeodeticInformation;

		bool 		mcurrentLocationRetrieved;

		bool 		mNullcurrentLocationRetrieved;

		capstd::INTEGER*		mageOfLocationInformation;

		capstd::OctetString*		mmme_Name;


	public:
		LocationInformationEPS();

		~LocationInformationEPS();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument e_utranCellGlobalIdentity for datatype LocationInformationEPS
		*/
		bool sete_utranCellGlobalIdentity(capstd::OctetString* e_utranCellGlobalIdentity);

		//! Function to set values
		/*!		Function to set OctetString type of argument e_utranCellGlobalIdentity for datatype LocationInformationEPS
		*/
		capstd::OctetString* sete_utranCellGlobalIdentity();

		//! Function to get values
		/*!		Function to set OctetString type of argument e_utranCellGlobalIdentity for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* gete_utranCellGlobalIdentity() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument trackingAreaIdentity for datatype LocationInformationEPS
		*/
		bool settrackingAreaIdentity(capstd::OctetString* trackingAreaIdentity);

		//! Function to set values
		/*!		Function to set OctetString type of argument trackingAreaIdentity for datatype LocationInformationEPS
		*/
		capstd::OctetString* settrackingAreaIdentity();

		//! Function to get values
		/*!		Function to set OctetString type of argument trackingAreaIdentity for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* gettrackingAreaIdentity() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformationEPS
		*/
		bool setextensionContainer(ExtensionContainer* extensionContainer);

		//! Function to set values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformationEPS
		*/
		ExtensionContainer* setextensionContainer();

		//! Function to get values
		/*!		Function to set ExtensionContainer type of argument extensionContainer for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		ExtensionContainer* getextensionContainer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationEPS
		*/
		bool setgeographicalInformation(capstd::OctetString* geographicalInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationEPS
		*/
		capstd::OctetString* setgeographicalInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeographicalInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationEPS
		*/
		bool setgeodeticInformation(capstd::OctetString* geodeticInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationEPS
		*/
		capstd::OctetString* setgeodeticInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeodeticInformation() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformationEPS
		*/
		bool setcurrentLocationRetrieved(bool currentLocationRetrieved);

		//! Function to set new values
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformationEPS
		*/
		bool* setcurrentLocationRetrieved();

		//! Function to get values
		/*!		Function to get NULL type of argument currentLocationRetrieved for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		bool getcurrentLocationRetrieved();

		//!Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationEPS
		*/
		bool setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation);

		//! Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationEPS
		*/
		capstd::INTEGER* setageOfLocationInformation();

		//! Function to get values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getageOfLocationInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument mme_Name for datatype LocationInformationEPS
		*/
		bool setmme_Name(capstd::OctetString* mme_Name);

		//! Function to set values
		/*!		Function to set OctetString type of argument mme_Name for datatype LocationInformationEPS
		*/
		capstd::OctetString* setmme_Name();

		//! Function to get values
		/*!		Function to set OctetString type of argument mme_Name for datatype LocationInformationEPS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmme_Name() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype LocationInformationEPS
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype LocationInformationEPS
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LocationInformationEPS
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags LocationInformationEPS
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_LocationInformationGPRS
{
	LocationInformationGPRS_CELLGLOBALIDORSERVICEAREAIDORLAI	=  1 << 0,
	LocationInformationGPRS_ROUTEINGAREAIDENTITY	=  1 << 1,
	LocationInformationGPRS_GEOGRAPHICALINFORMATION	=  1 << 2,
	LocationInformationGPRS_SGSN_NUMBER	=  1 << 3,
	LocationInformationGPRS_SELECTEDLSAIDENTITY	=  1 << 4,
	LocationInformationGPRS_EXTENSIONCONTAINER	=  1 << 5,
	LocationInformationGPRS_SAI_PRESENT	=  1 << 6,
	LocationInformationGPRS_GEODETICINFORMATION	=  1 << 7,
	LocationInformationGPRS_CURRENTLOCATIONRETRIEVED	=  1 << 8,
	LocationInformationGPRS_AGEOFLOCATIONINFORMATION	=  1 << 9,
	LocationInformationGPRS_USERCSGINFORMATION	=  1 << 10,
	LocationInformationGPRS_TAG_NULL	=  0x0000
}LocationInformationGPRS_tags;

		//! Class Definition
		/*!		ClassName is LocationInformationGPRS
		*/
class LocationInformationGPRS
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		CellGlobalIdOrServiceAreaIdOrLAI*		mcellGlobalIdOrServiceAreaIdOrLAI;

		capstd::OctetString*		mrouteingAreaIdentity;

		capstd::OctetString*		mgeographicalInformation;

		capstd::OctetString*		msgsn_Number;

		capstd::OctetString*		mselectedLSAIdentity;

		capstd::GENERIC*		mextensionContainer;

		bool 		msai_Present;

		bool 		mNullsai_Present;

		capstd::OctetString*		mgeodeticInformation;

		bool 		mcurrentLocationRetrieved;

		bool 		mNullcurrentLocationRetrieved;

		capstd::INTEGER*		mageOfLocationInformation;

		capstd::OctetString*		muserCSGInformation;


	public:
		LocationInformationGPRS();

		~LocationInformationGPRS();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformationGPRS
		*/
		bool setcellGlobalIdOrServiceAreaIdOrLAI(CellGlobalIdOrServiceAreaIdOrLAI* cellGlobalIdOrServiceAreaIdOrLAI);

		//! Function to set values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformationGPRS
		*/
		CellGlobalIdOrServiceAreaIdOrLAI* setcellGlobalIdOrServiceAreaIdOrLAI();

		//! Function to get values
		/*!		Function to set CellGlobalIdOrServiceAreaIdOrLAI type of argument cellGlobalIdOrServiceAreaIdOrLAI for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		CellGlobalIdOrServiceAreaIdOrLAI* getcellGlobalIdOrServiceAreaIdOrLAI() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument routeingAreaIdentity for datatype LocationInformationGPRS
		*/
		bool setrouteingAreaIdentity(capstd::OctetString* routeingAreaIdentity);

		//! Function to set values
		/*!		Function to set OctetString type of argument routeingAreaIdentity for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setrouteingAreaIdentity();

		//! Function to get values
		/*!		Function to set OctetString type of argument routeingAreaIdentity for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getrouteingAreaIdentity() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationGPRS
		*/
		bool setgeographicalInformation(capstd::OctetString* geographicalInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setgeographicalInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geographicalInformation for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeographicalInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype LocationInformationGPRS
		*/
		bool setsgsn_Number(capstd::OctetString* sgsn_Number);

		//! Function to set values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setsgsn_Number();

		//! Function to get values
		/*!		Function to set OctetString type of argument sgsn_Number for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getsgsn_Number() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument selectedLSAIdentity for datatype LocationInformationGPRS
		*/
		bool setselectedLSAIdentity(capstd::OctetString* selectedLSAIdentity);

		//! Function to set values
		/*!		Function to set OctetString type of argument selectedLSAIdentity for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setselectedLSAIdentity();

		//! Function to get values
		/*!		Function to set OctetString type of argument selectedLSAIdentity for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getselectedLSAIdentity() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype LocationInformationGPRS
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype LocationInformationGPRS
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument sai_Present for datatype LocationInformationGPRS
		*/
		bool setsai_Present(bool sai_Present);

		//! Function to set new values
		/*!		Function to set NULL type of argument sai_Present for datatype LocationInformationGPRS
		*/
		bool* setsai_Present();

		//! Function to get values
		/*!		Function to get NULL type of argument sai_Present for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		bool getsai_Present();

		//!Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationGPRS
		*/
		bool setgeodeticInformation(capstd::OctetString* geodeticInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setgeodeticInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument geodeticInformation for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getgeodeticInformation() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformationGPRS
		*/
		bool setcurrentLocationRetrieved(bool currentLocationRetrieved);

		//! Function to set new values
		/*!		Function to set NULL type of argument currentLocationRetrieved for datatype LocationInformationGPRS
		*/
		bool* setcurrentLocationRetrieved();

		//! Function to get values
		/*!		Function to get NULL type of argument currentLocationRetrieved for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		bool getcurrentLocationRetrieved();

		//!Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationGPRS
		*/
		bool setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation);

		//! Function to set values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationGPRS
		*/
		capstd::INTEGER* setageOfLocationInformation();

		//! Function to get values
		/*!		Function to set INTEGER type of argument ageOfLocationInformation for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getageOfLocationInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformationGPRS
		*/
		bool setuserCSGInformation(capstd::OctetString* userCSGInformation);

		//! Function to set values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformationGPRS
		*/
		capstd::OctetString* setuserCSGInformation();

		//! Function to get values
		/*!		Function to set OctetString type of argument userCSGInformation for datatype LocationInformationGPRS
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getuserCSGInformation() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype LocationInformationGPRS
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype LocationInformationGPRS
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype LocationInformationGPRS
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags LocationInformationGPRS
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_MNPInfoRes
{
	MNPInfoRes_ROUTEINGNUMBER	=  1 << 0,
	MNPInfoRes_IMSI	=  1 << 1,
	MNPInfoRes_MSISDN	=  1 << 2,
	MNPInfoRes_NUMBERPORTABILITYSTATUS	=  1 << 3,
	MNPInfoRes_EXTENSIONCONTAINER	=  1 << 4,
	MNPInfoRes_TAG_NULL	=  0x0000
}MNPInfoRes_tags;

		//! Class Definition
		/*!		ClassName is MNPInfoRes
		*/
class MNPInfoRes
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mrouteingNumber;

		capstd::IMSI*		mimsi;

		capstd::OctetString*		mmsisdn;

		NumberPortabilityStatus*		mnumberPortabilityStatus;

		capstd::GENERIC*		mextensionContainer;


	public:
		MNPInfoRes();

		~MNPInfoRes();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument routeingNumber for datatype MNPInfoRes
		*/
		bool setrouteingNumber(capstd::OctetString* routeingNumber);

		//! Function to set values
		/*!		Function to set OctetString type of argument routeingNumber for datatype MNPInfoRes
		*/
		capstd::OctetString* setrouteingNumber();

		//! Function to get values
		/*!		Function to set OctetString type of argument routeingNumber for datatype MNPInfoRes
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getrouteingNumber() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set IMSI type of argument imsi for datatype MNPInfoRes
		*/
		bool setimsi(capstd::IMSI* imsi);

		//! Function to set values
		/*!		Function to set IMSI type of argument imsi for datatype MNPInfoRes
		*/
		capstd::IMSI* setimsi();

		//! Function to get values
		/*!		Function to set IMSI type of argument imsi for datatype MNPInfoRes
		Throws exception of which type and Summary of Exception
		*/
		capstd::IMSI* getimsi() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument msisdn for datatype MNPInfoRes
		*/
		bool setmsisdn(capstd::OctetString* msisdn);

		//! Function to set values
		/*!		Function to set OctetString type of argument msisdn for datatype MNPInfoRes
		*/
		capstd::OctetString* setmsisdn();

		//! Function to get values
		/*!		Function to set OctetString type of argument msisdn for datatype MNPInfoRes
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmsisdn() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set NumberPortabilityStatus type of argument numberPortabilityStatus for datatype MNPInfoRes
		*/
		bool setnumberPortabilityStatus(NumberPortabilityStatus* numberPortabilityStatus);

		//! Function to set values
		/*!		Function to set NumberPortabilityStatus type of argument numberPortabilityStatus for datatype MNPInfoRes
		*/
		NumberPortabilityStatus* setnumberPortabilityStatus();

		//! Function to get values
		/*!		Function to set NumberPortabilityStatus type of argument numberPortabilityStatus for datatype MNPInfoRes
		Throws exception of which type and Summary of Exception
		*/
		NumberPortabilityStatus* getnumberPortabilityStatus() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype MNPInfoRes
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype MNPInfoRes
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype MNPInfoRes
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype MNPInfoRes
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype MNPInfoRes
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MNPInfoRes
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags MNPInfoRes
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_MessageID
{
	MessageID_ELEMENTARYMESSAGEID	=  1 << 0,
	MessageID_TEXT	=  1 << 1,
	MessageID_VARIABLEMESSAGE	=  1 << 2,
	MessageID_TAG_NULL	=  0x0000
}MessageID_tags;

		//! Class Definition
		/*!		ClassName is MessageID
		*/
class MessageID
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		melementaryMessageID;

		Text*		mtext;

		VariableMessage*		mvariableMessage;


	public:
		MessageID();

		~MessageID();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype MessageID
		*/
		bool setelementaryMessageID(capstd::INTEGER* elementaryMessageID);

		//! Function to set values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype MessageID
		*/
		capstd::INTEGER* setelementaryMessageID();

		//! Function to get values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype MessageID
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getelementaryMessageID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Text type of argument text for datatype MessageID
		*/
		bool settext(Text* text);

		//! Function to set values
		/*!		Function to set Text type of argument text for datatype MessageID
		*/
		Text* settext();

		//! Function to get values
		/*!		Function to set Text type of argument text for datatype MessageID
		Throws exception of which type and Summary of Exception
		*/
		Text* gettext() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set VariableMessage type of argument variableMessage for datatype MessageID
		*/
		bool setvariableMessage(VariableMessage* variableMessage);

		//! Function to set values
		/*!		Function to set VariableMessage type of argument variableMessage for datatype MessageID
		*/
		VariableMessage* setvariableMessage();

		//! Function to get values
		/*!		Function to set VariableMessage type of argument variableMessage for datatype MessageID
		Throws exception of which type and Summary of Exception
		*/
		VariableMessage* getvariableMessage() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype MessageID
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype MessageID
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MessageID
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags MessageID
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(MESSAGETYPE,
	(request, "request", 	 0X0000)
	(notification, "notification", 0X0001)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype MessageType
		*/
class MessageType
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		MESSAGETYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype MessageType
		*/
		MessageType();

		//!Destructor Function
		/*!		Destructor for datatype VariableMessage
		*/
		~MessageType();

		//!Function to set values
		/*!		Function to set ENUM type for datatype MessageType
		*/
		bool setValue(MESSAGETYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype MessageType
		*/
		MESSAGETYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype MessageType
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype MessageType
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype MessageType
		*/
		int Display(int tab);

};
typedef enum _tags_MiscCallInfo
{
	MiscCallInfo_MESSAGETYPE	=  1 << 0,
	MiscCallInfo_TAG_NULL	=  0x0000
}MiscCallInfo_tags;

		//! Class Definition
		/*!		ClassName is MiscCallInfo
		*/
class MiscCallInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		MessageType*		mmessageType;


	public:
		MiscCallInfo();

		~MiscCallInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set MessageType type of argument messageType for datatype MiscCallInfo
		*/
		bool setmessageType(MessageType* messageType);

		//! Function to set values
		/*!		Function to set MessageType type of argument messageType for datatype MiscCallInfo
		*/
		MessageType* setmessageType();

		//! Function to get values
		/*!		Function to set MessageType type of argument messageType for datatype MiscCallInfo
		Throws exception of which type and Summary of Exception
		*/
		MessageType* getmessageType() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype MiscCallInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype MiscCallInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MiscCallInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags MiscCallInfo
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(MONITORMODE,
	(interrupted, "interrupted", 	 0X0000)
	(notifyAndContinue, "notifyAndContinue", 	 0X0001)
	(transparent, "transparent", 0X0002)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype MonitorMode
		*/
class MonitorMode
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		MONITORMODE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype MonitorMode
		*/
		MonitorMode();

		//!Destructor Function
		/*!		Destructor for datatype NumberPortabilityStatus
		*/
		~MonitorMode();

		//!Function to set values
		/*!		Function to set ENUM type for datatype MonitorMode
		*/
		bool setValue(MONITORMODE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype MonitorMode
		*/
		MONITORMODE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype MonitorMode
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype MonitorMode
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype MonitorMode
		*/
		int Display(int tab);

};

TSS_ENUM(NOTREACHABLEREASON,
	(msPurged, "msPurged", 	 0X0000)
	(imsiDetached, "imsiDetached", 	 0X0001)
	(restrictedArea, "restrictedArea", 	 0X0002)
	(notRegistered, "notRegistered", 0X0003)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype NotReachableReason
		*/
class NotReachableReason
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		NOTREACHABLEREASON mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype NotReachableReason
		*/
		NotReachableReason();

		//!Destructor Function
		/*!		Destructor for datatype GENERIC
		*/
		~NotReachableReason();

		//!Function to set values
		/*!		Function to set ENUM type for datatype NotReachableReason
		*/
		bool setValue(NOTREACHABLEREASON val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype NotReachableReason
		*/
		NOTREACHABLEREASON getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype NotReachableReason
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype NotReachableReason
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype NotReachableReason
		*/
		int Display(int tab);

};

TSS_ENUM(NUMBERPORTABILITYSTATUS,
	(notKnownToBePorted, "notKnownToBePorted", 	 0X0000)
	(ownNumberPortedOut, "ownNumberPortedOut", 	 0X0001)
	(foreignNumberPortedToForeignNetwork, "foreignNumberPortedToForeignNetwork", 	 0X0002)
	(ownNumberNotPortedOut, "ownNumberNotPortedOut", 	 0X0004)
	(foreignNumberPortedIn, "foreignNumberPortedIn", 0X0005)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype NumberPortabilityStatus
		*/
class NumberPortabilityStatus
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		NUMBERPORTABILITYSTATUS mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype NumberPortabilityStatus
		*/
		NumberPortabilityStatus();

		//!Destructor Function
		/*!		Destructor for datatype GENERIC
		*/
		~NumberPortabilityStatus();

		//!Function to set values
		/*!		Function to set ENUM type for datatype NumberPortabilityStatus
		*/
		bool setValue(NUMBERPORTABILITYSTATUS val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype NumberPortabilityStatus
		*/
		NUMBERPORTABILITYSTATUS getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype NumberPortabilityStatus
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype NumberPortabilityStatus
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype NumberPortabilityStatus
		*/
		int Display(int tab);

};
typedef enum _tags_OAnswerSpecificInfo
{
	OAnswerSpecificInfo_DESTINATIONADDRESS	=  1 << 0,
	OAnswerSpecificInfo_OR_CALL	=  1 << 1,
	OAnswerSpecificInfo_FORWARDEDCALL	=  1 << 2,
	OAnswerSpecificInfo_TAG_NULL	=  0x0000
}OAnswerSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is OAnswerSpecificInfo
		*/
class OAnswerSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mdestinationAddress;

		bool 		mor_Call;

		bool 		mNullor_Call;

		bool 		mforwardedCall;

		bool 		mNullforwardedCall;


	public:
		OAnswerSpecificInfo();

		~OAnswerSpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument destinationAddress for datatype OAnswerSpecificInfo
		*/
		bool setdestinationAddress(capstd::OctetString* destinationAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument destinationAddress for datatype OAnswerSpecificInfo
		*/
		capstd::OctetString* setdestinationAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument destinationAddress for datatype OAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getdestinationAddress() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument or_Call for datatype OAnswerSpecificInfo
		*/
		bool setor_Call(bool or_Call);

		//! Function to set new values
		/*!		Function to set NULL type of argument or_Call for datatype OAnswerSpecificInfo
		*/
		bool* setor_Call();

		//! Function to get values
		/*!		Function to get NULL type of argument or_Call for datatype OAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getor_Call();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument forwardedCall for datatype OAnswerSpecificInfo
		*/
		bool setforwardedCall(bool forwardedCall);

		//! Function to set new values
		/*!		Function to set NULL type of argument forwardedCall for datatype OAnswerSpecificInfo
		*/
		bool* setforwardedCall();

		//! Function to get values
		/*!		Function to get NULL type of argument forwardedCall for datatype OAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getforwardedCall();

		//! Function to Decode
		/*!		Function to Decode datatype OAnswerSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype OAnswerSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype OAnswerSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags OAnswerSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_OCalledPartyBusySpecificInfo
{
	OCalledPartyBusySpecificInfo_BUSYCAUSE	=  1 << 0,
	OCalledPartyBusySpecificInfo_TAG_NULL	=  0x0000
}OCalledPartyBusySpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is OCalledPartyBusySpecificInfo
		*/
class OCalledPartyBusySpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mbusyCause;


	public:
		OCalledPartyBusySpecificInfo();

		~OCalledPartyBusySpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument busyCause for datatype OCalledPartyBusySpecificInfo
		*/
		bool setbusyCause(capstd::GENERIC* busyCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument busyCause for datatype OCalledPartyBusySpecificInfo
		*/
		capstd::GENERIC* setbusyCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument busyCause for datatype OCalledPartyBusySpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getbusyCause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype OCalledPartyBusySpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype OCalledPartyBusySpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype OCalledPartyBusySpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags OCalledPartyBusySpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ODisconnectSpecificInfo
{
	ODisconnectSpecificInfo_RELEASECAUSE	=  1 << 0,
	ODisconnectSpecificInfo_TAG_NULL	=  0x0000
}ODisconnectSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is ODisconnectSpecificInfo
		*/
class ODisconnectSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mreleaseCause;


	public:
		ODisconnectSpecificInfo();

		~ODisconnectSpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype ODisconnectSpecificInfo
		*/
		bool setreleaseCause(capstd::GENERIC* releaseCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype ODisconnectSpecificInfo
		*/
		capstd::GENERIC* setreleaseCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument releaseCause for datatype ODisconnectSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getreleaseCause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ODisconnectSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ODisconnectSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ODisconnectSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ODisconnectSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_PDP_ContextInfo
{
	PDP_ContextInfo_PDP_CONTEXTIDENTIFIER	=  1 << 0,
	PDP_ContextInfo_PDP_CONTEXTACTIVE	=  1 << 1,
	PDP_ContextInfo_PDP_TYPE	=  1 << 2,
	PDP_ContextInfo_PDP_ADDRESS	=  1 << 3,
	PDP_ContextInfo_APN_SUBSCRIBED	=  1 << 4,
	PDP_ContextInfo_APN_INUSE	=  1 << 5,
	PDP_ContextInfo_NSAPI	=  1 << 6,
	PDP_ContextInfo_TRANSACTIONID	=  1 << 7,
	PDP_ContextInfo_TEID_FORGNANDGP	=  1 << 8,
	PDP_ContextInfo_TEID_FORIU	=  1 << 9,
	PDP_ContextInfo_GGSN_ADDRESS	=  1 << 10,
	PDP_ContextInfo_QOS_SUBSCRIBED	=  1 << 11,
	PDP_ContextInfo_QOS_REQUESTED	=  1 << 12,
	PDP_ContextInfo_QOS_NEGOTIATED	=  1 << 13,
	PDP_ContextInfo_CHARGINGID	=  1 << 14,
	PDP_ContextInfo_CHARGINGCHARACTERISTICS	=  1 << 15,
	PDP_ContextInfo_RNC_ADDRESS	=  1 << 16,
	PDP_ContextInfo_EXTENSIONCONTAINER	=  1 << 17,
	PDP_ContextInfo_QOS2_SUBSCRIBED	=  1 << 18,
	PDP_ContextInfo_QOS2_REQUESTED	=  1 << 19,
	PDP_ContextInfo_QOS2_NEGOTIATED	=  1 << 20,
	PDP_ContextInfo_QOS3_SUBSCRIBED	=  1 << 21,
	PDP_ContextInfo_QOS3_REQUESTED	=  1 << 22,
	PDP_ContextInfo_QOS3_NEGOTIATED	=  1 << 23,
	PDP_ContextInfo_QOS4_SUBSCRIBED	=  1 << 24,
	PDP_ContextInfo_QOS4_REQUESTED	=  1 << 25,
	PDP_ContextInfo_QOS4_NEGOTIATED	=  1 << 26,
	PDP_ContextInfo_EXT_PDP_TYPE	=  1 << 27,
	PDP_ContextInfo_EXT_PDP_ADDRESS	=  1 << 28,
	PDP_ContextInfo_TAG_NULL	=  0x0000
}PDP_ContextInfo_tags;

		//! Class Definition
		/*!		ClassName is PDP_ContextInfo
		*/
class PDP_ContextInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mpdp_ContextIdentifier;

		bool 		mpdp_ContextActive;

		bool 		mNullpdp_ContextActive;

		capstd::OctetString*		mpdp_Type;

		capstd::OctetString*		mpdp_Address;

		capstd::OctetString*		mapn_Subscribed;

		capstd::OctetString*		mapn_InUse;

		capstd::INTEGER*		mnsapi;

		capstd::OctetString*		mtransactionId;

		capstd::OctetString*		mteid_ForGnAndGp;

		capstd::OctetString*		mteid_ForIu;

		capstd::OctetString*		mggsn_Address;

		capstd::OctetString*		mqos_Subscribed;

		capstd::OctetString*		mqos_Requested;

		capstd::OctetString*		mqos_Negotiated;

		capstd::OctetString*		mchargingId;

		capstd::OctetString*		mchargingCharacteristics;

		capstd::OctetString*		mrnc_Address;

		capstd::GENERIC*		mextensionContainer;

		capstd::OctetString*		mqos2_Subscribed;

		capstd::OctetString*		mqos2_Requested;

		capstd::OctetString*		mqos2_Negotiated;

		capstd::OctetString*		mqos3_Subscribed;

		capstd::OctetString*		mqos3_Requested;

		capstd::OctetString*		mqos3_Negotiated;

		capstd::OctetString*		mqos4_Subscribed;

		capstd::OctetString*		mqos4_Requested;

		capstd::OctetString*		mqos4_Negotiated;

		capstd::OctetString*		mext_pdp_Type;

		capstd::OctetString*		mext_pdp_Address;


	public:
		PDP_ContextInfo();

		~PDP_ContextInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument pdp_ContextIdentifier for datatype PDP_ContextInfo
		*/
		bool setpdp_ContextIdentifier(capstd::INTEGER* pdp_ContextIdentifier);

		//! Function to set values
		/*!		Function to set INTEGER type of argument pdp_ContextIdentifier for datatype PDP_ContextInfo
		*/
		capstd::INTEGER* setpdp_ContextIdentifier();

		//! Function to get values
		/*!		Function to set INTEGER type of argument pdp_ContextIdentifier for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getpdp_ContextIdentifier() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument pdp_ContextActive for datatype PDP_ContextInfo
		*/
		bool setpdp_ContextActive(bool pdp_ContextActive);

		//! Function to set new values
		/*!		Function to set NULL type of argument pdp_ContextActive for datatype PDP_ContextInfo
		*/
		bool* setpdp_ContextActive();

		//! Function to get values
		/*!		Function to get NULL type of argument pdp_ContextActive for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getpdp_ContextActive();

		//!Function to set values
		/*!		Function to set OctetString type of argument pdp_Type for datatype PDP_ContextInfo
		*/
		bool setpdp_Type(capstd::OctetString* pdp_Type);

		//! Function to set values
		/*!		Function to set OctetString type of argument pdp_Type for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setpdp_Type();

		//! Function to get values
		/*!		Function to set OctetString type of argument pdp_Type for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getpdp_Type() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument pdp_Address for datatype PDP_ContextInfo
		*/
		bool setpdp_Address(capstd::OctetString* pdp_Address);

		//! Function to set values
		/*!		Function to set OctetString type of argument pdp_Address for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setpdp_Address();

		//! Function to get values
		/*!		Function to set OctetString type of argument pdp_Address for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getpdp_Address() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument apn_Subscribed for datatype PDP_ContextInfo
		*/
		bool setapn_Subscribed(capstd::OctetString* apn_Subscribed);

		//! Function to set values
		/*!		Function to set OctetString type of argument apn_Subscribed for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setapn_Subscribed();

		//! Function to get values
		/*!		Function to set OctetString type of argument apn_Subscribed for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getapn_Subscribed() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument apn_InUse for datatype PDP_ContextInfo
		*/
		bool setapn_InUse(capstd::OctetString* apn_InUse);

		//! Function to set values
		/*!		Function to set OctetString type of argument apn_InUse for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setapn_InUse();

		//! Function to get values
		/*!		Function to set OctetString type of argument apn_InUse for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getapn_InUse() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument nsapi for datatype PDP_ContextInfo
		*/
		bool setnsapi(capstd::INTEGER* nsapi);

		//! Function to set values
		/*!		Function to set INTEGER type of argument nsapi for datatype PDP_ContextInfo
		*/
		capstd::INTEGER* setnsapi();

		//! Function to get values
		/*!		Function to set INTEGER type of argument nsapi for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getnsapi() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument transactionId for datatype PDP_ContextInfo
		*/
		bool settransactionId(capstd::OctetString* transactionId);

		//! Function to set values
		/*!		Function to set OctetString type of argument transactionId for datatype PDP_ContextInfo
		*/
		capstd::OctetString* settransactionId();

		//! Function to get values
		/*!		Function to set OctetString type of argument transactionId for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* gettransactionId() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument teid_ForGnAndGp for datatype PDP_ContextInfo
		*/
		bool setteid_ForGnAndGp(capstd::OctetString* teid_ForGnAndGp);

		//! Function to set values
		/*!		Function to set OctetString type of argument teid_ForGnAndGp for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setteid_ForGnAndGp();

		//! Function to get values
		/*!		Function to set OctetString type of argument teid_ForGnAndGp for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getteid_ForGnAndGp() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument teid_ForIu for datatype PDP_ContextInfo
		*/
		bool setteid_ForIu(capstd::OctetString* teid_ForIu);

		//! Function to set values
		/*!		Function to set OctetString type of argument teid_ForIu for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setteid_ForIu();

		//! Function to get values
		/*!		Function to set OctetString type of argument teid_ForIu for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getteid_ForIu() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ggsn_Address for datatype PDP_ContextInfo
		*/
		bool setggsn_Address(capstd::OctetString* ggsn_Address);

		//! Function to set values
		/*!		Function to set OctetString type of argument ggsn_Address for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setggsn_Address();

		//! Function to get values
		/*!		Function to set OctetString type of argument ggsn_Address for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getggsn_Address() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos_Subscribed for datatype PDP_ContextInfo
		*/
		bool setqos_Subscribed(capstd::OctetString* qos_Subscribed);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos_Subscribed for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos_Subscribed();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos_Subscribed for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos_Subscribed() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos_Requested for datatype PDP_ContextInfo
		*/
		bool setqos_Requested(capstd::OctetString* qos_Requested);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos_Requested for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos_Requested();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos_Requested for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos_Requested() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos_Negotiated for datatype PDP_ContextInfo
		*/
		bool setqos_Negotiated(capstd::OctetString* qos_Negotiated);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos_Negotiated for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos_Negotiated();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos_Negotiated for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos_Negotiated() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument chargingId for datatype PDP_ContextInfo
		*/
		bool setchargingId(capstd::OctetString* chargingId);

		//! Function to set values
		/*!		Function to set OctetString type of argument chargingId for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setchargingId();

		//! Function to get values
		/*!		Function to set OctetString type of argument chargingId for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getchargingId() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument chargingCharacteristics for datatype PDP_ContextInfo
		*/
		bool setchargingCharacteristics(capstd::OctetString* chargingCharacteristics);

		//! Function to set values
		/*!		Function to set OctetString type of argument chargingCharacteristics for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setchargingCharacteristics();

		//! Function to get values
		/*!		Function to set OctetString type of argument chargingCharacteristics for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getchargingCharacteristics() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument rnc_Address for datatype PDP_ContextInfo
		*/
		bool setrnc_Address(capstd::OctetString* rnc_Address);

		//! Function to set values
		/*!		Function to set OctetString type of argument rnc_Address for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setrnc_Address();

		//! Function to get values
		/*!		Function to set OctetString type of argument rnc_Address for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getrnc_Address() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype PDP_ContextInfo
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype PDP_ContextInfo
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos2_Subscribed for datatype PDP_ContextInfo
		*/
		bool setqos2_Subscribed(capstd::OctetString* qos2_Subscribed);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos2_Subscribed for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos2_Subscribed();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos2_Subscribed for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos2_Subscribed() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos2_Requested for datatype PDP_ContextInfo
		*/
		bool setqos2_Requested(capstd::OctetString* qos2_Requested);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos2_Requested for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos2_Requested();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos2_Requested for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos2_Requested() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos2_Negotiated for datatype PDP_ContextInfo
		*/
		bool setqos2_Negotiated(capstd::OctetString* qos2_Negotiated);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos2_Negotiated for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos2_Negotiated();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos2_Negotiated for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos2_Negotiated() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos3_Subscribed for datatype PDP_ContextInfo
		*/
		bool setqos3_Subscribed(capstd::OctetString* qos3_Subscribed);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos3_Subscribed for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos3_Subscribed();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos3_Subscribed for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos3_Subscribed() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos3_Requested for datatype PDP_ContextInfo
		*/
		bool setqos3_Requested(capstd::OctetString* qos3_Requested);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos3_Requested for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos3_Requested();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos3_Requested for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos3_Requested() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos3_Negotiated for datatype PDP_ContextInfo
		*/
		bool setqos3_Negotiated(capstd::OctetString* qos3_Negotiated);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos3_Negotiated for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos3_Negotiated();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos3_Negotiated for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos3_Negotiated() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos4_Subscribed for datatype PDP_ContextInfo
		*/
		bool setqos4_Subscribed(capstd::OctetString* qos4_Subscribed);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos4_Subscribed for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos4_Subscribed();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos4_Subscribed for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos4_Subscribed() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos4_Requested for datatype PDP_ContextInfo
		*/
		bool setqos4_Requested(capstd::OctetString* qos4_Requested);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos4_Requested for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos4_Requested();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos4_Requested for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos4_Requested() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument qos4_Negotiated for datatype PDP_ContextInfo
		*/
		bool setqos4_Negotiated(capstd::OctetString* qos4_Negotiated);

		//! Function to set values
		/*!		Function to set OctetString type of argument qos4_Negotiated for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setqos4_Negotiated();

		//! Function to get values
		/*!		Function to set OctetString type of argument qos4_Negotiated for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getqos4_Negotiated() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ext_pdp_Type for datatype PDP_ContextInfo
		*/
		bool setext_pdp_Type(capstd::OctetString* ext_pdp_Type);

		//! Function to set values
		/*!		Function to set OctetString type of argument ext_pdp_Type for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setext_pdp_Type();

		//! Function to get values
		/*!		Function to set OctetString type of argument ext_pdp_Type for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getext_pdp_Type() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ext_pdp_Address for datatype PDP_ContextInfo
		*/
		bool setext_pdp_Address(capstd::OctetString* ext_pdp_Address);

		//! Function to set values
		/*!		Function to set OctetString type of argument ext_pdp_Address for datatype PDP_ContextInfo
		*/
		capstd::OctetString* setext_pdp_Address();

		//! Function to get values
		/*!		Function to set OctetString type of argument ext_pdp_Address for datatype PDP_ContextInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getext_pdp_Address() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype PDP_ContextInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype PDP_ContextInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PDP_ContextInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags PDP_ContextInfo
		*/
		bool ValidateMandatory(char *errStr);

};

class PDP_ContextInfoList
{
	private:

		vector<PDP_ContextInfo *> mParamList;

		PDP_ContextInfo*  mPDP_ContextInfo;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		PDP_ContextInfoList();

		~PDP_ContextInfoList();

		bool setPDP_ContextInfo(PDP_ContextInfo* pDP_ContextInfo);

		PDP_ContextInfo* setPDP_ContextInfo();

		PDP_ContextInfo* setNewPDP_ContextInfo();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First PDP_ContextInfo type of argument PDP_ContextInfo for datatype PDP_ContextInfoList list
		Throws exception of which type and Summary of Exception
		*/
		PDP_ContextInfo* getPDP_ContextInfo() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value PDP_ContextInfo type of argument PDP_ContextInfo for datatype PDP_ContextInfoList at given location
		Throws exception of which type and Summary of Exception
		*/
		PDP_ContextInfo* getPDP_ContextInfoAtLocation(unsigned location) ;//throw(const char*)

		PDP_ContextInfo* setNextPDP_ContextInfo();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next PDP_ContextInfo type of argument PDP_ContextInfo for datatype PDP_ContextInfoList list
		Throws exception of which type and Summary of Exception
		*/
		PDP_ContextInfo* getNextPDP_ContextInfo() ;//throw(const char*)

		unsigned getNoOfPDP_ContextInfo();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};
typedef enum _tags_PS_SubscriberState
{
	PS_SubscriberState_NOTPROVIDEDFROMSGSNORMME	=  1 << 0,
	PS_SubscriberState_PS_DETACHED	=  1 << 1,
	PS_SubscriberState_PS_ATTACHEDNOTREACHABLEFORPAGING	=  1 << 2,
	PS_SubscriberState_PS_ATTACHEDREACHABLEFORPAGING	=  1 << 3,
	PS_SubscriberState_PS_PDP_ACTIVENOTREACHABLEFORPAGING	=  1 << 4,
	PS_SubscriberState_PS_PDP_ACTIVEREACHABLEFORPAGING	=  1 << 5,
	PS_SubscriberState_NETDETNOTREACHABLE	=  1 << 6,
	PS_SubscriberState_TAG_NULL	=  0x0000
}PS_SubscriberState_tags;

		//! Class Definition
		/*!		ClassName is PS_SubscriberState
		*/
class PS_SubscriberState
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bool 		mnotProvidedFromSGSNorMME;

		bool 		mNullnotProvidedFromSGSNorMME;

		bool 		mps_Detached;

		bool 		mNullps_Detached;

		bool 		mps_AttachedNotReachableForPaging;

		bool 		mNullps_AttachedNotReachableForPaging;

		bool 		mps_AttachedReachableForPaging;

		bool 		mNullps_AttachedReachableForPaging;

		PDP_ContextInfoList*		mps_PDP_ActiveNotReachableForPaging;

		PDP_ContextInfoList*		mps_PDP_ActiveReachableForPaging;

		NotReachableReason*		mnetDetNotReachable;


	public:
		PS_SubscriberState();

		~PS_SubscriberState();

		bool isPresent(int);

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument notProvidedFromSGSNorMME for datatype PS_SubscriberState
		*/
		bool setnotProvidedFromSGSNorMME(bool notProvidedFromSGSNorMME);

		//! Function to set new values
		/*!		Function to set NULL type of argument notProvidedFromSGSNorMME for datatype PS_SubscriberState
		*/
		bool* setnotProvidedFromSGSNorMME();

		//! Function to get values
		/*!		Function to get NULL type of argument notProvidedFromSGSNorMME for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getnotProvidedFromSGSNorMME();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument ps_Detached for datatype PS_SubscriberState
		*/
		bool setps_Detached(bool ps_Detached);

		//! Function to set new values
		/*!		Function to set NULL type of argument ps_Detached for datatype PS_SubscriberState
		*/
		bool* setps_Detached();

		//! Function to get values
		/*!		Function to get NULL type of argument ps_Detached for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getps_Detached();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument ps_AttachedNotReachableForPaging for datatype PS_SubscriberState
		*/
		bool setps_AttachedNotReachableForPaging(bool ps_AttachedNotReachableForPaging);

		//! Function to set new values
		/*!		Function to set NULL type of argument ps_AttachedNotReachableForPaging for datatype PS_SubscriberState
		*/
		bool* setps_AttachedNotReachableForPaging();

		//! Function to get values
		/*!		Function to get NULL type of argument ps_AttachedNotReachableForPaging for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getps_AttachedNotReachableForPaging();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument ps_AttachedReachableForPaging for datatype PS_SubscriberState
		*/
		bool setps_AttachedReachableForPaging(bool ps_AttachedReachableForPaging);

		//! Function to set new values
		/*!		Function to set NULL type of argument ps_AttachedReachableForPaging for datatype PS_SubscriberState
		*/
		bool* setps_AttachedReachableForPaging();

		//! Function to get values
		/*!		Function to get NULL type of argument ps_AttachedReachableForPaging for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getps_AttachedReachableForPaging();

		//!Function to set values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveNotReachableForPaging for datatype PS_SubscriberState
		*/
		bool setps_PDP_ActiveNotReachableForPaging(PDP_ContextInfoList* ps_PDP_ActiveNotReachableForPaging);

		//! Function to set values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveNotReachableForPaging for datatype PS_SubscriberState
		*/
		PDP_ContextInfoList* setps_PDP_ActiveNotReachableForPaging();

		//! Function to get values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveNotReachableForPaging for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		PDP_ContextInfoList* getps_PDP_ActiveNotReachableForPaging() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveReachableForPaging for datatype PS_SubscriberState
		*/
		bool setps_PDP_ActiveReachableForPaging(PDP_ContextInfoList* ps_PDP_ActiveReachableForPaging);

		//! Function to set values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveReachableForPaging for datatype PS_SubscriberState
		*/
		PDP_ContextInfoList* setps_PDP_ActiveReachableForPaging();

		//! Function to get values
		/*!		Function to set PDP_ContextInfoList type of argument ps_PDP_ActiveReachableForPaging for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		PDP_ContextInfoList* getps_PDP_ActiveReachableForPaging() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype PS_SubscriberState
		*/
		bool setnetDetNotReachable(NotReachableReason* netDetNotReachable);

		//! Function to set values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype PS_SubscriberState
		*/
		NotReachableReason* setnetDetNotReachable();

		//! Function to get values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype PS_SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		NotReachableReason* getnetDetNotReachable() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype PS_SubscriberState
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype PS_SubscriberState
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PS_SubscriberState
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags PS_SubscriberState
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_PrivateExtension
{
	PrivateExtension_EXTID	=  1 << 0,
	PrivateExtension_TAG_NULL	=  0x0000
}PrivateExtension_tags;

		//! Class Definition
		/*!		ClassName is PrivateExtension
		*/
class PrivateExtension
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mextId;


	public:
		PrivateExtension();

		~PrivateExtension();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument extId for datatype PrivateExtension
		*/
		bool setextId(capstd::OctetString* extId);

		//! Function to set values
		/*!		Function to set OctetString type of argument extId for datatype PrivateExtension
		*/
		capstd::OctetString* setextId();

		//! Function to get values
		/*!		Function to set OctetString type of argument extId for datatype PrivateExtension
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getextId() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype PrivateExtension
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype PrivateExtension
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PrivateExtension
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags PrivateExtension
		*/
		bool ValidateMandatory(char *errStr);

};

class PrivateExtensionList
{
	private:

		vector<PrivateExtension *> mParamList;

		PrivateExtension*  mPrivateExtension;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		PrivateExtensionList();

		~PrivateExtensionList();

		bool setPrivateExtension(PrivateExtension* privateExtension);

		PrivateExtension* setPrivateExtension();

		PrivateExtension* setNewPrivateExtension();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First PrivateExtension type of argument PrivateExtension for datatype PrivateExtensionList list
		Throws exception of which type and Summary of Exception
		*/
		PrivateExtension* getPrivateExtension() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value PrivateExtension type of argument PrivateExtension for datatype PrivateExtensionList at given location
		Throws exception of which type and Summary of Exception
		*/
		PrivateExtension* getPrivateExtensionAtLocation(unsigned location) ;//throw(const char*)

		PrivateExtension* setNextPrivateExtension();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next PrivateExtension type of argument PrivateExtension for datatype PrivateExtensionList list
		Throws exception of which type and Summary of Exception
		*/
		PrivateExtension* getNextPrivateExtension() ;//throw(const char*)

		unsigned getNoOfPrivateExtension();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};
typedef enum _tags_ReceivingSideID
{
	ReceivingSideID_RECEIVINGSIDEID	=  1 << 0,
	ReceivingSideID_TAG_NULL	=  0x0000
}ReceivingSideID_tags;

		//! Class Definition
		/*!		ClassName is ReceivingSideID
		*/
class ReceivingSideID
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mreceivingSideID;


	public:
		ReceivingSideID();

		~ReceivingSideID();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument receivingSideID for datatype ReceivingSideID
		*/
		bool setreceivingSideID(capstd::OctetString* receivingSideID);

		//! Function to set values
		/*!		Function to set OctetString type of argument receivingSideID for datatype ReceivingSideID
		*/
		capstd::OctetString* setreceivingSideID();

		//! Function to get values
		/*!		Function to set OctetString type of argument receivingSideID for datatype ReceivingSideID
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getreceivingSideID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ReceivingSideID
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ReceivingSideID
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReceivingSideID
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ReceivingSideID
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_RequestedInfo
{
	RequestedInfo_LOCATIONINFORMATION	=  1 << 0,
	RequestedInfo_SUBSCRIBERSTATE	=  1 << 1,
	RequestedInfo_EXTENSIONCONTAINER	=  1 << 2,
	RequestedInfo_CURRENTLOCATION	=  1 << 3,
	RequestedInfo_REQUESTEDDOMAIN	=  1 << 4,
	RequestedInfo_IMEI	=  1 << 5,
	RequestedInfo_MS_CLASSMARK	=  1 << 6,
	RequestedInfo_MNPREQUESTEDINFO	=  1 << 7,
	RequestedInfo_T_ADSDATA	=  1 << 8,
	RequestedInfo_REQUESTEDNODES	=  1 << 9,
	RequestedInfo_SERVINGNODEINDICATION	=  1 << 10,
	RequestedInfo_TAG_NULL	=  0x0000
}RequestedInfo_tags;

		//! Class Definition
		/*!		ClassName is RequestedInfo
		*/
class RequestedInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bool 		mlocationInformation;

		bool 		mNulllocationInformation;

		bool 		msubscriberState;

		bool 		mNullsubscriberState;

		capstd::GENERIC*		mextensionContainer;

		bool 		mcurrentLocation;

		bool 		mNullcurrentLocation;

		DomainType*		mrequestedDomain;

		bool 		mimei;

		bool 		mNullimei;

		bool 		mms_classmark;

		bool 		mNullms_classmark;

		bool 		mmnpRequestedInfo;

		bool 		mNullmnpRequestedInfo;

		bool 		mt_adsData;

		bool 		mNullt_adsData;

		RequestedNodes*		mrequestedNodes;

		bool 		mservingNodeIndication;

		bool 		mNullservingNodeIndication;


	public:
		RequestedInfo();

		~RequestedInfo();

		bool isPresent(int);

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument locationInformation for datatype RequestedInfo
		*/
		bool setlocationInformation(bool locationInformation);

		//! Function to set new values
		/*!		Function to set NULL type of argument locationInformation for datatype RequestedInfo
		*/
		bool* setlocationInformation();

		//! Function to get values
		/*!		Function to get NULL type of argument locationInformation for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getlocationInformation();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument subscriberState for datatype RequestedInfo
		*/
		bool setsubscriberState(bool subscriberState);

		//! Function to set new values
		/*!		Function to set NULL type of argument subscriberState for datatype RequestedInfo
		*/
		bool* setsubscriberState();

		//! Function to get values
		/*!		Function to get NULL type of argument subscriberState for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getsubscriberState();

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype RequestedInfo
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype RequestedInfo
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument currentLocation for datatype RequestedInfo
		*/
		bool setcurrentLocation(bool currentLocation);

		//! Function to set new values
		/*!		Function to set NULL type of argument currentLocation for datatype RequestedInfo
		*/
		bool* setcurrentLocation();

		//! Function to get values
		/*!		Function to get NULL type of argument currentLocation for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getcurrentLocation();

		//!Function to set values
		/*!		Function to set DomainType type of argument requestedDomain for datatype RequestedInfo
		*/
		bool setrequestedDomain(DomainType* requestedDomain);

		//! Function to set values
		/*!		Function to set DomainType type of argument requestedDomain for datatype RequestedInfo
		*/
		DomainType* setrequestedDomain();

		//! Function to get values
		/*!		Function to set DomainType type of argument requestedDomain for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		DomainType* getrequestedDomain() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument imei for datatype RequestedInfo
		*/
		bool setimei(bool imei);

		//! Function to set new values
		/*!		Function to set NULL type of argument imei for datatype RequestedInfo
		*/
		bool* setimei();

		//! Function to get values
		/*!		Function to get NULL type of argument imei for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getimei();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument ms_classmark for datatype RequestedInfo
		*/
		bool setms_classmark(bool ms_classmark);

		//! Function to set new values
		/*!		Function to set NULL type of argument ms_classmark for datatype RequestedInfo
		*/
		bool* setms_classmark();

		//! Function to get values
		/*!		Function to get NULL type of argument ms_classmark for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getms_classmark();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument mnpRequestedInfo for datatype RequestedInfo
		*/
		bool setmnpRequestedInfo(bool mnpRequestedInfo);

		//! Function to set new values
		/*!		Function to set NULL type of argument mnpRequestedInfo for datatype RequestedInfo
		*/
		bool* setmnpRequestedInfo();

		//! Function to get values
		/*!		Function to get NULL type of argument mnpRequestedInfo for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getmnpRequestedInfo();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument t_adsData for datatype RequestedInfo
		*/
		bool sett_adsData(bool t_adsData);

		//! Function to set new values
		/*!		Function to set NULL type of argument t_adsData for datatype RequestedInfo
		*/
		bool* sett_adsData();

		//! Function to get values
		/*!		Function to get NULL type of argument t_adsData for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool gett_adsData();

		//!Function to set values
		/*!		Function to set RequestedNodes type of argument requestedNodes for datatype RequestedInfo
		*/
		bool setrequestedNodes(RequestedNodes* requestedNodes);

		//! Function to set values
		/*!		Function to set RequestedNodes type of argument requestedNodes for datatype RequestedInfo
		*/
		RequestedNodes* setrequestedNodes();

		//! Function to get values
		/*!		Function to set RequestedNodes type of argument requestedNodes for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		RequestedNodes* getrequestedNodes() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument servingNodeIndication for datatype RequestedInfo
		*/
		bool setservingNodeIndication(bool servingNodeIndication);

		//! Function to set new values
		/*!		Function to set NULL type of argument servingNodeIndication for datatype RequestedInfo
		*/
		bool* setservingNodeIndication();

		//! Function to get values
		/*!		Function to get NULL type of argument servingNodeIndication for datatype RequestedInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getservingNodeIndication();

		//! Function to Decode
		/*!		Function to Decode datatype RequestedInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RequestedInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RequestedInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RequestedInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_RequestedInformation
{
	RequestedInformation_REQUESTEDINFORMATIONTYPE	=  1 << 0,
	RequestedInformation_REQUESTEDINFORMATIONVALUE	=  1 << 1,
	RequestedInformation_TAG_NULL	=  0x0000
}RequestedInformation_tags;

		//! Class Definition
		/*!		ClassName is RequestedInformation
		*/
class RequestedInformation
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		RequestedInformationType*		mrequestedInformationType;

		RequestedInformationValue*		mrequestedInformationValue;


	public:
		RequestedInformation();

		~RequestedInformation();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set RequestedInformationType type of argument requestedInformationType for datatype RequestedInformation
		*/
		bool setrequestedInformationType(RequestedInformationType* requestedInformationType);

		//! Function to set values
		/*!		Function to set RequestedInformationType type of argument requestedInformationType for datatype RequestedInformation
		*/
		RequestedInformationType* setrequestedInformationType();

		//! Function to get values
		/*!		Function to set RequestedInformationType type of argument requestedInformationType for datatype RequestedInformation
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationType* getrequestedInformationType() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set RequestedInformationValue type of argument requestedInformationValue for datatype RequestedInformation
		*/
		bool setrequestedInformationValue(RequestedInformationValue* requestedInformationValue);

		//! Function to set values
		/*!		Function to set RequestedInformationValue type of argument requestedInformationValue for datatype RequestedInformation
		*/
		RequestedInformationValue* setrequestedInformationValue();

		//! Function to get values
		/*!		Function to set RequestedInformationValue type of argument requestedInformationValue for datatype RequestedInformation
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationValue* getrequestedInformationValue() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype RequestedInformation
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RequestedInformation
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RequestedInformation
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RequestedInformation
		*/
		bool ValidateMandatory(char *errStr);

};

class RequestedInformationList
{
	private:

		vector<RequestedInformation *> mParamList;

		RequestedInformation*  mRequestedInformation;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		RequestedInformationList();

		~RequestedInformationList();

		bool setRequestedInformation(RequestedInformation* requestedInformation);

		RequestedInformation* setRequestedInformation();

		RequestedInformation* setNewRequestedInformation();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First RequestedInformation type of argument RequestedInformation for datatype RequestedInformationList list
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformation* getRequestedInformation() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value RequestedInformation type of argument RequestedInformation for datatype RequestedInformationList at given location
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformation* getRequestedInformationAtLocation(unsigned location) ;//throw(const char*)

		RequestedInformation* setNextRequestedInformation();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next RequestedInformation type of argument RequestedInformation for datatype RequestedInformationList list
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformation* getNextRequestedInformation() ;//throw(const char*)

		unsigned getNoOfRequestedInformation();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};

TSS_ENUM(REQUESTEDINFORMATIONTYPE,
	(callAttemptElapsedTime, "callAttemptElapsedTime", 	 0X0000)
	(callStopTime, "callStopTime", 	 0X0001)
	(callConnectedElapsedTime, "callConnectedElapsedTime", 	 0X0002)
	(releaseCause, "releaseCause", 0X001E)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype RequestedInformationType
		*/
class RequestedInformationType
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		REQUESTEDINFORMATIONTYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype RequestedInformationType
		*/
		RequestedInformationType();

		//!Destructor Function
		/*!		Destructor for datatype DomainType
		*/
		~RequestedInformationType();

		//!Function to set values
		/*!		Function to set ENUM type for datatype RequestedInformationType
		*/
		bool setValue(REQUESTEDINFORMATIONTYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype RequestedInformationType
		*/
		REQUESTEDINFORMATIONTYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype RequestedInformationType
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype RequestedInformationType
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype RequestedInformationType
		*/
		int Display(int tab);

};

class RequestedInformationTypeList
{
	private:

		vector<RequestedInformationType *> mParamList;

		RequestedInformationType*  mRequestedInformationType;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		RequestedInformationTypeList();

		~RequestedInformationTypeList();

		bool setRequestedInformationType(RequestedInformationType* requestedInformationType);

		RequestedInformationType* setRequestedInformationType();

		RequestedInformationType* setNewRequestedInformationType();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First RequestedInformationType type of argument RequestedInformationType for datatype RequestedInformationTypeList list
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationType* getRequestedInformationType() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value RequestedInformationType type of argument RequestedInformationType for datatype RequestedInformationTypeList at given location
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationType* getRequestedInformationTypeAtLocation(unsigned location) ;//throw(const char*)

		RequestedInformationType* setNextRequestedInformationType();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next RequestedInformationType type of argument RequestedInformationType for datatype RequestedInformationTypeList list
		Throws exception of which type and Summary of Exception
		*/
		RequestedInformationType* getNextRequestedInformationType() ;//throw(const char*)

		unsigned getNoOfRequestedInformationType();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};
typedef enum _tags_RequestedInformationValue
{
	RequestedInformationValue_CALLATTEMPTELAPSEDTIMEVALUE	=  1 << 0,
	RequestedInformationValue_CALLSTOPTIMEVALUE	=  1 << 1,
	RequestedInformationValue_CALLCONNECTEDELAPSEDTIMEVALUE	=  1 << 2,
	RequestedInformationValue_RELEASECAUSEVALUE	=  1 << 3,
	RequestedInformationValue_TAG_NULL	=  0x0000
}RequestedInformationValue_tags;

		//! Class Definition
		/*!		ClassName is RequestedInformationValue
		*/
class RequestedInformationValue
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mcallAttemptElapsedTimeValue;

		capstd::DateAndTime*		mcallStopTimeValue;

		capstd::INTEGER*		mcallConnectedElapsedTimeValue;

		capstd::GENERIC*		mreleaseCauseValue;


	public:
		RequestedInformationValue();

		~RequestedInformationValue();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument callAttemptElapsedTimeValue for datatype RequestedInformationValue
		*/
		bool setcallAttemptElapsedTimeValue(capstd::INTEGER* callAttemptElapsedTimeValue);

		//! Function to set values
		/*!		Function to set INTEGER type of argument callAttemptElapsedTimeValue for datatype RequestedInformationValue
		*/
		capstd::INTEGER* setcallAttemptElapsedTimeValue();

		//! Function to get values
		/*!		Function to set INTEGER type of argument callAttemptElapsedTimeValue for datatype RequestedInformationValue
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getcallAttemptElapsedTimeValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set DateAndTime type of argument callStopTimeValue for datatype RequestedInformationValue
		*/
		bool setcallStopTimeValue(capstd::DateAndTime* callStopTimeValue);

		//! Function to set values
		/*!		Function to set DateAndTime type of argument callStopTimeValue for datatype RequestedInformationValue
		*/
		capstd::DateAndTime* setcallStopTimeValue();

		//! Function to get values
		/*!		Function to set DateAndTime type of argument callStopTimeValue for datatype RequestedInformationValue
		Throws exception of which type and Summary of Exception
		*/
		capstd::DateAndTime* getcallStopTimeValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument callConnectedElapsedTimeValue for datatype RequestedInformationValue
		*/
		bool setcallConnectedElapsedTimeValue(capstd::INTEGER* callConnectedElapsedTimeValue);

		//! Function to set values
		/*!		Function to set INTEGER type of argument callConnectedElapsedTimeValue for datatype RequestedInformationValue
		*/
		capstd::INTEGER* setcallConnectedElapsedTimeValue();

		//! Function to get values
		/*!		Function to set INTEGER type of argument callConnectedElapsedTimeValue for datatype RequestedInformationValue
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getcallConnectedElapsedTimeValue() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument releaseCauseValue for datatype RequestedInformationValue
		*/
		bool setreleaseCauseValue(capstd::GENERIC* releaseCauseValue);

		//! Function to set values
		/*!		Function to set GENERIC type of argument releaseCauseValue for datatype RequestedInformationValue
		*/
		capstd::GENERIC* setreleaseCauseValue();

		//! Function to get values
		/*!		Function to set GENERIC type of argument releaseCauseValue for datatype RequestedInformationValue
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getreleaseCauseValue() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype RequestedInformationValue
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RequestedInformationValue
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RequestedInformationValue
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RequestedInformationValue
		*/
		bool ValidateMandatory(char *errStr);

};

typedef enum _REQUESTEDNODES
{
	REQUESTEDNODES_mme	=  0X0000,
	REQUESTEDNODES_sgsn	=  0X0001
}REQUESTEDNODES;


typedef struct _RequestedNodes
{
	unsigned int mme:1;
	unsigned int sgsn:1;
}_RequestedNodes;

		//!Creating BitString Class
		/*!		Creating BitString Class of Datatype RequestedNodes
		*/
class RequestedNodes
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		unsigned mLength;

		unsigned mUnUsedBits;

		int  minSize;

		int  maxSize;

		char* mValue;

		REQUESTEDNODES mEnumValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype RequestedNodes
		*/
		RequestedNodes();

		//!Constructor Function
		/*!		Constructor for datatype RequestedNodes with min and max size defined
		*/
		RequestedNodes(int, int);

		//!Destructor Function
		/*!		Destructor for datatype RequestedNodes
		*/
		~RequestedNodes();

		//!Function to set values
		/*!		Function to set Bit value for mme
		*/
		bool setMme();
		//!Function to set values
		/*!		Function to set Bit value for sgsn
		*/
		bool setSgsn();
		//!Function to get values
		/*!		Function to check whether Bit value is set for mme
		*/
		bool isSetMme();
		//!Function to get values
		/*!		Function to check whether Bit value is set for sgsn
		*/
		bool isSetSgsn();
		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype RequestedNodes
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype RequestedNodes
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype RequestedNodes
		*/
		int Display(int tab);

};
typedef enum _tags_ResourceAddress
{
	ResourceAddress_IPROUTINGADDRESS	=  1 << 0,
	ResourceAddress_NONE	=  1 << 1,
	ResourceAddress_TAG_NULL	=  0x0000
}ResourceAddress_tags;

		//! Class Definition
		/*!		ClassName is ResourceAddress
		*/
class ResourceAddress
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mipRoutingAddress;

		bool 		mnone;

		bool 		mNullnone;


	public:
		ResourceAddress();

		~ResourceAddress();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument ipRoutingAddress for datatype ResourceAddress
		*/
		bool setipRoutingAddress(capstd::OctetString* ipRoutingAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument ipRoutingAddress for datatype ResourceAddress
		*/
		capstd::OctetString* setipRoutingAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument ipRoutingAddress for datatype ResourceAddress
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getipRoutingAddress() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument none for datatype ResourceAddress
		*/
		bool setnone(bool none);

		//! Function to set new values
		/*!		Function to set NULL type of argument none for datatype ResourceAddress
		*/
		bool* setnone();

		//! Function to get values
		/*!		Function to get NULL type of argument none for datatype ResourceAddress
		Throws exception of which type and Summary of Exception
		*/
		bool getnone();

		//! Function to Decode
		/*!		Function to Decode datatype ResourceAddress
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ResourceAddress
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ResourceAddress
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ResourceAddress
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_RouteSelectFailureSpecificInfo
{
	RouteSelectFailureSpecificInfo_FAILURECAUSE	=  1 << 0,
	RouteSelectFailureSpecificInfo_TAG_NULL	=  0x0000
}RouteSelectFailureSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is RouteSelectFailureSpecificInfo
		*/
class RouteSelectFailureSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mfailureCause;


	public:
		RouteSelectFailureSpecificInfo();

		~RouteSelectFailureSpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument failureCause for datatype RouteSelectFailureSpecificInfo
		*/
		bool setfailureCause(capstd::GENERIC* failureCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument failureCause for datatype RouteSelectFailureSpecificInfo
		*/
		capstd::GENERIC* setfailureCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument failureCause for datatype RouteSelectFailureSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getfailureCause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype RouteSelectFailureSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype RouteSelectFailureSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RouteSelectFailureSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags RouteSelectFailureSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_SendingSideID
{
	SendingSideID_SENDINGSIDEID	=  1 << 0,
	SendingSideID_TAG_NULL	=  0x0000
}SendingSideID_tags;

		//! Class Definition
		/*!		ClassName is SendingSideID
		*/
class SendingSideID
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		msendingSideID;


	public:
		SendingSideID();

		~SendingSideID();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument sendingSideID for datatype SendingSideID
		*/
		bool setsendingSideID(capstd::OctetString* sendingSideID);

		//! Function to set values
		/*!		Function to set OctetString type of argument sendingSideID for datatype SendingSideID
		*/
		capstd::OctetString* setsendingSideID();

		//! Function to get values
		/*!		Function to set OctetString type of argument sendingSideID for datatype SendingSideID
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getsendingSideID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype SendingSideID
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SendingSideID
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SendingSideID
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SendingSideID
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_ServiceInteractionIndicatorsTwo
{
	ServiceInteractionIndicatorsTwo_FORWARDSERVICEINTERACTIONIND	=  1 << 0,
	ServiceInteractionIndicatorsTwo_BACKWARDSERVICEINTERACTIONIND	=  1 << 1,
	ServiceInteractionIndicatorsTwo_BOTHWAYTHROUGHCONNECTIONIND	=  1 << 2,
	ServiceInteractionIndicatorsTwo_CONNECTEDNUMBERTREATMENTIND	=  1 << 3,
	ServiceInteractionIndicatorsTwo_NONCUGCALL	=  1 << 4,
	ServiceInteractionIndicatorsTwo_HOLDTREATMENTINDICATOR	=  1 << 5,
	ServiceInteractionIndicatorsTwo_CWTREATMENTINDICATOR	=  1 << 6,
	ServiceInteractionIndicatorsTwo_ECTTREATMENTINDICATOR	=  1 << 7,
	ServiceInteractionIndicatorsTwo_TAG_NULL	=  0x0000
}ServiceInteractionIndicatorsTwo_tags;

		//! Class Definition
		/*!		ClassName is ServiceInteractionIndicatorsTwo
		*/
class ServiceInteractionIndicatorsTwo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		ForwardServiceInteractionInd*		mforwardServiceInteractionInd;

		BackwardServiceInteractionInd*		mbackwardServiceInteractionInd;

		BothwayThroughConnectionInd*		mbothwayThroughConnectionInd;

		ConnectedNumberTreatmentInd*		mconnectedNumberTreatmentInd;

		bool 		mnonCUGCall;

		bool 		mNullnonCUGCall;

		capstd::OctetString*		mholdTreatmentIndicator;

		capstd::OctetString*		mcwTreatmentIndicator;

		capstd::OctetString*		mectTreatmentIndicator;


	public:
		ServiceInteractionIndicatorsTwo();

		~ServiceInteractionIndicatorsTwo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set ForwardServiceInteractionInd type of argument forwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setforwardServiceInteractionInd(ForwardServiceInteractionInd* forwardServiceInteractionInd);

		//! Function to set values
		/*!		Function to set ForwardServiceInteractionInd type of argument forwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		ForwardServiceInteractionInd* setforwardServiceInteractionInd();

		//! Function to get values
		/*!		Function to set ForwardServiceInteractionInd type of argument forwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		ForwardServiceInteractionInd* getforwardServiceInteractionInd() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set BackwardServiceInteractionInd type of argument backwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setbackwardServiceInteractionInd(BackwardServiceInteractionInd* backwardServiceInteractionInd);

		//! Function to set values
		/*!		Function to set BackwardServiceInteractionInd type of argument backwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		BackwardServiceInteractionInd* setbackwardServiceInteractionInd();

		//! Function to get values
		/*!		Function to set BackwardServiceInteractionInd type of argument backwardServiceInteractionInd for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		BackwardServiceInteractionInd* getbackwardServiceInteractionInd() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set BothwayThroughConnectionInd type of argument bothwayThroughConnectionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setbothwayThroughConnectionInd(BothwayThroughConnectionInd* bothwayThroughConnectionInd);

		//! Function to set values
		/*!		Function to set BothwayThroughConnectionInd type of argument bothwayThroughConnectionInd for datatype ServiceInteractionIndicatorsTwo
		*/
		BothwayThroughConnectionInd* setbothwayThroughConnectionInd();

		//! Function to get values
		/*!		Function to set BothwayThroughConnectionInd type of argument bothwayThroughConnectionInd for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		BothwayThroughConnectionInd* getbothwayThroughConnectionInd() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set ConnectedNumberTreatmentInd type of argument connectedNumberTreatmentInd for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setconnectedNumberTreatmentInd(ConnectedNumberTreatmentInd* connectedNumberTreatmentInd);

		//! Function to set values
		/*!		Function to set ConnectedNumberTreatmentInd type of argument connectedNumberTreatmentInd for datatype ServiceInteractionIndicatorsTwo
		*/
		ConnectedNumberTreatmentInd* setconnectedNumberTreatmentInd();

		//! Function to get values
		/*!		Function to set ConnectedNumberTreatmentInd type of argument connectedNumberTreatmentInd for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		ConnectedNumberTreatmentInd* getconnectedNumberTreatmentInd() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument nonCUGCall for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setnonCUGCall(bool nonCUGCall);

		//! Function to set new values
		/*!		Function to set NULL type of argument nonCUGCall for datatype ServiceInteractionIndicatorsTwo
		*/
		bool* setnonCUGCall();

		//! Function to get values
		/*!		Function to get NULL type of argument nonCUGCall for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		bool getnonCUGCall();

		//!Function to set values
		/*!		Function to set OctetString type of argument holdTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setholdTreatmentIndicator(capstd::OctetString* holdTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument holdTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		capstd::OctetString* setholdTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument holdTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getholdTreatmentIndicator() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument cwTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setcwTreatmentIndicator(capstd::OctetString* cwTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument cwTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		capstd::OctetString* setcwTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument cwTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getcwTreatmentIndicator() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ectTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		bool setectTreatmentIndicator(capstd::OctetString* ectTreatmentIndicator);

		//! Function to set values
		/*!		Function to set OctetString type of argument ectTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		*/
		capstd::OctetString* setectTreatmentIndicator();

		//! Function to get values
		/*!		Function to set OctetString type of argument ectTreatmentIndicator for datatype ServiceInteractionIndicatorsTwo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getectTreatmentIndicator() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype ServiceInteractionIndicatorsTwo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype ServiceInteractionIndicatorsTwo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ServiceInteractionIndicatorsTwo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags ServiceInteractionIndicatorsTwo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_SubscriberIdentity
{
	SubscriberIdentity_IMSI	=  1 << 0,
	SubscriberIdentity_MSISDN	=  1 << 1,
	SubscriberIdentity_TAG_NULL	=  0x0000
}SubscriberIdentity_tags;

		//! Class Definition
		/*!		ClassName is SubscriberIdentity
		*/
class SubscriberIdentity
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::IMSI*		mimsi;

		capstd::OctetString*		mmsisdn;


	public:
		SubscriberIdentity();

		~SubscriberIdentity();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set IMSI type of argument imsi for datatype SubscriberIdentity
		*/
		bool setimsi(capstd::IMSI* imsi);

		//! Function to set values
		/*!		Function to set IMSI type of argument imsi for datatype SubscriberIdentity
		*/
		capstd::IMSI* setimsi();

		//! Function to get values
		/*!		Function to set IMSI type of argument imsi for datatype SubscriberIdentity
		Throws exception of which type and Summary of Exception
		*/
		capstd::IMSI* getimsi() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument msisdn for datatype SubscriberIdentity
		*/
		bool setmsisdn(capstd::OctetString* msisdn);

		//! Function to set values
		/*!		Function to set OctetString type of argument msisdn for datatype SubscriberIdentity
		*/
		capstd::OctetString* setmsisdn();

		//! Function to get values
		/*!		Function to set OctetString type of argument msisdn for datatype SubscriberIdentity
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmsisdn() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype SubscriberIdentity
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SubscriberIdentity
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscriberIdentity
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SubscriberIdentity
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_SubscriberInfo
{
	SubscriberInfo_LOCATIONINFORMATION	=  1 << 0,
	SubscriberInfo_SUBSCRIBERSTATE	=  1 << 1,
	SubscriberInfo_EXTENSIONCONTAINER	=  1 << 2,
	SubscriberInfo_LOCATIONINFORMATIONGPRS	=  1 << 3,
	SubscriberInfo_PS_SUBSCRIBERSTATE	=  1 << 4,
	SubscriberInfo_IMEI	=  1 << 5,
	SubscriberInfo_MS_CLASSMARK2	=  1 << 6,
	SubscriberInfo_GPRS_MS_CLASS	=  1 << 7,
	SubscriberInfo_MNPINFORES	=  1 << 8,
	SubscriberInfo_IMSVOICEOVERPS_SESSIONSINDICATION	=  1 << 9,
	SubscriberInfo_LASTUE_ACTIVITYTIME	=  1 << 10,
	SubscriberInfo_LASTRAT_TYPE	=  1 << 11,
	SubscriberInfo_EPS_SUBSCRIBERSTATE	=  1 << 12,
	SubscriberInfo_LOCATIONINFORMATIONEPS	=  1 << 13,
	SubscriberInfo_TAG_NULL	=  0x0000
}SubscriberInfo_tags;

		//! Class Definition
		/*!		ClassName is SubscriberInfo
		*/
class SubscriberInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		LocationInformation*		mlocationInformation;

		SubscriberState*		msubscriberState;

		capstd::GENERIC*		mextensionContainer;

		LocationInformationGPRS*		mlocationInformationGPRS;

		PS_SubscriberState*		mps_SubscriberState;

		capstd::OctetString*		mimei;

		capstd::OctetString*		mms_Classmark2;

		GPRSMSClass*		mgprs_MS_Class;

		MNPInfoRes*		mmnpInfoRes;

		IMS_VoiceOverPS_SessionsInd*		mimsVoiceOverPS_SessionsIndication;

		capstd::OctetString*		mlastUE_ActivityTime;

		Used_RAT_Type*		mlastRAT_Type;

		PS_SubscriberState*		meps_SubscriberState;

		LocationInformationEPS*		mlocationInformationEPS;


	public:
		SubscriberInfo();

		~SubscriberInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype SubscriberInfo
		*/
		bool setlocationInformation(LocationInformation* locationInformation);

		//! Function to set values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype SubscriberInfo
		*/
		LocationInformation* setlocationInformation();

		//! Function to get values
		/*!		Function to set LocationInformation type of argument locationInformation for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		LocationInformation* getlocationInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype SubscriberInfo
		*/
		bool setsubscriberState(SubscriberState* subscriberState);

		//! Function to set values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype SubscriberInfo
		*/
		SubscriberState* setsubscriberState();

		//! Function to get values
		/*!		Function to set SubscriberState type of argument subscriberState for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		SubscriberState* getsubscriberState() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype SubscriberInfo
		*/
		bool setextensionContainer(capstd::GENERIC* extensionContainer);

		//! Function to set values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype SubscriberInfo
		*/
		capstd::GENERIC* setextensionContainer();

		//! Function to get values
		/*!		Function to set GENERIC type of argument extensionContainer for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getextensionContainer() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype SubscriberInfo
		*/
		bool setlocationInformationGPRS(LocationInformationGPRS* locationInformationGPRS);

		//! Function to set values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype SubscriberInfo
		*/
		LocationInformationGPRS* setlocationInformationGPRS();

		//! Function to get values
		/*!		Function to set LocationInformationGPRS type of argument locationInformationGPRS for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		LocationInformationGPRS* getlocationInformationGPRS() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set PS_SubscriberState type of argument ps_SubscriberState for datatype SubscriberInfo
		*/
		bool setps_SubscriberState(PS_SubscriberState* ps_SubscriberState);

		//! Function to set values
		/*!		Function to set PS_SubscriberState type of argument ps_SubscriberState for datatype SubscriberInfo
		*/
		PS_SubscriberState* setps_SubscriberState();

		//! Function to get values
		/*!		Function to set PS_SubscriberState type of argument ps_SubscriberState for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		PS_SubscriberState* getps_SubscriberState() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument imei for datatype SubscriberInfo
		*/
		bool setimei(capstd::OctetString* imei);

		//! Function to set values
		/*!		Function to set OctetString type of argument imei for datatype SubscriberInfo
		*/
		capstd::OctetString* setimei();

		//! Function to get values
		/*!		Function to set OctetString type of argument imei for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getimei() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype SubscriberInfo
		*/
		bool setms_Classmark2(capstd::OctetString* ms_Classmark2);

		//! Function to set values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype SubscriberInfo
		*/
		capstd::OctetString* setms_Classmark2();

		//! Function to get values
		/*!		Function to set OctetString type of argument ms_Classmark2 for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getms_Classmark2() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set GPRSMSClass type of argument gprs_MS_Class for datatype SubscriberInfo
		*/
		bool setgprs_MS_Class(GPRSMSClass* gprs_MS_Class);

		//! Function to set values
		/*!		Function to set GPRSMSClass type of argument gprs_MS_Class for datatype SubscriberInfo
		*/
		GPRSMSClass* setgprs_MS_Class();

		//! Function to get values
		/*!		Function to set GPRSMSClass type of argument gprs_MS_Class for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		GPRSMSClass* getgprs_MS_Class() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set MNPInfoRes type of argument mnpInfoRes for datatype SubscriberInfo
		*/
		bool setmnpInfoRes(MNPInfoRes* mnpInfoRes);

		//! Function to set values
		/*!		Function to set MNPInfoRes type of argument mnpInfoRes for datatype SubscriberInfo
		*/
		MNPInfoRes* setmnpInfoRes();

		//! Function to get values
		/*!		Function to set MNPInfoRes type of argument mnpInfoRes for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		MNPInfoRes* getmnpInfoRes() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set IMS_VoiceOverPS_SessionsInd type of argument imsVoiceOverPS_SessionsIndication for datatype SubscriberInfo
		*/
		bool setimsVoiceOverPS_SessionsIndication(IMS_VoiceOverPS_SessionsInd* imsVoiceOverPS_SessionsIndication);

		//! Function to set values
		/*!		Function to set IMS_VoiceOverPS_SessionsInd type of argument imsVoiceOverPS_SessionsIndication for datatype SubscriberInfo
		*/
		IMS_VoiceOverPS_SessionsInd* setimsVoiceOverPS_SessionsIndication();

		//! Function to get values
		/*!		Function to set IMS_VoiceOverPS_SessionsInd type of argument imsVoiceOverPS_SessionsIndication for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		IMS_VoiceOverPS_SessionsInd* getimsVoiceOverPS_SessionsIndication() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument lastUE_ActivityTime for datatype SubscriberInfo
		*/
		bool setlastUE_ActivityTime(capstd::OctetString* lastUE_ActivityTime);

		//! Function to set values
		/*!		Function to set OctetString type of argument lastUE_ActivityTime for datatype SubscriberInfo
		*/
		capstd::OctetString* setlastUE_ActivityTime();

		//! Function to get values
		/*!		Function to set OctetString type of argument lastUE_ActivityTime for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getlastUE_ActivityTime() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Used_RAT_Type type of argument lastRAT_Type for datatype SubscriberInfo
		*/
		bool setlastRAT_Type(Used_RAT_Type* lastRAT_Type);

		//! Function to set values
		/*!		Function to set Used_RAT_Type type of argument lastRAT_Type for datatype SubscriberInfo
		*/
		Used_RAT_Type* setlastRAT_Type();

		//! Function to get values
		/*!		Function to set Used_RAT_Type type of argument lastRAT_Type for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		Used_RAT_Type* getlastRAT_Type() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set PS_SubscriberState type of argument eps_SubscriberState for datatype SubscriberInfo
		*/
		bool seteps_SubscriberState(PS_SubscriberState* eps_SubscriberState);

		//! Function to set values
		/*!		Function to set PS_SubscriberState type of argument eps_SubscriberState for datatype SubscriberInfo
		*/
		PS_SubscriberState* seteps_SubscriberState();

		//! Function to get values
		/*!		Function to set PS_SubscriberState type of argument eps_SubscriberState for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		PS_SubscriberState* geteps_SubscriberState() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype SubscriberInfo
		*/
		bool setlocationInformationEPS(LocationInformationEPS* locationInformationEPS);

		//! Function to set values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype SubscriberInfo
		*/
		LocationInformationEPS* setlocationInformationEPS();

		//! Function to get values
		/*!		Function to set LocationInformationEPS type of argument locationInformationEPS for datatype SubscriberInfo
		Throws exception of which type and Summary of Exception
		*/
		LocationInformationEPS* getlocationInformationEPS() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype SubscriberInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SubscriberInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscriberInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SubscriberInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_SubscriberState
{
	SubscriberState_ASSUMEDIDLE	=  1 << 0,
	SubscriberState_CAMELBUSY	=  1 << 1,
	SubscriberState_NETDETNOTREACHABLE	=  1 << 2,
	SubscriberState_NOTPROVIDEDFROMVLR	=  1 << 3,
	SubscriberState_TAG_NULL	=  0x0000
}SubscriberState_tags;

		//! Class Definition
		/*!		ClassName is SubscriberState
		*/
class SubscriberState
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bool 		massumedIdle;

		bool 		mNullassumedIdle;

		bool 		mcamelBusy;

		bool 		mNullcamelBusy;

		NotReachableReason*		mnetDetNotReachable;

		bool 		mnotProvidedFromVLR;

		bool 		mNullnotProvidedFromVLR;


	public:
		SubscriberState();

		~SubscriberState();

		bool isPresent(int);

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument assumedIdle for datatype SubscriberState
		*/
		bool setassumedIdle(bool assumedIdle);

		//! Function to set new values
		/*!		Function to set NULL type of argument assumedIdle for datatype SubscriberState
		*/
		bool* setassumedIdle();

		//! Function to get values
		/*!		Function to get NULL type of argument assumedIdle for datatype SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getassumedIdle();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument camelBusy for datatype SubscriberState
		*/
		bool setcamelBusy(bool camelBusy);

		//! Function to set new values
		/*!		Function to set NULL type of argument camelBusy for datatype SubscriberState
		*/
		bool* setcamelBusy();

		//! Function to get values
		/*!		Function to get NULL type of argument camelBusy for datatype SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getcamelBusy();

		//!Function to set values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype SubscriberState
		*/
		bool setnetDetNotReachable(NotReachableReason* netDetNotReachable);

		//! Function to set values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype SubscriberState
		*/
		NotReachableReason* setnetDetNotReachable();

		//! Function to get values
		/*!		Function to set NotReachableReason type of argument netDetNotReachable for datatype SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		NotReachableReason* getnetDetNotReachable() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument notProvidedFromVLR for datatype SubscriberState
		*/
		bool setnotProvidedFromVLR(bool notProvidedFromVLR);

		//! Function to set new values
		/*!		Function to set NULL type of argument notProvidedFromVLR for datatype SubscriberState
		*/
		bool* setnotProvidedFromVLR();

		//! Function to get values
		/*!		Function to get NULL type of argument notProvidedFromVLR for datatype SubscriberState
		Throws exception of which type and Summary of Exception
		*/
		bool getnotProvidedFromVLR();

		//! Function to Decode
		/*!		Function to Decode datatype SubscriberState
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SubscriberState
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscriberState
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SubscriberState
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_SupportedExtensionsExtensionType
{
	SupportedExtensionsExtensionType_FIRSTEXTENSIONEXTENSIONTYPE	=  1 << 0,
	SupportedExtensionsExtensionType_TAG_NULL	=  0x0000
}SupportedExtensionsExtensionType_tags;

		//! Class Definition
		/*!		ClassName is SupportedExtensionsExtensionType
		*/
class SupportedExtensionsExtensionType
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bool 		mfirstExtensionExtensionType;

		bool 		mNullfirstExtensionExtensionType;


	public:
		SupportedExtensionsExtensionType();

		~SupportedExtensionsExtensionType();

		bool isPresent(int);

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument firstExtensionExtensionType for datatype SupportedExtensionsExtensionType
		*/
		bool setfirstExtensionExtensionType(bool firstExtensionExtensionType);

		//! Function to set new values
		/*!		Function to set NULL type of argument firstExtensionExtensionType for datatype SupportedExtensionsExtensionType
		*/
		bool* setfirstExtensionExtensionType();

		//! Function to get values
		/*!		Function to get NULL type of argument firstExtensionExtensionType for datatype SupportedExtensionsExtensionType
		Throws exception of which type and Summary of Exception
		*/
		bool getfirstExtensionExtensionType();

		//! Function to Decode
		/*!		Function to Decode datatype SupportedExtensionsExtensionType
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype SupportedExtensionsExtensionType
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SupportedExtensionsExtensionType
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags SupportedExtensionsExtensionType
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TAnswerSpecificInfo
{
	TAnswerSpecificInfo_DESTINATIONADDRESS	=  1 << 0,
	TAnswerSpecificInfo_OR_CALL	=  1 << 1,
	TAnswerSpecificInfo_FORWARDEDCALL	=  1 << 2,
	TAnswerSpecificInfo_TAG_NULL	=  0x0000
}TAnswerSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is TAnswerSpecificInfo
		*/
class TAnswerSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mdestinationAddress;

		bool 		mor_Call;

		bool 		mNullor_Call;

		bool 		mforwardedCall;

		bool 		mNullforwardedCall;


	public:
		TAnswerSpecificInfo();

		~TAnswerSpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument destinationAddress for datatype TAnswerSpecificInfo
		*/
		bool setdestinationAddress(capstd::OctetString* destinationAddress);

		//! Function to set values
		/*!		Function to set OctetString type of argument destinationAddress for datatype TAnswerSpecificInfo
		*/
		capstd::OctetString* setdestinationAddress();

		//! Function to get values
		/*!		Function to set OctetString type of argument destinationAddress for datatype TAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getdestinationAddress() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument or_Call for datatype TAnswerSpecificInfo
		*/
		bool setor_Call(bool or_Call);

		//! Function to set new values
		/*!		Function to set NULL type of argument or_Call for datatype TAnswerSpecificInfo
		*/
		bool* setor_Call();

		//! Function to get values
		/*!		Function to get NULL type of argument or_Call for datatype TAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getor_Call();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument forwardedCall for datatype TAnswerSpecificInfo
		*/
		bool setforwardedCall(bool forwardedCall);

		//! Function to set new values
		/*!		Function to set NULL type of argument forwardedCall for datatype TAnswerSpecificInfo
		*/
		bool* setforwardedCall();

		//! Function to get values
		/*!		Function to get NULL type of argument forwardedCall for datatype TAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getforwardedCall();

		//! Function to Decode
		/*!		Function to Decode datatype TAnswerSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TAnswerSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TAnswerSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TAnswerSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TBusySpecificInfo
{
	TBusySpecificInfo_BUSYCAUSE	=  1 << 0,
	TBusySpecificInfo_CALLFORWARDED	=  1 << 1,
	TBusySpecificInfo_ROUTENOTPERMITTED	=  1 << 2,
	TBusySpecificInfo_TAG_NULL	=  0x0000
}TBusySpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is TBusySpecificInfo
		*/
class TBusySpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mbusyCause;

		bool 		mcallForwarded;

		bool 		mNullcallForwarded;

		bool 		mrouteNotPermitted;

		bool 		mNullrouteNotPermitted;


	public:
		TBusySpecificInfo();

		~TBusySpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument busyCause for datatype TBusySpecificInfo
		*/
		bool setbusyCause(capstd::GENERIC* busyCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument busyCause for datatype TBusySpecificInfo
		*/
		capstd::GENERIC* setbusyCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument busyCause for datatype TBusySpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getbusyCause() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument callForwarded for datatype TBusySpecificInfo
		*/
		bool setcallForwarded(bool callForwarded);

		//! Function to set new values
		/*!		Function to set NULL type of argument callForwarded for datatype TBusySpecificInfo
		*/
		bool* setcallForwarded();

		//! Function to get values
		/*!		Function to get NULL type of argument callForwarded for datatype TBusySpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getcallForwarded();

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument routeNotPermitted for datatype TBusySpecificInfo
		*/
		bool setrouteNotPermitted(bool routeNotPermitted);

		//! Function to set new values
		/*!		Function to set NULL type of argument routeNotPermitted for datatype TBusySpecificInfo
		*/
		bool* setrouteNotPermitted();

		//! Function to get values
		/*!		Function to get NULL type of argument routeNotPermitted for datatype TBusySpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getrouteNotPermitted();

		//! Function to Decode
		/*!		Function to Decode datatype TBusySpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TBusySpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TBusySpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TBusySpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TDisconnectSpecificInfo
{
	TDisconnectSpecificInfo_RELEASECAUSE	=  1 << 0,
	TDisconnectSpecificInfo_TAG_NULL	=  0x0000
}TDisconnectSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is TDisconnectSpecificInfo
		*/
class TDisconnectSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::GENERIC*		mreleaseCause;


	public:
		TDisconnectSpecificInfo();

		~TDisconnectSpecificInfo();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype TDisconnectSpecificInfo
		*/
		bool setreleaseCause(capstd::GENERIC* releaseCause);

		//! Function to set values
		/*!		Function to set GENERIC type of argument releaseCause for datatype TDisconnectSpecificInfo
		*/
		capstd::GENERIC* setreleaseCause();

		//! Function to get values
		/*!		Function to set GENERIC type of argument releaseCause for datatype TDisconnectSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		capstd::GENERIC* getreleaseCause() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TDisconnectSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TDisconnectSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TDisconnectSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TDisconnectSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TNoAnswerSpecificInfo
{
	TNoAnswerSpecificInfo_CALLFORWARDED	=  1 << 0,
	TNoAnswerSpecificInfo_TAG_NULL	=  0x0000
}TNoAnswerSpecificInfo_tags;

		//! Class Definition
		/*!		ClassName is TNoAnswerSpecificInfo
		*/
class TNoAnswerSpecificInfo
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		bool 		mcallForwarded;

		bool 		mNullcallForwarded;


	public:
		TNoAnswerSpecificInfo();

		~TNoAnswerSpecificInfo();

		bool isPresent(int);

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument callForwarded for datatype TNoAnswerSpecificInfo
		*/
		bool setcallForwarded(bool callForwarded);

		//! Function to set new values
		/*!		Function to set NULL type of argument callForwarded for datatype TNoAnswerSpecificInfo
		*/
		bool* setcallForwarded();

		//! Function to get values
		/*!		Function to get NULL type of argument callForwarded for datatype TNoAnswerSpecificInfo
		Throws exception of which type and Summary of Exception
		*/
		bool getcallForwarded();

		//! Function to Decode
		/*!		Function to Decode datatype TNoAnswerSpecificInfo
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TNoAnswerSpecificInfo
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TNoAnswerSpecificInfo
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TNoAnswerSpecificInfo
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_Text
{
	Text_MESSAGECONTENT	=  1 << 0,
	Text_ATTRIBUTES	=  1 << 1,
	Text_TAG_NULL	=  0x0000
}Text_tags;

		//! Class Definition
		/*!		ClassName is Text
		*/
class Text
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::OctetString*		mmessageContent;

		capstd::OctetString*		mattributes;


	public:
		Text();

		~Text();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set OctetString type of argument messageContent for datatype Text
		*/
		bool setmessageContent(capstd::OctetString* messageContent);

		//! Function to set values
		/*!		Function to set OctetString type of argument messageContent for datatype Text
		*/
		capstd::OctetString* setmessageContent();

		//! Function to get values
		/*!		Function to set OctetString type of argument messageContent for datatype Text
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getmessageContent() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set OctetString type of argument attributes for datatype Text
		*/
		bool setattributes(capstd::OctetString* attributes);

		//! Function to set values
		/*!		Function to set OctetString type of argument attributes for datatype Text
		*/
		capstd::OctetString* setattributes();

		//! Function to get values
		/*!		Function to set OctetString type of argument attributes for datatype Text
		Throws exception of which type and Summary of Exception
		*/
		capstd::OctetString* getattributes() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype Text
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype Text
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Text
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags Text
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TimeDurationCharging
{
	TimeDurationCharging_MAXCALLPERIODDURATION	=  1 << 0,
	TimeDurationCharging_RELEASEIFDURATIONEXCEEDED	=  1 << 1,
	TimeDurationCharging_TARIFFSWITCHINTERVAL	=  1 << 2,
	TimeDurationCharging_TONE	=  1 << 3,
	TimeDurationCharging_EXTENSIONS	=  1 << 4,
	TimeDurationCharging_TAG_NULL	=  0x0000
}TimeDurationCharging_tags;

		//! Class Definition
		/*!		ClassName is TimeDurationCharging
		*/
class TimeDurationCharging
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mmaxCallPeriodDuration;

		capstd::Boolean* releaseIfdurationExceededDefault;
		capstd::Boolean*		mreleaseIfdurationExceeded;

		capstd::INTEGER*		mtariffSwitchInterval;

		capstd::Boolean* toneDefault;
		capstd::Boolean*		mtone;

		Extensions*		mextensions;


	public:
		TimeDurationCharging();

		~TimeDurationCharging();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument maxCallPeriodDuration for datatype TimeDurationCharging
		*/
		bool setmaxCallPeriodDuration(capstd::INTEGER* maxCallPeriodDuration);

		//! Function to set values
		/*!		Function to set INTEGER type of argument maxCallPeriodDuration for datatype TimeDurationCharging
		*/
		capstd::INTEGER* setmaxCallPeriodDuration();

		//! Function to get values
		/*!		Function to set INTEGER type of argument maxCallPeriodDuration for datatype TimeDurationCharging
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getmaxCallPeriodDuration() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument releaseIfdurationExceeded for datatype TimeDurationCharging
		*/
		bool setreleaseIfdurationExceeded(capstd::Boolean* releaseIfdurationExceeded);

		//! Function to set values
		/*!		Function to set Boolean type of argument releaseIfdurationExceeded for datatype TimeDurationCharging
		*/
		capstd::Boolean* setreleaseIfdurationExceeded();

		//! Function to get values
		/*!		Function to set Boolean type of argument releaseIfdurationExceeded for datatype TimeDurationCharging
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* getreleaseIfdurationExceeded() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeDurationCharging
		*/
		bool settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeDurationCharging
		*/
		capstd::INTEGER* settariffSwitchInterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeDurationCharging
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettariffSwitchInterval() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument tone for datatype TimeDurationCharging
		*/
		bool settone(capstd::Boolean* tone);

		//! Function to set values
		/*!		Function to set Boolean type of argument tone for datatype TimeDurationCharging
		*/
		capstd::Boolean* settone();

		//! Function to get values
		/*!		Function to set Boolean type of argument tone for datatype TimeDurationCharging
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* gettone() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationCharging
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationCharging
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationCharging
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TimeDurationCharging
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TimeDurationCharging
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TimeDurationCharging
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TimeDurationCharging
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TimeDurationChargingResult
{
	TimeDurationChargingResult_PARTYTOCHARGE	=  1 << 0,
	TimeDurationChargingResult_TIMEINFORMATION	=  1 << 1,
	TimeDurationChargingResult_CALLACTIVE	=  1 << 2,
	TimeDurationChargingResult_CALLRELEASEDATTCPEXPIRY	=  1 << 3,
	TimeDurationChargingResult_EXTENSIONS	=  1 << 4,
	TimeDurationChargingResult_TAG_NULL	=  0x0000
}TimeDurationChargingResult_tags;

		//! Class Definition
		/*!		ClassName is TimeDurationChargingResult
		*/
class TimeDurationChargingResult
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		ReceivingSideID*		mpartyToCharge;

		TimeInformation*		mtimeInformation;

		capstd::Boolean* callActiveDefault;
		capstd::Boolean*		mcallActive;

		bool 		mcallReleasedAtTcpExpiry;

		bool 		mNullcallReleasedAtTcpExpiry;

		Extensions*		mextensions;


	public:
		TimeDurationChargingResult();

		~TimeDurationChargingResult();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set ReceivingSideID type of argument partyToCharge for datatype TimeDurationChargingResult
		*/
		bool setpartyToCharge(ReceivingSideID* partyToCharge);

		//! Function to set values
		/*!		Function to set ReceivingSideID type of argument partyToCharge for datatype TimeDurationChargingResult
		*/
		ReceivingSideID* setpartyToCharge();

		//! Function to get values
		/*!		Function to set ReceivingSideID type of argument partyToCharge for datatype TimeDurationChargingResult
		Throws exception of which type and Summary of Exception
		*/
		ReceivingSideID* getpartyToCharge() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeInformation type of argument timeInformation for datatype TimeDurationChargingResult
		*/
		bool settimeInformation(TimeInformation* timeInformation);

		//! Function to set values
		/*!		Function to set TimeInformation type of argument timeInformation for datatype TimeDurationChargingResult
		*/
		TimeInformation* settimeInformation();

		//! Function to get values
		/*!		Function to set TimeInformation type of argument timeInformation for datatype TimeDurationChargingResult
		Throws exception of which type and Summary of Exception
		*/
		TimeInformation* gettimeInformation() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set Boolean type of argument callActive for datatype TimeDurationChargingResult
		*/
		bool setcallActive(capstd::Boolean* callActive);

		//! Function to set values
		/*!		Function to set Boolean type of argument callActive for datatype TimeDurationChargingResult
		*/
		capstd::Boolean* setcallActive();

		//! Function to get values
		/*!		Function to set Boolean type of argument callActive for datatype TimeDurationChargingResult
		Throws exception of which type and Summary of Exception
		*/
		capstd::Boolean* getcallActive() ;//throw(const char*)

		//! Function to set values as given Object
		/*!		Function to set NULL type of argument callReleasedAtTcpExpiry for datatype TimeDurationChargingResult
		*/
		bool setcallReleasedAtTcpExpiry(bool callReleasedAtTcpExpiry);

		//! Function to set new values
		/*!		Function to set NULL type of argument callReleasedAtTcpExpiry for datatype TimeDurationChargingResult
		*/
		bool* setcallReleasedAtTcpExpiry();

		//! Function to get values
		/*!		Function to get NULL type of argument callReleasedAtTcpExpiry for datatype TimeDurationChargingResult
		Throws exception of which type and Summary of Exception
		*/
		bool getcallReleasedAtTcpExpiry();

		//!Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationChargingResult
		*/
		bool setextensions(Extensions* extensions);

		//! Function to set values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationChargingResult
		*/
		Extensions* setextensions();

		//! Function to get values
		/*!		Function to set Extensions type of argument extensions for datatype TimeDurationChargingResult
		Throws exception of which type and Summary of Exception
		*/
		Extensions* getextensions() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TimeDurationChargingResult
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TimeDurationChargingResult
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TimeDurationChargingResult
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TimeDurationChargingResult
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TimeGPRSIfTariffSwitch
{
	TimeGPRSIfTariffSwitch_TIMEGPRSSINCELASTTARIFFSWITCH	=  1 << 0,
	TimeGPRSIfTariffSwitch_TIMEGPRSTARIFFSWITCHINTERVAL	=  1 << 1,
	TimeGPRSIfTariffSwitch_TAG_NULL	=  0x0000
}TimeGPRSIfTariffSwitch_tags;

		//! Class Definition
		/*!		ClassName is TimeGPRSIfTariffSwitch
		*/
class TimeGPRSIfTariffSwitch
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mtimeGPRSSinceLastTariffSwitch;

		capstd::INTEGER*		mtimeGPRSTariffSwitchInterval;


	public:
		TimeGPRSIfTariffSwitch();

		~TimeGPRSIfTariffSwitch();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSSinceLastTariffSwitch for datatype TimeGPRSIfTariffSwitch
		*/
		bool settimeGPRSSinceLastTariffSwitch(capstd::INTEGER* timeGPRSSinceLastTariffSwitch);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSSinceLastTariffSwitch for datatype TimeGPRSIfTariffSwitch
		*/
		capstd::INTEGER* settimeGPRSSinceLastTariffSwitch();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timeGPRSSinceLastTariffSwitch for datatype TimeGPRSIfTariffSwitch
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimeGPRSSinceLastTariffSwitch() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSTariffSwitchInterval for datatype TimeGPRSIfTariffSwitch
		*/
		bool settimeGPRSTariffSwitchInterval(capstd::INTEGER* timeGPRSTariffSwitchInterval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timeGPRSTariffSwitchInterval for datatype TimeGPRSIfTariffSwitch
		*/
		capstd::INTEGER* settimeGPRSTariffSwitchInterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timeGPRSTariffSwitchInterval for datatype TimeGPRSIfTariffSwitch
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimeGPRSTariffSwitchInterval() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TimeGPRSIfTariffSwitch
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TimeGPRSIfTariffSwitch
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TimeGPRSIfTariffSwitch
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TimeGPRSIfTariffSwitch
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TimeIfTariffSwitch
{
	TimeIfTariffSwitch_TIMESINCETARIFFSWITCH	=  1 << 0,
	TimeIfTariffSwitch_TARIFFSWITCHINTERVAL	=  1 << 1,
	TimeIfTariffSwitch_TAG_NULL	=  0x0000
}TimeIfTariffSwitch_tags;

		//! Class Definition
		/*!		ClassName is TimeIfTariffSwitch
		*/
class TimeIfTariffSwitch
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mtimeSinceTariffSwitch;

		capstd::INTEGER*		mtariffSwitchInterval;


	public:
		TimeIfTariffSwitch();

		~TimeIfTariffSwitch();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument timeSinceTariffSwitch for datatype TimeIfTariffSwitch
		*/
		bool settimeSinceTariffSwitch(capstd::INTEGER* timeSinceTariffSwitch);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timeSinceTariffSwitch for datatype TimeIfTariffSwitch
		*/
		capstd::INTEGER* settimeSinceTariffSwitch();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timeSinceTariffSwitch for datatype TimeIfTariffSwitch
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimeSinceTariffSwitch() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeIfTariffSwitch
		*/
		bool settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval);

		//! Function to set values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeIfTariffSwitch
		*/
		capstd::INTEGER* settariffSwitchInterval();

		//! Function to get values
		/*!		Function to set INTEGER type of argument tariffSwitchInterval for datatype TimeIfTariffSwitch
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettariffSwitchInterval() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TimeIfTariffSwitch
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TimeIfTariffSwitch
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TimeIfTariffSwitch
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TimeIfTariffSwitch
		*/
		bool ValidateMandatory(char *errStr);

};
typedef enum _tags_TimeInformation
{
	TimeInformation_TIMEIFNOTARIFFSWITCH	=  1 << 0,
	TimeInformation_TIMEIFTARIFFSWITCH	=  1 << 1,
	TimeInformation_TAG_NULL	=  0x0000
}TimeInformation_tags;

		//! Class Definition
		/*!		ClassName is TimeInformation
		*/
class TimeInformation
{
	private:

		bool mParamSet;

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mtimeIfNoTariffSwitch;

		TimeIfTariffSwitch*		mtimeIfTariffSwitch;


	public:
		TimeInformation();

		~TimeInformation();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument timeIfNoTariffSwitch for datatype TimeInformation
		*/
		bool settimeIfNoTariffSwitch(capstd::INTEGER* timeIfNoTariffSwitch);

		//! Function to set values
		/*!		Function to set INTEGER type of argument timeIfNoTariffSwitch for datatype TimeInformation
		*/
		capstd::INTEGER* settimeIfNoTariffSwitch();

		//! Function to get values
		/*!		Function to set INTEGER type of argument timeIfNoTariffSwitch for datatype TimeInformation
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettimeIfNoTariffSwitch() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set TimeIfTariffSwitch type of argument timeIfTariffSwitch for datatype TimeInformation
		*/
		bool settimeIfTariffSwitch(TimeIfTariffSwitch* timeIfTariffSwitch);

		//! Function to set values
		/*!		Function to set TimeIfTariffSwitch type of argument timeIfTariffSwitch for datatype TimeInformation
		*/
		TimeIfTariffSwitch* settimeIfTariffSwitch();

		//! Function to get values
		/*!		Function to set TimeIfTariffSwitch type of argument timeIfTariffSwitch for datatype TimeInformation
		Throws exception of which type and Summary of Exception
		*/
		TimeIfTariffSwitch* gettimeIfTariffSwitch() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype TimeInformation
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype TimeInformation
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TimeInformation
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags TimeInformation
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(TIMERID,
	(tssf, "tssf", 0X0000)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype TimerID
		*/
class TimerID
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		TIMERID mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype TimerID
		*/
		TimerID();

		//!Destructor Function
		/*!		Destructor for datatype TimeIfTariffSwitch
		*/
		~TimerID();

		//!Function to set values
		/*!		Function to set ENUM type for datatype TimerID
		*/
		bool setValue(TIMERID val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype TimerID
		*/
		TIMERID getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype TimerID
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype TimerID
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype TimerID
		*/
		int Display(int tab);

};
typedef enum _tags_Tone
{
	Tone_TONEID	=  1 << 0,
	Tone_DURATION	=  1 << 1,
	Tone_TAG_NULL	=  0x0000
}Tone_tags;

		//! Class Definition
		/*!		ClassName is Tone
		*/
class Tone
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		mtoneID;

		capstd::INTEGER*		mduration;


	public:
		Tone();

		~Tone();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument toneID for datatype Tone
		*/
		bool settoneID(capstd::INTEGER* toneID);

		//! Function to set values
		/*!		Function to set INTEGER type of argument toneID for datatype Tone
		*/
		capstd::INTEGER* settoneID();

		//! Function to get values
		/*!		Function to set INTEGER type of argument toneID for datatype Tone
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* gettoneID() ;//throw(const char*)

		//!Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype Tone
		*/
		bool setduration(capstd::INTEGER* duration);

		//! Function to set values
		/*!		Function to set INTEGER type of argument duration for datatype Tone
		*/
		capstd::INTEGER* setduration();

		//! Function to get values
		/*!		Function to set INTEGER type of argument duration for datatype Tone
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getduration() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype Tone
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype Tone
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Tone
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags Tone
		*/
		bool ValidateMandatory(char *errStr);

};

TSS_ENUM(USED_RAT_TYPE,
	(utran, "utran", 	 0X0000)
	(geran, "geran", 	 0X0001)
	(gan, "gan", 	 0X0002)
	(i_hspa_evolution, "i_hspa_evolution", 	 0X0003)
	(e_utran, "e_utran", 0X0004)
);

		//!Creating Enum Class
		/*!		Creating Enumerated Class of Datatype Used_RAT_Type
		*/
class Used_RAT_Type
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTag;

		USED_RAT_TYPE mValue;


	public:
		//!Constructor Function
		/*!		Constructor for datatype Used_RAT_Type
		*/
		Used_RAT_Type();

		//!Destructor Function
		/*!		Destructor for datatype OctetString
		*/
		~Used_RAT_Type();

		//!Function to set values
		/*!		Function to set ENUM type for datatype Used_RAT_Type
		*/
		bool setValue(USED_RAT_TYPE val);

		//!Function to get values
		/*!		Function to get ENUM type for datatype Used_RAT_Type
		*/
		USED_RAT_TYPE getValue();

		//!Function to Decode
		/*!		Function to Decode ENUM type for datatype Used_RAT_Type
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed);
		//!Function to Encode
		/*!		Function to Encode ENUM type for datatype Used_RAT_Type
		*/
		int Encode(capstd::byteArray *array);
		//!Function to Display values
		/*!		Function to Display ENUM type datatype Used_RAT_Type
		*/
		int Display(int tab);

};
typedef enum _tags_VariableMessage
{
	VariableMessage_ELEMENTARYMESSAGEID	=  1 << 0,
	VariableMessage_TAG_NULL	=  0x0000
}VariableMessage_tags;

		//! Class Definition
		/*!		ClassName is VariableMessage
		*/
class VariableMessage
{
	private:

		vector<capstd::Parameter> mParamList;

		unsigned mTagsPresent;

		unsigned mTag;

		vector<unsigned> mTagArray;

		vector<bool> mTagOptional;

		capstd::INTEGER*		melementaryMessageID;


	public:
		VariableMessage();

		~VariableMessage();

		bool isPresent(int);

		//!Function to set values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype VariableMessage
		*/
		bool setelementaryMessageID(capstd::INTEGER* elementaryMessageID);

		//! Function to set values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype VariableMessage
		*/
		capstd::INTEGER* setelementaryMessageID();

		//! Function to get values
		/*!		Function to set INTEGER type of argument elementaryMessageID for datatype VariableMessage
		Throws exception of which type and Summary of Exception
		*/
		capstd::INTEGER* getelementaryMessageID() ;//throw(const char*)

		//! Function to Decode
		/*!		Function to Decode datatype VariableMessage
		lengthDecode should be false for Choice Datatype with no tag in sequence of
		*/
		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		//! Function to Encode
		/*!		Function to Encode datatype VariableMessage
		*/
		int Encode(capstd::byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype VariableMessage
		*/
		int Display(int tab);

		//! Function to check mandatory params
		/*!		Function to validate mandatory tags VariableMessage
		*/
		bool ValidateMandatory(char *errStr);

};

class bcsmEvents
{
	private:

		vector<BCSMEvent *> mParamList;

		BCSMEvent*  mBCSMEvent;

		unsigned mTag;

		unsigned mCounter;

		unsigned mCurrentLocation;

		unsigned mMinSize;

		unsigned mMaxSize;

		bool CheckBoundary();


	public:
		bcsmEvents();

		~bcsmEvents();

		bool setBCSMEvent(BCSMEvent* bCSMEvent);

		BCSMEvent* setBCSMEvent();

		BCSMEvent* setNewBCSMEvent();

		//!Function to get First value in the set and reset the counter to the begining
		/*!		Function to get First BCSMEvent type of argument BCSMEvent for datatype bcsmEvents list
		Throws exception of which type and Summary of Exception
		*/
		BCSMEvent* getBCSMEvent() ;//throw(const char*)

		//!Function to get value at given location, location starts from 0
		/*!		Function to get value BCSMEvent type of argument BCSMEvent for datatype bcsmEvents at given location
		Throws exception of which type and Summary of Exception
		*/
		BCSMEvent* getBCSMEventAtLocation(unsigned location) ;//throw(const char*)

		BCSMEvent* setNextBCSMEvent();

		//!Function to get Next value in the set, NULL if this function calls more then received items
		/*!		Function to get Next BCSMEvent type of argument BCSMEvent for datatype bcsmEvents list
		Throws exception of which type and Summary of Exception
		*/
		BCSMEvent* getNextBCSMEvent() ;//throw(const char*)

		unsigned getNoOfBCSMEvent();

		int Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode = true);
		int Encode(capstd::byteArray *array);
		int Display(int tab);

};

}


#endif
