#include "ApplyChargingReportArg.h"

using namespace capphase3;

ApplyChargingReportArg::ApplyChargingReportArg()
{
	mcallReult = NULL;
	mtimeduration = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A2, 0X00A0};
	mTagOptional = {true, false};
}

ApplyChargingReportArg::~ApplyChargingReportArg()
{
	if(mcallReult != NULL)
		delete mcallReult;
	if(mtimeduration != NULL)
		delete mtimeduration;
}

CAMEL_CallResult* ApplyChargingReportArg::setcallReult(){
	if(mcallReult == NULL)
	{
		mcallReult = new CAMEL_CallResult();
		mTagsPresent |= ApplyChargingReportArg_CALLREULT;
		return mcallReult;
	}
	else
		return mcallReult;

}

bool ApplyChargingReportArg::setcallReult(CAMEL_CallResult* callReult){
	if(mcallReult == NULL)
	{
		return -1;
	}
	else
	{
		mcallReult = callReult;
		return true;
	}

}

TimeDurationChargingResult* ApplyChargingReportArg::settimeduration(){
	if(mtimeduration == NULL)
	{
		mtimeduration = new TimeDurationChargingResult();
		mTagsPresent |= ApplyChargingReportArg_TIMEDURATION;
		return mtimeduration;
	}
	else
		return mtimeduration;

}

bool ApplyChargingReportArg::settimeduration(TimeDurationChargingResult* timeduration){
	if(mtimeduration == NULL)
	{
		return -1;
	}
	else
	{
		mtimeduration = timeduration;
		return true;
	}

}

CAMEL_CallResult* ApplyChargingReportArg::getcallReult() {//throw(const char*)
	if(NULL == mcallReult)
		throw("Object callReult is NULL");
	else
		return mcallReult;
}

TimeDurationChargingResult* ApplyChargingReportArg::gettimeduration() {//throw(const char*)
	if(NULL == mtimeduration)
		throw("Object timeduration is NULL");
	else
		return mtimeduration;
}

bool ApplyChargingReportArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ApplyChargingReportArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X00A2:
				if(NULL == this->setcallReult())
					return -1;
				if(mcallReult->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A0:
				if(NULL == this->settimeduration())
					return -1;
				if(mtimeduration->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ApplyChargingReportArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ApplyChargingReportArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ApplyChargingReportArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ApplyChargingReportArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ApplyChargingReportArg_CALLREULT:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallReult->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ApplyChargingReportArg_TIMEDURATION:
				if(asn1_tag_encode(48, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeduration->Encode(array) < 0) || 
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

int ApplyChargingReportArg::Display(int tab){
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
			case ApplyChargingReportArg_CALLREULT:
			{
				printf(temp, " ", "callReult");
				if(mcallReult->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ApplyChargingReportArg_TIMEDURATION:
			{
				printf(temp, " ", "timeduration");
				if(mtimeduration->Display(tab+1) < 0)
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

bool ApplyChargingReportArg::ValidateMandatory(char *errStr){
	if(NULL == mtimeduration)
	{
		strcpy(errStr, "timeduration");
		return false;
	}

	return true;
}
