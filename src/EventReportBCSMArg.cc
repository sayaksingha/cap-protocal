#include "EventReportBCSMArg.h"

using namespace capphase3;

EventReportBCSMArg::EventReportBCSMArg()
{
	meventTypeBCSM = NULL;
	meventSpecificInformationBCSM = NULL;
	mlegID = NULL;
	mmiscCallInfo = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X00A2, 0X00A3, 0X00A4, 0X00A5};
	mTagOptional = {false, true, true, false, true};
}

EventReportBCSMArg::~EventReportBCSMArg()
{
	if(meventTypeBCSM != NULL)
		delete meventTypeBCSM;
	if(meventSpecificInformationBCSM != NULL)
		delete meventSpecificInformationBCSM;
	if(mlegID != NULL)
		delete mlegID;
	if(mmiscCallInfo != NULL)
		delete mmiscCallInfo;
	if(mextensions != NULL)
		delete mextensions;
}

EventTypeBCSM* EventReportBCSMArg::seteventTypeBCSM(){
	if(meventTypeBCSM == NULL)
	{
		meventTypeBCSM = new EventTypeBCSM();
		mTagsPresent |= EventReportBCSMArg_EVENTTYPEBCSM;
		return meventTypeBCSM;
	}
	else
		return meventTypeBCSM;

}

bool EventReportBCSMArg::seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM){
	if(meventTypeBCSM == NULL)
	{
		return -1;
	}
	else
	{
		meventTypeBCSM = eventTypeBCSM;
		return true;
	}

}

EventSpecificInformationBCSM* EventReportBCSMArg::seteventSpecificInformationBCSM(){
	if(meventSpecificInformationBCSM == NULL)
	{
		meventSpecificInformationBCSM = new EventSpecificInformationBCSM();
		mTagsPresent |= EventReportBCSMArg_EVENTSPECIFICINFORMATIONBCSM;
		return meventSpecificInformationBCSM;
	}
	else
		return meventSpecificInformationBCSM;

}

bool EventReportBCSMArg::seteventSpecificInformationBCSM(EventSpecificInformationBCSM* eventSpecificInformationBCSM){
	if(meventSpecificInformationBCSM == NULL)
	{
		return -1;
	}
	else
	{
		meventSpecificInformationBCSM = eventSpecificInformationBCSM;
		return true;
	}

}

ReceivingSideID* EventReportBCSMArg::setlegID(){
	if(mlegID == NULL)
	{
		mlegID = new ReceivingSideID();
		mTagsPresent |= EventReportBCSMArg_LEGID;
		return mlegID;
	}
	else
		return mlegID;

}

bool EventReportBCSMArg::setlegID(ReceivingSideID* legID){
	if(mlegID == NULL)
	{
		return -1;
	}
	else
	{
		mlegID = legID;
		return true;
	}

}

MiscCallInfo* EventReportBCSMArg::setmiscCallInfo(){
	if(mmiscCallInfo == NULL)
	{
		mmiscCallInfo = new MiscCallInfo();
		mTagsPresent |= EventReportBCSMArg_MISCCALLINFO;
		return mmiscCallInfo;
	}
	else
		return mmiscCallInfo;

}

bool EventReportBCSMArg::setmiscCallInfo(MiscCallInfo* miscCallInfo){
	if(mmiscCallInfo == NULL)
	{
		return -1;
	}
	else
	{
		mmiscCallInfo = miscCallInfo;
		return true;
	}

}

Extensions* EventReportBCSMArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= EventReportBCSMArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool EventReportBCSMArg::setextensions(Extensions* extensions){
	if(mextensions == NULL)
	{
		return -1;
	}
	else
	{
		mextensions = extensions;
		return true;
	}

}

EventTypeBCSM* EventReportBCSMArg::geteventTypeBCSM() {//throw(const char*)
	if(NULL == meventTypeBCSM)
		throw("Object eventTypeBCSM is NULL");
	else
		return meventTypeBCSM;
}

EventSpecificInformationBCSM* EventReportBCSMArg::geteventSpecificInformationBCSM() {//throw(const char*)
	if(NULL == meventSpecificInformationBCSM)
		throw("Object eventSpecificInformationBCSM is NULL");
	else
		return meventSpecificInformationBCSM;
}

ReceivingSideID* EventReportBCSMArg::getlegID() {//throw(const char*)
	if(NULL == mlegID)
		throw("Object legID is NULL");
	else
		return mlegID;
}

MiscCallInfo* EventReportBCSMArg::getmiscCallInfo() {//throw(const char*)
	if(NULL == mmiscCallInfo)
		throw("Object miscCallInfo is NULL");
	else
		return mmiscCallInfo;
}

Extensions* EventReportBCSMArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool EventReportBCSMArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int EventReportBCSMArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	unsigned tag = 0;
	asn1_tag_get(array, &tag);
	(*bytesParsed) = 0;

	//This is for the sequence of choice datatype with no tag given to choice datatype
	if(lengthDecode)
	{
		lengthSize = asn1_length_decode(array, &definite, &length);

		if(-1 == lengthSize)
			return -1;
		if(!definite)
		{
			length = 1;
		}
	}
	else
		length = 1;
	while(length && decode)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0080:
				if(NULL == this->seteventTypeBCSM())
					return -1;
				if(meventTypeBCSM->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->seteventSpecificInformationBCSM())
					return -1;
				if(meventSpecificInformationBCSM->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setlegID())
					return -1;
				if(mlegID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setmiscCallInfo())
					return -1;
				if(mmiscCallInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A5:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: EventReportBCSMArg Tag:%d Offset:%d\n", tag, array->offset);
				if(asn1_skip_unknown(array, &bytesDecoded) < 0)
					return -1;
		}
		if(!definite)
		{
			if((array->byte[array->offset] == 0x00 && array->byte[array->offset + 1] == 0x00) || !decode)
			{
				length += bytesDecoded + tagSize;
				array->offset += 2;
				(*bytesParsed) += length - 1 + 2;
				break;
			}
			if(array->size < array->offset)
			{
				length += bytesDecoded + tagSize;
				(*bytesParsed) += length - 1 + 2;
				printf("not found eoc size %d offset %d", array->size, array->offset);
				return -1;
			}
			(*bytesParsed) += bytesDecoded + tagSize;
		}
		else
		{
			(*bytesParsed) += bytesDecoded + tagSize;
			length -= bytesDecoded + tagSize;
			if(length < 0 || (array->size < array->offset))
				return -1;
		}
	}
	(*bytesParsed) += lengthSize;
	if(!decode)
		return -1;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("EventReportBCSMArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int EventReportBCSMArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("EventReportBCSMArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	if(asn1_tag_encode(mTag, array) < 0)
		return -1;

	lLengthOffset = array->offset++;
	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case EventReportBCSMArg_EVENTTYPEBCSM:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meventTypeBCSM->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EventReportBCSMArg_EVENTSPECIFICINFORMATIONBCSM:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meventSpecificInformationBCSM->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EventReportBCSMArg_LEGID:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlegID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EventReportBCSMArg_MISCCALLINFO:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmiscCallInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case EventReportBCSMArg_EXTENSIONS:
				if(asn1_tag_encode(165, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	if(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0)
		return -1;

	return 0;
}

int EventReportBCSMArg::Display(int tab){
	unsigned lTemp = 0;
	char temp[30];
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));
	sprintf(temp, "%%%ds %%s\n", tab * 3);

	while(lTemp)
	{
		switch(lSwitchTemp)
		{
			case EventReportBCSMArg_EVENTTYPEBCSM:
			{
				printf(temp, " ", "eventTypeBCSM");
				if(meventTypeBCSM->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventReportBCSMArg_EVENTSPECIFICINFORMATIONBCSM:
			{
				printf(temp, " ", "eventSpecificInformationBCSM");
				if(meventSpecificInformationBCSM->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventReportBCSMArg_LEGID:
			{
				printf(temp, " ", "legID");
				if(mlegID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventReportBCSMArg_MISCCALLINFO:
			{
				printf(temp, " ", "miscCallInfo");
				if(mmiscCallInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventReportBCSMArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
					return -1;
				break;
			}
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	return 1;
}

bool EventReportBCSMArg::ValidateMandatory(char *errStr){
	if(NULL == meventTypeBCSM)
	{
		strcpy(errStr, "eventTypeBCSM");
		return false;
	}
	else if(NULL == mmiscCallInfo)
	{
		strcpy(errStr, "miscCallInfo");
		return false;
	}

	return true;
}
