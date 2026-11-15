static const char *id = " @(#) $Id: ResetTimerSMSArg.cc,v 1.1.2.3 2019/06/29 02:24:32 mrafi Exp $";

#include "ResetTimerSMSArg.h"

using namespace capphase3;

ResetTimerSMSArg::ResetTimerSMSArg()
{
	timerIDDefault = new TimerID();
	timerIDDefault->setValue(tssf);;
	mtimerID = NULL;
	mtimervalue = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X00A2};
	mTagOptional = {false, false, true};
}

ResetTimerSMSArg::~ResetTimerSMSArg()
{
	if(mtimerID != NULL)
		delete mtimerID;
	if(timerIDDefault != NULL)
		delete timerIDDefault;
	if(mtimervalue != NULL)
		delete mtimervalue;
	if(mextensions != NULL)
		delete mextensions;
}

TimerID* ResetTimerSMSArg::settimerID(){
	if(mtimerID == NULL)
	{
		mtimerID = new TimerID();
		mTagsPresent |= ResetTimerSMSArg_TIMERID;
		return mtimerID;
	}
	else
		return mtimerID;

}

bool ResetTimerSMSArg::settimerID(TimerID* timerID){
	if(mtimerID == NULL)
	{
		return -1;
	}
	else
	{
		mtimerID = timerID;
		return true;
	}

}

capstd::capstd::INTEGER* ResetTimerSMSArg::settimervalue(){
	if(mtimervalue == NULL)
	{
		mtimervalue = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= ResetTimerSMSArg_TIMERVALUE;
		return mtimervalue;
	}
	else
		return mtimervalue;

}

bool ResetTimerSMSArg::settimervalue(capstd::capstd::INTEGER* timervalue){
	if(mtimervalue == NULL)
	{
		return -1;
	}
	else
	{
		mtimervalue = timervalue;
		return true;
	}

}

Extensions* ResetTimerSMSArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ResetTimerSMSArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ResetTimerSMSArg::setextensions(Extensions* extensions){
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

TimerID* ResetTimerSMSArg::gettimerID()  { // //{//throw(const char*)
	if(NULL == mtimerID)
		throw("Object timerID is NULL");
	else
		return mtimerID;
}

capstd::capstd::INTEGER* ResetTimerSMSArg::gettimervalue()  { // //{//throw(const char*)
	if(NULL == mtimervalue)
		throw("Object timervalue is NULL");
	else
		return mtimervalue;
}

Extensions* ResetTimerSMSArg::getextensions()  { // //{//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool ResetTimerSMSArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ResetTimerSMSArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0, lengthSize = 0;
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
				if(NULL == this->settimerID())
					return -1;
				if(mtimerID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->settimervalue())
					return -1;
				if(mtimervalue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ResetTimerSMSArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ResetTimerSMSArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ResetTimerSMSArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ResetTimerSMSArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ResetTimerSMSArg_TIMERID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimerID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ResetTimerSMSArg_TIMERVALUE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimervalue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ResetTimerSMSArg_EXTENSIONS:
				if(asn1_tag_encode(162, array) < 0)
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

int ResetTimerSMSArg::Display(int tab){
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
			case ResetTimerSMSArg_TIMERID:
			{
				printf(temp, " ", "timerID");
				if(mtimerID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ResetTimerSMSArg_TIMERVALUE:
			{
				printf(temp, " ", "timervalue");
				if(mtimervalue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ResetTimerSMSArg_EXTENSIONS:
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

bool ResetTimerSMSArg::ValidateMandatory(char *errStr){
	if(NULL == mtimerID)
	{
		strcpy(errStr, "timerID");
		return false;
	}
	else if(NULL == mtimervalue)
	{
		strcpy(errStr, "timervalue");
		return false;
	}

	return true;
}
