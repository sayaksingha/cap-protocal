static const char *id = " @(#) $Id: RequestReportSMSEventArg.cc,v 1.1.2.3 2019/06/29 02:24:32 mrafi Exp $";

#include "RequestReportSMSEventArg.h"

using namespace capphase3;

RequestReportSMSEventArg::RequestReportSMSEventArg()
{
	mCounter = 0;
	mMinNoOfSMSEvent = 1;
	mMaxNoOfSMSEvent = 10;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00AA};
	mTagOptional = {false, true};
}

RequestReportSMSEventArg::~RequestReportSMSEventArg()
{
	vector<SMSEvent *>::iterator lParam = msMSEventsList.begin();
	while(msMSEventsList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	msMSEventsList.clear();
	if(mextensions != NULL)
		delete mextensions;
}

bool RequestReportSMSEventArg::CheckSMSEventBoundary()
{
	if(mCounter < mMinNoOfSMSEvent || mCounter > mMaxNoOfSMSEvent)
		return -1;

	return true;
}

SMSEvent* RequestReportSMSEventArg::setNewsMSEvents()
{
	msMSEvents = new SMSEvent();
	if(NULL == msMSEvents)
		return NULL;
	mTagsPresent |= RequestReportSMSEventArg_SMSEVENTS;
	msMSEventsList.push_back(msMSEvents);
	mCounter++;
	if(!this->CheckSMSEventBoundary())
		return NULL;

	return msMSEvents;
}

SMSEvent* RequestReportSMSEventArg::setsMSEvents(){
	if(msMSEvents == NULL)
	{
		msMSEvents = new SMSEvent();
		mTagsPresent |= RequestReportSMSEventArg_SMSEVENTS;
		return msMSEvents;
	}
	else
		return msMSEvents;

}

bool RequestReportSMSEventArg::setsMSEvents(SMSEvent* sMSEvents){
	if(msMSEvents == NULL)
	{
		return -1;
	}
	else
	{
		msMSEvents = sMSEvents;
		return true;
	}

}

Extensions* RequestReportSMSEventArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= RequestReportSMSEventArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool RequestReportSMSEventArg::setextensions(Extensions* extensions){
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

SMSEvent* RequestReportSMSEventArg::getsMSEvents()  { // //{//throw(const char*)
	if(NULL == msMSEvents)
		throw("Object sMSEvents is NULL");
	else
		return msMSEvents;
}

Extensions* RequestReportSMSEventArg::getextensions()  { // //{//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool RequestReportSMSEventArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int RequestReportSMSEventArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X00A0:
				if(this->DecodeSeqOfSMSEvent(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AA:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: RequestReportSMSEventArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("RequestReportSMSEventArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int RequestReportSMSEventArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("RequestReportSMSEventArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case RequestReportSMSEventArg_SMSEVENTS:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msMSEvents->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case RequestReportSMSEventArg_EXTENSIONS:
				if(asn1_tag_encode(170, array) < 0)
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

int RequestReportSMSEventArg::Display(int tab){
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
			case RequestReportSMSEventArg_SMSEVENTS:
			{
				printf(temp, " ", "sMSEvents");
				vector<SMSEvent *>::iterator lParam = msMSEventsList.begin();

				while(lParam != msMSEventsList.end())
				{
					printf(temp, " ", "SMSEvent");
					(*lParam)->Display(tab+1);
					lParam++;
				}
				break;
			}
			case RequestReportSMSEventArg_EXTENSIONS:
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

bool RequestReportSMSEventArg::ValidateMandatory(char *errStr){
	if(NULL == msMSEvents)
	{
		strcpy(errStr, "sMSEvents");
		return false;
	}

	return true;
}
int RequestReportSMSEventArg::DecodeSeqOfSMSEvent(capstd::capstd::byteArray  *array, unsigned *bytesParsed)
{
	bool    definite = true, decode = true;
	unsigned length = 0, lengthSize = 0;
	unsigned bytesDecoded = 0;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);


	if(-1 == lengthSize)
		return -1;
	if(!definite)
	{
		length = 1;
	}

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
			case 0X0030:
				this->setNewsMSEvents();
				if(msMSEvents->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				if(asn1_skip_unknown(array, &bytesDecoded) < 0)
					return -1;
				break;
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
			if(length < 0)
				return -1;
		}
	}
	(*bytesParsed) += lengthSize;
	if(!decode)
		return -1;

	return true;
}
