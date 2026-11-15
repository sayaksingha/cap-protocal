#include "CapDataTypes.h"

using namespace capphase3;

AOCBeforeAnswer::AOCBeforeAnswer()
{
	maOCInitial = NULL;
	maOCSubsequent = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1};
	mTagOptional = {false, true};
}

AOCBeforeAnswer::~AOCBeforeAnswer()
{
	if(maOCInitial != NULL)
		delete maOCInitial;
	if(maOCSubsequent != NULL)
		delete maOCSubsequent;
}

CAI_GSM0224* AOCBeforeAnswer::setaOCInitial(){
	if(maOCInitial == NULL)
	{
		maOCInitial = new CAI_GSM0224();
		mTagsPresent |= AOCBeforeAnswer_AOCINITIAL;
		return maOCInitial;
	}
	else
		return maOCInitial;

}

bool AOCBeforeAnswer::setaOCInitial(CAI_GSM0224* aOCInitial){
	if(maOCInitial == NULL)
	{
		return -1;
	}
	else
	{
		maOCInitial = aOCInitial;
		return true;
	}

}

AOCSubsequent* AOCBeforeAnswer::setaOCSubsequent(){
	if(maOCSubsequent == NULL)
	{
		maOCSubsequent = new AOCSubsequent();
		mTagsPresent |= AOCBeforeAnswer_AOCSUBSEQUENT;
		return maOCSubsequent;
	}
	else
		return maOCSubsequent;

}

bool AOCBeforeAnswer::setaOCSubsequent(AOCSubsequent* aOCSubsequent){
	if(maOCSubsequent == NULL)
	{
		return -1;
	}
	else
	{
		maOCSubsequent = aOCSubsequent;
		return true;
	}

}

CAI_GSM0224* AOCBeforeAnswer::getaOCInitial() {//throw(const char*)
	if(NULL == maOCInitial)
		throw("Object aOCInitial is NULL");
	else
		return maOCInitial;
}

AOCSubsequent* AOCBeforeAnswer::getaOCSubsequent() {//throw(const char*)
	if(NULL == maOCSubsequent)
		throw("Object aOCSubsequent is NULL");
	else
		return maOCSubsequent;
}

bool AOCBeforeAnswer::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AOCBeforeAnswer::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setaOCInitial())
					return -1;
				if(maOCInitial->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setaOCSubsequent())
					return -1;
				if(maOCSubsequent->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AOCBeforeAnswer Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AOCBeforeAnswer: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AOCBeforeAnswer::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AOCBeforeAnswer: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case AOCBeforeAnswer_AOCINITIAL:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCInitial->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AOCBeforeAnswer_AOCSUBSEQUENT:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCSubsequent->Encode(array) < 0) || 
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

	return 0;
}

int AOCBeforeAnswer::Display(int tab){
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
			case AOCBeforeAnswer_AOCINITIAL:
			{
				printf(temp, " ", "aOCInitial");
				if(maOCInitial->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AOCBeforeAnswer_AOCSUBSEQUENT:
			{
				printf(temp, " ", "aOCSubsequent");
				if(maOCSubsequent->Display(tab+1) < 0)
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

bool AOCBeforeAnswer::ValidateMandatory(char *errStr){
	if(NULL == maOCInitial)
	{
		strcpy(errStr, "aOCInitial");
		return false;
	}

	return true;
}
AOCGPRS::AOCGPRS()
{
	maOCInitial = NULL;
	maOCSubsequent = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1};
	mTagOptional = {false, true};
}

AOCGPRS::~AOCGPRS()
{
	if(maOCInitial != NULL)
		delete maOCInitial;
	if(maOCSubsequent != NULL)
		delete maOCSubsequent;
}

CAI_GSM0224* AOCGPRS::setaOCInitial(){
	if(maOCInitial == NULL)
	{
		maOCInitial = new CAI_GSM0224();
		mTagsPresent |= AOCGPRS_AOCINITIAL;
		return maOCInitial;
	}
	else
		return maOCInitial;

}

bool AOCGPRS::setaOCInitial(CAI_GSM0224* aOCInitial){
	if(maOCInitial == NULL)
	{
		return -1;
	}
	else
	{
		maOCInitial = aOCInitial;
		return true;
	}

}

AOCSubsequent* AOCGPRS::setaOCSubsequent(){
	if(maOCSubsequent == NULL)
	{
		maOCSubsequent = new AOCSubsequent();
		mTagsPresent |= AOCGPRS_AOCSUBSEQUENT;
		return maOCSubsequent;
	}
	else
		return maOCSubsequent;

}

bool AOCGPRS::setaOCSubsequent(AOCSubsequent* aOCSubsequent){
	if(maOCSubsequent == NULL)
	{
		return -1;
	}
	else
	{
		maOCSubsequent = aOCSubsequent;
		return true;
	}

}

CAI_GSM0224* AOCGPRS::getaOCInitial() {//throw(const char*)
	if(NULL == maOCInitial)
		throw("Object aOCInitial is NULL");
	else
		return maOCInitial;
}

AOCSubsequent* AOCGPRS::getaOCSubsequent() {//throw(const char*)
	if(NULL == maOCSubsequent)
		throw("Object aOCSubsequent is NULL");
	else
		return maOCSubsequent;
}

bool AOCGPRS::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AOCGPRS::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setaOCInitial())
					return -1;
				if(maOCInitial->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setaOCSubsequent())
					return -1;
				if(maOCSubsequent->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AOCGPRS Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AOCGPRS: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AOCGPRS::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AOCGPRS: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case AOCGPRS_AOCINITIAL:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCInitial->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AOCGPRS_AOCSUBSEQUENT:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCSubsequent->Encode(array) < 0) || 
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

	return 0;
}

int AOCGPRS::Display(int tab){
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
			case AOCGPRS_AOCINITIAL:
			{
				printf(temp, " ", "aOCInitial");
				if(maOCInitial->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AOCGPRS_AOCSUBSEQUENT:
			{
				printf(temp, " ", "aOCSubsequent");
				if(maOCSubsequent->Display(tab+1) < 0)
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

bool AOCGPRS::ValidateMandatory(char *errStr){
	if(NULL == maOCInitial)
	{
		strcpy(errStr, "aOCInitial");
		return false;
	}

	return true;
}
AOCSubsequent::AOCSubsequent()
{
	mcAI_GSM0224 = NULL;
	mtariffSwitchInterval = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081};
	mTagOptional = {false, true};
}

AOCSubsequent::~AOCSubsequent()
{
	if(mcAI_GSM0224 != NULL)
		delete mcAI_GSM0224;
	if(mtariffSwitchInterval != NULL)
		delete mtariffSwitchInterval;
}

CAI_GSM0224* AOCSubsequent::setcAI_GSM0224(){
	if(mcAI_GSM0224 == NULL)
	{
		mcAI_GSM0224 = new CAI_GSM0224();
		mTagsPresent |= AOCSubsequent_CAI_GSM0224;
		return mcAI_GSM0224;
	}
	else
		return mcAI_GSM0224;

}

bool AOCSubsequent::setcAI_GSM0224(CAI_GSM0224* cAI_GSM0224){
	if(mcAI_GSM0224 == NULL)
	{
		return -1;
	}
	else
	{
		mcAI_GSM0224 = cAI_GSM0224;
		return true;
	}

}

capstd::INTEGER* AOCSubsequent::settariffSwitchInterval(){
	if(mtariffSwitchInterval == NULL)
	{
		mtariffSwitchInterval = new capstd::INTEGER(1, 86400);
		mTagsPresent |= AOCSubsequent_TARIFFSWITCHINTERVAL;
		return mtariffSwitchInterval;
	}
	else
		return mtariffSwitchInterval;

}

bool AOCSubsequent::settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval){
	if(mtariffSwitchInterval == NULL)
	{
		return -1;
	}
	else
	{
		mtariffSwitchInterval = tariffSwitchInterval;
		return true;
	}

}

CAI_GSM0224* AOCSubsequent::getcAI_GSM0224() {//throw(const char*)
	if(NULL == mcAI_GSM0224)
		throw("Object cAI_GSM0224 is NULL");
	else
		return mcAI_GSM0224;
}

capstd::INTEGER* AOCSubsequent::gettariffSwitchInterval() {//throw(const char*)
	if(NULL == mtariffSwitchInterval)
		throw("Object tariffSwitchInterval is NULL");
	else
		return mtariffSwitchInterval;
}

bool AOCSubsequent::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int AOCSubsequent::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setcAI_GSM0224())
					return -1;
				if(mcAI_GSM0224->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->settariffSwitchInterval())
					return -1;
				if(mtariffSwitchInterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: AOCSubsequent Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("AOCSubsequent: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int AOCSubsequent::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("AOCSubsequent: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case AOCSubsequent_CAI_GSM0224:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcAI_GSM0224->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case AOCSubsequent_TARIFFSWITCHINTERVAL:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtariffSwitchInterval->Encode(array) < 0) || 
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

	return 0;
}

int AOCSubsequent::Display(int tab){
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
			case AOCSubsequent_CAI_GSM0224:
			{
				printf(temp, " ", "cAI_GSM0224");
				if(mcAI_GSM0224->Display(tab+1) < 0)
					return -1;
				break;
			}
			case AOCSubsequent_TARIFFSWITCHINTERVAL:
			{
				printf(temp, " ", "tariffSwitchInterval");
				if(mtariffSwitchInterval->Display(tab+1) < 0)
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

bool AOCSubsequent::ValidateMandatory(char *errStr){
	if(NULL == mcAI_GSM0224)
	{
		strcpy(errStr, "cAI_GSM0224");
		return false;
	}

	return true;
}

AppendFreeFormatData::AppendFreeFormatData()
{
	mTag = 0X000A;
}

AppendFreeFormatData::~AppendFreeFormatData()
{
}

bool AppendFreeFormatData::setValue(APPENDFREEFORMATDATA val)
{
	mValue = val;
	return true;
}

APPENDFREEFORMATDATA AppendFreeFormatData::getValue()
{
	return mValue;
}

int AppendFreeFormatData::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (APPENDFREEFORMATDATA)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int AppendFreeFormatData::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int AppendFreeFormatData::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", APPENDFREEFORMATDATA_str(mValue), mValue);
	return 0;
}

BCSMEvent::BCSMEvent()
{
	meventTypeBCSM = NULL;
	mmonitorMode = NULL;
	mlegID = NULL;
	mdpSpecificCriteria = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X00A2, 0X00BE};
	mTagOptional = {false, false, true, true};
}

BCSMEvent::~BCSMEvent()
{
	if(meventTypeBCSM != NULL)
		delete meventTypeBCSM;
	if(mmonitorMode != NULL)
		delete mmonitorMode;
	if(mlegID != NULL)
		delete mlegID;
	if(mdpSpecificCriteria != NULL)
		delete mdpSpecificCriteria;
}

EventTypeBCSM* BCSMEvent::seteventTypeBCSM(){
	if(meventTypeBCSM == NULL)
	{
		meventTypeBCSM = new EventTypeBCSM();
		mTagsPresent |= BCSMEvent_EVENTTYPEBCSM;
		return meventTypeBCSM;
	}
	else
		return meventTypeBCSM;

}

bool BCSMEvent::seteventTypeBCSM(EventTypeBCSM* eventTypeBCSM){
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

MonitorMode* BCSMEvent::setmonitorMode(){
	if(mmonitorMode == NULL)
	{
		mmonitorMode = new MonitorMode();
		mTagsPresent |= BCSMEvent_MONITORMODE;
		return mmonitorMode;
	}
	else
		return mmonitorMode;

}

bool BCSMEvent::setmonitorMode(MonitorMode* monitorMode){
	if(mmonitorMode == NULL)
	{
		return -1;
	}
	else
	{
		mmonitorMode = monitorMode;
		return true;
	}

}

LegID* BCSMEvent::setlegID(){
	if(mlegID == NULL)
	{
		mlegID = new LegID();
		mTagsPresent |= BCSMEvent_LEGID;
		return mlegID;
	}
	else
		return mlegID;

}

bool BCSMEvent::setlegID(LegID* legID){
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

DpSpecificCriteria* BCSMEvent::setdpSpecificCriteria(){
	if(mdpSpecificCriteria == NULL)
	{
		mdpSpecificCriteria = new DpSpecificCriteria();
		mTagsPresent |= BCSMEvent_DPSPECIFICCRITERIA;
		return mdpSpecificCriteria;
	}
	else
		return mdpSpecificCriteria;

}

bool BCSMEvent::setdpSpecificCriteria(DpSpecificCriteria* dpSpecificCriteria){
	if(mdpSpecificCriteria == NULL)
	{
		return -1;
	}
	else
	{
		mdpSpecificCriteria = dpSpecificCriteria;
		return true;
	}

}

EventTypeBCSM* BCSMEvent::geteventTypeBCSM() {//throw(const char*)
	if(NULL == meventTypeBCSM)
		throw("Object eventTypeBCSM is NULL");
	else
		return meventTypeBCSM;
}

MonitorMode* BCSMEvent::getmonitorMode() {//throw(const char*)
	if(NULL == mmonitorMode)
		throw("Object monitorMode is NULL");
	else
		return mmonitorMode;
}

LegID* BCSMEvent::getlegID() {//throw(const char*)
	if(NULL == mlegID)
		throw("Object legID is NULL");
	else
		return mlegID;
}

DpSpecificCriteria* BCSMEvent::getdpSpecificCriteria() {//throw(const char*)
	if(NULL == mdpSpecificCriteria)
		throw("Object dpSpecificCriteria is NULL");
	else
		return mdpSpecificCriteria;
}

bool BCSMEvent::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int BCSMEvent::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X0081:
				if(NULL == this->setmonitorMode())
					return -1;
				if(mmonitorMode->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setlegID())
					return -1;
				if(mlegID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00BE:
				if(NULL == this->setdpSpecificCriteria())
					return -1;
				if(mdpSpecificCriteria->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: BCSMEvent Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("BCSMEvent: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int BCSMEvent::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("BCSMEvent: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case BCSMEvent_EVENTTYPEBCSM:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meventTypeBCSM->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case BCSMEvent_MONITORMODE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmonitorMode->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case BCSMEvent_LEGID:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlegID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case BCSMEvent_DPSPECIFICCRITERIA:
				if(asn1_tag_encode(190, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdpSpecificCriteria->Encode(array) < 0) || 
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

	return 0;
}

int BCSMEvent::Display(int tab){
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
			case BCSMEvent_EVENTTYPEBCSM:
			{
				printf(temp, " ", "eventTypeBCSM");
				if(meventTypeBCSM->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BCSMEvent_MONITORMODE:
			{
				printf(temp, " ", "monitorMode");
				if(mmonitorMode->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BCSMEvent_LEGID:
			{
				printf(temp, " ", "legID");
				if(mlegID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BCSMEvent_DPSPECIFICCRITERIA:
			{
				printf(temp, " ", "dpSpecificCriteria");
				if(mdpSpecificCriteria->Display(tab+1) < 0)
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

bool BCSMEvent::ValidateMandatory(char *errStr){
	if(NULL == meventTypeBCSM)
	{
		strcpy(errStr, "eventTypeBCSM");
		return false;
	}
	else if(NULL == mmonitorMode)
	{
		strcpy(errStr, "monitorMode");
		return false;
	}

	return true;
}
BackwardServiceInteractionInd::BackwardServiceInteractionInd()
{
	mconferenceTreatmentIndicator = NULL;
	mcallCompletionTreatmentIndicator = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0081, 0X0082};
	mTagOptional = {true, true};
}

BackwardServiceInteractionInd::~BackwardServiceInteractionInd()
{
	if(mconferenceTreatmentIndicator != NULL)
		delete mconferenceTreatmentIndicator;
	if(mcallCompletionTreatmentIndicator != NULL)
		delete mcallCompletionTreatmentIndicator;
}

capstd::OctetString* BackwardServiceInteractionInd::setconferenceTreatmentIndicator(){
	if(mconferenceTreatmentIndicator == NULL)
	{
		mconferenceTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= BackwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR;
		return mconferenceTreatmentIndicator;
	}
	else
		return mconferenceTreatmentIndicator;

}

bool BackwardServiceInteractionInd::setconferenceTreatmentIndicator(capstd::OctetString* conferenceTreatmentIndicator){
	if(mconferenceTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mconferenceTreatmentIndicator = conferenceTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* BackwardServiceInteractionInd::setcallCompletionTreatmentIndicator(){
	if(mcallCompletionTreatmentIndicator == NULL)
	{
		mcallCompletionTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= BackwardServiceInteractionInd_CALLCOMPLETIONTREATMENTINDICATOR;
		return mcallCompletionTreatmentIndicator;
	}
	else
		return mcallCompletionTreatmentIndicator;

}

bool BackwardServiceInteractionInd::setcallCompletionTreatmentIndicator(capstd::OctetString* callCompletionTreatmentIndicator){
	if(mcallCompletionTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mcallCompletionTreatmentIndicator = callCompletionTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* BackwardServiceInteractionInd::getconferenceTreatmentIndicator() {//throw(const char*)
	if(NULL == mconferenceTreatmentIndicator)
		throw("Object conferenceTreatmentIndicator is NULL");
	else
		return mconferenceTreatmentIndicator;
}

capstd::OctetString* BackwardServiceInteractionInd::getcallCompletionTreatmentIndicator() {//throw(const char*)
	if(NULL == mcallCompletionTreatmentIndicator)
		throw("Object callCompletionTreatmentIndicator is NULL");
	else
		return mcallCompletionTreatmentIndicator;
}

bool BackwardServiceInteractionInd::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int BackwardServiceInteractionInd::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X0081:
				if(NULL == this->setconferenceTreatmentIndicator())
					return -1;
				if(mconferenceTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setcallCompletionTreatmentIndicator())
					return -1;
				if(mcallCompletionTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: BackwardServiceInteractionInd Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("BackwardServiceInteractionInd: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int BackwardServiceInteractionInd::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("BackwardServiceInteractionInd: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case BackwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mconferenceTreatmentIndicator->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case BackwardServiceInteractionInd_CALLCOMPLETIONTREATMENTINDICATOR:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallCompletionTreatmentIndicator->Encode(array) < 0) || 
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

	return 0;
}

int BackwardServiceInteractionInd::Display(int tab){
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
			case BackwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR:
			{
				printf(temp, " ", "conferenceTreatmentIndicator");
				if(mconferenceTreatmentIndicator->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BackwardServiceInteractionInd_CALLCOMPLETIONTREATMENTINDICATOR:
			{
				printf(temp, " ", "callCompletionTreatmentIndicator");
				if(mcallCompletionTreatmentIndicator->Display(tab+1) < 0)
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

bool BackwardServiceInteractionInd::ValidateMandatory(char *errStr){

	return true;
}
BasicGapCriteria::BasicGapCriteria()
{
	mcalledAddressValue = NULL;
	mgapOnService = NULL;
	mcalledAddressAndService = NULL;
	mcallingAddressAndService = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X00A2, 0X00BD, 0X00BE};
}

BasicGapCriteria::~BasicGapCriteria()
{
	if(mcalledAddressValue != NULL)
		delete mcalledAddressValue;
	if(mgapOnService != NULL)
		delete mgapOnService;
	if(mcalledAddressAndService != NULL)
		delete mcalledAddressAndService;
	if(mcallingAddressAndService != NULL)
		delete mcallingAddressAndService;
}

capstd::OctetString* BasicGapCriteria::setcalledAddressValue(){
if(mParamSet == true)
	{
		if(mcalledAddressValue != NULL)
			return mcalledAddressValue;
		else
			return NULL;
	}
	if(mcalledAddressValue == NULL)
	{
		mcalledAddressValue = new capstd::OctetString(2, 16);
		mTagsPresent |= BasicGapCriteria_CALLEDADDRESSVALUE;
		mParamSet = true;
		return mcalledAddressValue;
	}
}

bool BasicGapCriteria::setcalledAddressValue(capstd::OctetString* calledAddressValue){
	if(mcalledAddressValue == NULL)
	{
		return -1;
	}
	else
	{
		mcalledAddressValue = calledAddressValue;
		return true;
	}

}

GapOnService* BasicGapCriteria::setgapOnService(){
if(mParamSet == true)
	{
		if(mgapOnService != NULL)
			return mgapOnService;
		else
			return NULL;
	}
	if(mgapOnService == NULL)
	{
		mgapOnService = new GapOnService();
		mTagsPresent |= BasicGapCriteria_GAPONSERVICE;
		mParamSet = true;
		return mgapOnService;
	}
}

bool BasicGapCriteria::setgapOnService(GapOnService* gapOnService){
	if(mgapOnService == NULL)
	{
		return -1;
	}
	else
	{
		mgapOnService = gapOnService;
		return true;
	}

}

CalledAddressAndService* BasicGapCriteria::setcalledAddressAndService(){
if(mParamSet == true)
	{
		if(mcalledAddressAndService != NULL)
			return mcalledAddressAndService;
		else
			return NULL;
	}
	if(mcalledAddressAndService == NULL)
	{
		mcalledAddressAndService = new CalledAddressAndService();
		mTagsPresent |= BasicGapCriteria_CALLEDADDRESSANDSERVICE;
		mParamSet = true;
		return mcalledAddressAndService;
	}
}

bool BasicGapCriteria::setcalledAddressAndService(CalledAddressAndService* calledAddressAndService){
	if(mcalledAddressAndService == NULL)
	{
		return -1;
	}
	else
	{
		mcalledAddressAndService = calledAddressAndService;
		return true;
	}

}

CallingAddressAndService* BasicGapCriteria::setcallingAddressAndService(){
if(mParamSet == true)
	{
		if(mcallingAddressAndService != NULL)
			return mcallingAddressAndService;
		else
			return NULL;
	}
	if(mcallingAddressAndService == NULL)
	{
		mcallingAddressAndService = new CallingAddressAndService();
		mTagsPresent |= BasicGapCriteria_CALLINGADDRESSANDSERVICE;
		mParamSet = true;
		return mcallingAddressAndService;
	}
}

bool BasicGapCriteria::setcallingAddressAndService(CallingAddressAndService* callingAddressAndService){
	if(mcallingAddressAndService == NULL)
	{
		return -1;
	}
	else
	{
		mcallingAddressAndService = callingAddressAndService;
		return true;
	}

}

capstd::OctetString* BasicGapCriteria::getcalledAddressValue() {//throw(const char*)
	if(NULL == mcalledAddressValue)
		throw("Object calledAddressValue is NULL");
	else
		return mcalledAddressValue;
}

GapOnService* BasicGapCriteria::getgapOnService() {//throw(const char*)
	if(NULL == mgapOnService)
		throw("Object gapOnService is NULL");
	else
		return mgapOnService;
}

CalledAddressAndService* BasicGapCriteria::getcalledAddressAndService() {//throw(const char*)
	if(NULL == mcalledAddressAndService)
		throw("Object calledAddressAndService is NULL");
	else
		return mcalledAddressAndService;
}

CallingAddressAndService* BasicGapCriteria::getcallingAddressAndService() {//throw(const char*)
	if(NULL == mcallingAddressAndService)
		throw("Object callingAddressAndService is NULL");
	else
		return mcallingAddressAndService;
}

bool BasicGapCriteria::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int BasicGapCriteria::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setcalledAddressValue())
					return -1;
				if(mcalledAddressValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A2:
				if(NULL == this->setgapOnService())
					return -1;
				if(mgapOnService->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00BD:
				if(NULL == this->setcalledAddressAndService())
					return -1;
				if(mcalledAddressAndService->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00BE:
				if(NULL == this->setcallingAddressAndService())
					return -1;
				if(mcallingAddressAndService->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: BasicGapCriteria Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("BasicGapCriteria: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int BasicGapCriteria::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("BasicGapCriteria: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case BasicGapCriteria_CALLEDADDRESSVALUE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledAddressValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case BasicGapCriteria_GAPONSERVICE:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgapOnService->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case BasicGapCriteria_CALLEDADDRESSANDSERVICE:
				if(asn1_tag_encode(189, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledAddressAndService->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case BasicGapCriteria_CALLINGADDRESSANDSERVICE:
				if(asn1_tag_encode(190, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingAddressAndService->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int BasicGapCriteria::Display(int tab){
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
			case BasicGapCriteria_CALLEDADDRESSVALUE:
			{
				printf(temp, " ", "calledAddressValue");
				if(mcalledAddressValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BasicGapCriteria_GAPONSERVICE:
			{
				printf(temp, " ", "gapOnService");
				if(mgapOnService->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BasicGapCriteria_CALLEDADDRESSANDSERVICE:
			{
				printf(temp, " ", "calledAddressAndService");
				if(mcalledAddressAndService->Display(tab+1) < 0)
					return -1;
				break;
			}
			case BasicGapCriteria_CALLINGADDRESSANDSERVICE:
			{
				printf(temp, " ", "callingAddressAndService");
				if(mcallingAddressAndService->Display(tab+1) < 0)
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

bool BasicGapCriteria::ValidateMandatory(char *errStr){

	return true;
}
BearerCapability::BearerCapability()
{
	mbearerCap = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080};
}

BearerCapability::~BearerCapability()
{
	if(mbearerCap != NULL)
		delete mbearerCap;
}

capstd::OctetString* BearerCapability::setbearerCap(){
if(mParamSet == true)
	{
		if(mbearerCap != NULL)
			return mbearerCap;
		else
			return NULL;
	}
	if(mbearerCap == NULL)
	{
		mbearerCap = new capstd::OctetString(2, 11);
		mTagsPresent |= BearerCapability_BEARERCAP;
		mParamSet = true;
		return mbearerCap;
	}
}

bool BearerCapability::setbearerCap(capstd::OctetString* bearerCap){
	if(mbearerCap == NULL)
	{
		return -1;
	}
	else
	{
		mbearerCap = bearerCap;
		return true;
	}

}

capstd::OctetString* BearerCapability::getbearerCap() {//throw(const char*)
	if(NULL == mbearerCap)
		throw("Object bearerCap is NULL");
	else
		return mbearerCap;
}

bool BearerCapability::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int BearerCapability::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setbearerCap())
					return -1;
				if(mbearerCap->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: BearerCapability Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("BearerCapability: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int BearerCapability::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("BearerCapability: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case BearerCapability_BEARERCAP:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbearerCap->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int BearerCapability::Display(int tab){
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
			case BearerCapability_BEARERCAP:
			{
				printf(temp, " ", "bearerCap");
				if(mbearerCap->Display(tab+1) < 0)
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

bool BearerCapability::ValidateMandatory(char *errStr){

	return true;
}

BothwayThroughConnectionInd::BothwayThroughConnectionInd()
{
	mTag = 0X000A;
}

BothwayThroughConnectionInd::~BothwayThroughConnectionInd()
{
}

bool BothwayThroughConnectionInd::setValue(BOTHWAYTHROUGHCONNECTIONIND val)
{
	mValue = val;
	return true;
}

BOTHWAYTHROUGHCONNECTIONIND BothwayThroughConnectionInd::getValue()
{
	return mValue;
}

int BothwayThroughConnectionInd::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (BOTHWAYTHROUGHCONNECTIONIND)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int BothwayThroughConnectionInd::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int BothwayThroughConnectionInd::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", BOTHWAYTHROUGHCONNECTIONIND_str(mValue), mValue);
	return 0;
}

CAI_GSM0224::CAI_GSM0224()
{
	me1 = NULL;
	me2 = NULL;
	me3 = NULL;
	me4 = NULL;
	me5 = NULL;
	me6 = NULL;
	me7 = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X0084, 0X0085, 0X0086};
	mTagOptional = {true, true, true, true, true, true, true};
}

CAI_GSM0224::~CAI_GSM0224()
{
	if(me1 != NULL)
		delete me1;
	if(me2 != NULL)
		delete me2;
	if(me3 != NULL)
		delete me3;
	if(me4 != NULL)
		delete me4;
	if(me5 != NULL)
		delete me5;
	if(me6 != NULL)
		delete me6;
	if(me7 != NULL)
		delete me7;
}

capstd::INTEGER* CAI_GSM0224::sete1(){
	if(me1 == NULL)
	{
		me1 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E1;
		return me1;
	}
	else
		return me1;

}

bool CAI_GSM0224::sete1(capstd::INTEGER* e1){
	if(me1 == NULL)
	{
		return -1;
	}
	else
	{
		me1 = e1;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete2(){
	if(me2 == NULL)
	{
		me2 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E2;
		return me2;
	}
	else
		return me2;

}

bool CAI_GSM0224::sete2(capstd::INTEGER* e2){
	if(me2 == NULL)
	{
		return -1;
	}
	else
	{
		me2 = e2;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete3(){
	if(me3 == NULL)
	{
		me3 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E3;
		return me3;
	}
	else
		return me3;

}

bool CAI_GSM0224::sete3(capstd::INTEGER* e3){
	if(me3 == NULL)
	{
		return -1;
	}
	else
	{
		me3 = e3;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete4(){
	if(me4 == NULL)
	{
		me4 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E4;
		return me4;
	}
	else
		return me4;

}

bool CAI_GSM0224::sete4(capstd::INTEGER* e4){
	if(me4 == NULL)
	{
		return -1;
	}
	else
	{
		me4 = e4;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete5(){
	if(me5 == NULL)
	{
		me5 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E5;
		return me5;
	}
	else
		return me5;

}

bool CAI_GSM0224::sete5(capstd::INTEGER* e5){
	if(me5 == NULL)
	{
		return -1;
	}
	else
	{
		me5 = e5;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete6(){
	if(me6 == NULL)
	{
		me6 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E6;
		return me6;
	}
	else
		return me6;

}

bool CAI_GSM0224::sete6(capstd::INTEGER* e6){
	if(me6 == NULL)
	{
		return -1;
	}
	else
	{
		me6 = e6;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::sete7(){
	if(me7 == NULL)
	{
		me7 = new capstd::INTEGER(0, 8191);
		mTagsPresent |= CAI_GSM0224_E7;
		return me7;
	}
	else
		return me7;

}

bool CAI_GSM0224::sete7(capstd::INTEGER* e7){
	if(me7 == NULL)
	{
		return -1;
	}
	else
	{
		me7 = e7;
		return true;
	}

}

capstd::INTEGER* CAI_GSM0224::gete1() {//throw(const char*)
	if(NULL == me1)
		throw("Object e1 is NULL");
	else
		return me1;
}

capstd::INTEGER* CAI_GSM0224::gete2() {//throw(const char*)
	if(NULL == me2)
		throw("Object e2 is NULL");
	else
		return me2;
}

capstd::INTEGER* CAI_GSM0224::gete3() {//throw(const char*)
	if(NULL == me3)
		throw("Object e3 is NULL");
	else
		return me3;
}

capstd::INTEGER* CAI_GSM0224::gete4() {//throw(const char*)
	if(NULL == me4)
		throw("Object e4 is NULL");
	else
		return me4;
}

capstd::INTEGER* CAI_GSM0224::gete5() {//throw(const char*)
	if(NULL == me5)
		throw("Object e5 is NULL");
	else
		return me5;
}

capstd::INTEGER* CAI_GSM0224::gete6() {//throw(const char*)
	if(NULL == me6)
		throw("Object e6 is NULL");
	else
		return me6;
}

capstd::INTEGER* CAI_GSM0224::gete7() {//throw(const char*)
	if(NULL == me7)
		throw("Object e7 is NULL");
	else
		return me7;
}

bool CAI_GSM0224::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CAI_GSM0224::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->sete1())
					return -1;
				if(me1->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->sete2())
					return -1;
				if(me2->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->sete3())
					return -1;
				if(me3->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->sete4())
					return -1;
				if(me4->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->sete5())
					return -1;
				if(me5->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->sete6())
					return -1;
				if(me6->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->sete7())
					return -1;
				if(me7->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CAI_GSM0224 Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CAI_GSM0224: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CAI_GSM0224::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CAI_GSM0224: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CAI_GSM0224_E1:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me1->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E2:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me2->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E3:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me3->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E4:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me4->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E5:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me5->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E6:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me6->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CAI_GSM0224_E7:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me7->Encode(array) < 0) || 
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

	return 0;
}

int CAI_GSM0224::Display(int tab){
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
			case CAI_GSM0224_E1:
			{
				printf(temp, " ", "e1");
				if(me1->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E2:
			{
				printf(temp, " ", "e2");
				if(me2->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E3:
			{
				printf(temp, " ", "e3");
				if(me3->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E4:
			{
				printf(temp, " ", "e4");
				if(me4->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E5:
			{
				printf(temp, " ", "e5");
				if(me5->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E6:
			{
				printf(temp, " ", "e6");
				if(me6->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAI_GSM0224_E7:
			{
				printf(temp, " ", "e7");
				if(me7->Display(tab+1) < 0)
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

bool CAI_GSM0224::ValidateMandatory(char *errStr){

	return true;
}
CAMEL_AChBillingChargingCharacteristics::CAMEL_AChBillingChargingCharacteristics()
{
	mtimeDurationCharging = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0};
}

CAMEL_AChBillingChargingCharacteristics::~CAMEL_AChBillingChargingCharacteristics()
{
	if(mtimeDurationCharging != NULL)
		delete mtimeDurationCharging;
}

TimeDurationCharging* CAMEL_AChBillingChargingCharacteristics::settimeDurationCharging(){
if(mParamSet == true)
	{
		if(mtimeDurationCharging != NULL)
			return mtimeDurationCharging;
		else
			return NULL;
	}
	if(mtimeDurationCharging == NULL)
	{
		mtimeDurationCharging = new TimeDurationCharging();
		mTagsPresent |= CAMEL_AChBillingChargingCharacteristics_TIMEDURATIONCHARGING;
		mParamSet = true;
		return mtimeDurationCharging;
	}
}

bool CAMEL_AChBillingChargingCharacteristics::settimeDurationCharging(TimeDurationCharging* timeDurationCharging){
	if(mtimeDurationCharging == NULL)
	{
		return -1;
	}
	else
	{
		mtimeDurationCharging = timeDurationCharging;
		return true;
	}

}

TimeDurationCharging* CAMEL_AChBillingChargingCharacteristics::gettimeDurationCharging() {//throw(const char*)
	if(NULL == mtimeDurationCharging)
		throw("Object timeDurationCharging is NULL");
	else
		return mtimeDurationCharging;
}

bool CAMEL_AChBillingChargingCharacteristics::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CAMEL_AChBillingChargingCharacteristics::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->settimeDurationCharging())
					return -1;
				if(mtimeDurationCharging->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CAMEL_AChBillingChargingCharacteristics Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CAMEL_AChBillingChargingCharacteristics: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CAMEL_AChBillingChargingCharacteristics::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CAMEL_AChBillingChargingCharacteristics: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CAMEL_AChBillingChargingCharacteristics_TIMEDURATIONCHARGING:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeDurationCharging->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CAMEL_AChBillingChargingCharacteristics::Display(int tab){
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
			case CAMEL_AChBillingChargingCharacteristics_TIMEDURATIONCHARGING:
			{
				printf(temp, " ", "timeDurationCharging");
				if(mtimeDurationCharging->Display(tab+1) < 0)
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

bool CAMEL_AChBillingChargingCharacteristics::ValidateMandatory(char *errStr){

	return true;
}
CAMEL_CallResult::CAMEL_CallResult()
{
	mtimeDurationChargingResult = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0};
}

CAMEL_CallResult::~CAMEL_CallResult()
{
	if(mtimeDurationChargingResult != NULL)
		delete mtimeDurationChargingResult;
}

TimeDurationChargingResult* CAMEL_CallResult::settimeDurationChargingResult(){
if(mParamSet == true)
	{
		if(mtimeDurationChargingResult != NULL)
			return mtimeDurationChargingResult;
		else
			return NULL;
	}
	if(mtimeDurationChargingResult == NULL)
	{
		mtimeDurationChargingResult = new TimeDurationChargingResult();
		mTagsPresent |= CAMEL_CallResult_TIMEDURATIONCHARGINGRESULT;
		mParamSet = true;
		return mtimeDurationChargingResult;
	}
}

bool CAMEL_CallResult::settimeDurationChargingResult(TimeDurationChargingResult* timeDurationChargingResult){
	if(mtimeDurationChargingResult == NULL)
	{
		return -1;
	}
	else
	{
		mtimeDurationChargingResult = timeDurationChargingResult;
		return true;
	}

}

TimeDurationChargingResult* CAMEL_CallResult::gettimeDurationChargingResult() {//throw(const char*)
	if(NULL == mtimeDurationChargingResult)
		throw("Object timeDurationChargingResult is NULL");
	else
		return mtimeDurationChargingResult;
}

bool CAMEL_CallResult::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CAMEL_CallResult::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->settimeDurationChargingResult())
					return -1;
				if(mtimeDurationChargingResult->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CAMEL_CallResult Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CAMEL_CallResult: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CAMEL_CallResult::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CAMEL_CallResult: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CAMEL_CallResult_TIMEDURATIONCHARGINGRESULT:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeDurationChargingResult->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CAMEL_CallResult::Display(int tab){
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
			case CAMEL_CallResult_TIMEDURATIONCHARGINGRESULT:
			{
				printf(temp, " ", "timeDurationChargingResult");
				if(mtimeDurationChargingResult->Display(tab+1) < 0)
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

bool CAMEL_CallResult::ValidateMandatory(char *errStr){

	return true;
}
CAMEL_FCIBillingChargingCharacteristics::CAMEL_FCIBillingChargingCharacteristics()
{
	mfCIBCCCAMELsequence1 = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0};
}

CAMEL_FCIBillingChargingCharacteristics::~CAMEL_FCIBillingChargingCharacteristics()
{
	if(mfCIBCCCAMELsequence1 != NULL)
		delete mfCIBCCCAMELsequence1;
}

FCIBCCCAMELsequence1* CAMEL_FCIBillingChargingCharacteristics::setfCIBCCCAMELsequence1(){
if(mParamSet == true)
	{
		if(mfCIBCCCAMELsequence1 != NULL)
			return mfCIBCCCAMELsequence1;
		else
			return NULL;
	}
	if(mfCIBCCCAMELsequence1 == NULL)
	{
		mfCIBCCCAMELsequence1 = new FCIBCCCAMELsequence1();
		mTagsPresent |= CAMEL_FCIBillingChargingCharacteristics_FCIBCCCAMELSEQUENCE1;
		mParamSet = true;
		return mfCIBCCCAMELsequence1;
	}
}

bool CAMEL_FCIBillingChargingCharacteristics::setfCIBCCCAMELsequence1(FCIBCCCAMELsequence1* fCIBCCCAMELsequence1){
	if(mfCIBCCCAMELsequence1 == NULL)
	{
		return -1;
	}
	else
	{
		mfCIBCCCAMELsequence1 = fCIBCCCAMELsequence1;
		return true;
	}

}

FCIBCCCAMELsequence1* CAMEL_FCIBillingChargingCharacteristics::getfCIBCCCAMELsequence1() {//throw(const char*)
	if(NULL == mfCIBCCCAMELsequence1)
		throw("Object fCIBCCCAMELsequence1 is NULL");
	else
		return mfCIBCCCAMELsequence1;
}

bool CAMEL_FCIBillingChargingCharacteristics::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CAMEL_FCIBillingChargingCharacteristics::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setfCIBCCCAMELsequence1())
					return -1;
				if(mfCIBCCCAMELsequence1->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CAMEL_FCIBillingChargingCharacteristics Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CAMEL_FCIBillingChargingCharacteristics: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CAMEL_FCIBillingChargingCharacteristics::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CAMEL_FCIBillingChargingCharacteristics: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CAMEL_FCIBillingChargingCharacteristics_FCIBCCCAMELSEQUENCE1:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mfCIBCCCAMELsequence1->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CAMEL_FCIBillingChargingCharacteristics::Display(int tab){
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
			case CAMEL_FCIBillingChargingCharacteristics_FCIBCCCAMELSEQUENCE1:
			{
				printf(temp, " ", "fCIBCCCAMELsequence1");
				if(mfCIBCCCAMELsequence1->Display(tab+1) < 0)
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

bool CAMEL_FCIBillingChargingCharacteristics::ValidateMandatory(char *errStr){

	return true;
}
CAMEL_SCIBillingChargingCharacteristics::CAMEL_SCIBillingChargingCharacteristics()
{
	maOCBeforeAnswer = NULL;
	maOCAfterAnswer = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0, 0X00A1};
}

CAMEL_SCIBillingChargingCharacteristics::~CAMEL_SCIBillingChargingCharacteristics()
{
	if(maOCBeforeAnswer != NULL)
		delete maOCBeforeAnswer;
	if(maOCAfterAnswer != NULL)
		delete maOCAfterAnswer;
}

AOCBeforeAnswer* CAMEL_SCIBillingChargingCharacteristics::setaOCBeforeAnswer(){
if(mParamSet == true)
	{
		if(maOCBeforeAnswer != NULL)
			return maOCBeforeAnswer;
		else
			return NULL;
	}
	if(maOCBeforeAnswer == NULL)
	{
		maOCBeforeAnswer = new AOCBeforeAnswer();
		mTagsPresent |= CAMEL_SCIBillingChargingCharacteristics_AOCBEFOREANSWER;
		mParamSet = true;
		return maOCBeforeAnswer;
	}
}

bool CAMEL_SCIBillingChargingCharacteristics::setaOCBeforeAnswer(AOCBeforeAnswer* aOCBeforeAnswer){
	if(maOCBeforeAnswer == NULL)
	{
		return -1;
	}
	else
	{
		maOCBeforeAnswer = aOCBeforeAnswer;
		return true;
	}

}

AOCSubsequent* CAMEL_SCIBillingChargingCharacteristics::setaOCAfterAnswer(){
if(mParamSet == true)
	{
		if(maOCAfterAnswer != NULL)
			return maOCAfterAnswer;
		else
			return NULL;
	}
	if(maOCAfterAnswer == NULL)
	{
		maOCAfterAnswer = new AOCSubsequent();
		mTagsPresent |= CAMEL_SCIBillingChargingCharacteristics_AOCAFTERANSWER;
		mParamSet = true;
		return maOCAfterAnswer;
	}
}

bool CAMEL_SCIBillingChargingCharacteristics::setaOCAfterAnswer(AOCSubsequent* aOCAfterAnswer){
	if(maOCAfterAnswer == NULL)
	{
		return -1;
	}
	else
	{
		maOCAfterAnswer = aOCAfterAnswer;
		return true;
	}

}

AOCBeforeAnswer* CAMEL_SCIBillingChargingCharacteristics::getaOCBeforeAnswer() {//throw(const char*)
	if(NULL == maOCBeforeAnswer)
		throw("Object aOCBeforeAnswer is NULL");
	else
		return maOCBeforeAnswer;
}

AOCSubsequent* CAMEL_SCIBillingChargingCharacteristics::getaOCAfterAnswer() {//throw(const char*)
	if(NULL == maOCAfterAnswer)
		throw("Object aOCAfterAnswer is NULL");
	else
		return maOCAfterAnswer;
}

bool CAMEL_SCIBillingChargingCharacteristics::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CAMEL_SCIBillingChargingCharacteristics::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setaOCBeforeAnswer())
					return -1;
				if(maOCBeforeAnswer->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->setaOCAfterAnswer())
					return -1;
				if(maOCAfterAnswer->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CAMEL_SCIBillingChargingCharacteristics Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CAMEL_SCIBillingChargingCharacteristics: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CAMEL_SCIBillingChargingCharacteristics::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CAMEL_SCIBillingChargingCharacteristics: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CAMEL_SCIBillingChargingCharacteristics_AOCBEFOREANSWER:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCBeforeAnswer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case CAMEL_SCIBillingChargingCharacteristics_AOCAFTERANSWER:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maOCAfterAnswer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CAMEL_SCIBillingChargingCharacteristics::Display(int tab){
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
			case CAMEL_SCIBillingChargingCharacteristics_AOCBEFOREANSWER:
			{
				printf(temp, " ", "aOCBeforeAnswer");
				if(maOCBeforeAnswer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CAMEL_SCIBillingChargingCharacteristics_AOCAFTERANSWER:
			{
				printf(temp, " ", "aOCAfterAnswer");
				if(maOCAfterAnswer->Display(tab+1) < 0)
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

bool CAMEL_SCIBillingChargingCharacteristics::ValidateMandatory(char *errStr){

	return true;
}

CGEncountered::CGEncountered()
{
	mTag = 0X000A;
}

CGEncountered::~CGEncountered()
{
}

bool CGEncountered::setValue(CGENCOUNTERED val)
{
	mValue = val;
	return true;
}

CGENCOUNTERED CGEncountered::getValue()
{
	return mValue;
}

int CGEncountered::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (CGENCOUNTERED)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int CGEncountered::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int CGEncountered::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", CGENCOUNTERED_str(mValue), mValue);
	return 0;
}

CalledAddressAndService::CalledAddressAndService()
{
	mcalledAddressValue = NULL;
	mserviceKey = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, false};
}

CalledAddressAndService::~CalledAddressAndService()
{
	if(mcalledAddressValue != NULL)
		delete mcalledAddressValue;
	if(mserviceKey != NULL)
		delete mserviceKey;
}

capstd::OctetString* CalledAddressAndService::setcalledAddressValue(){
	if(mcalledAddressValue == NULL)
	{
		mcalledAddressValue = new capstd::OctetString(2, 16);
		mTagsPresent |= CalledAddressAndService_CALLEDADDRESSVALUE;
		return mcalledAddressValue;
	}
	else
		return mcalledAddressValue;

}

bool CalledAddressAndService::setcalledAddressValue(capstd::OctetString* calledAddressValue){
	if(mcalledAddressValue == NULL)
	{
		return -1;
	}
	else
	{
		mcalledAddressValue = calledAddressValue;
		return true;
	}

}

capstd::INTEGER* CalledAddressAndService::setserviceKey(){
	if(mserviceKey == NULL)
	{
		mserviceKey = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= CalledAddressAndService_SERVICEKEY;
		return mserviceKey;
	}
	else
		return mserviceKey;

}

bool CalledAddressAndService::setserviceKey(capstd::INTEGER* serviceKey){
	if(mserviceKey == NULL)
	{
		return -1;
	}
	else
	{
		mserviceKey = serviceKey;
		return true;
	}

}

capstd::OctetString* CalledAddressAndService::getcalledAddressValue() {//throw(const char*)
	if(NULL == mcalledAddressValue)
		throw("Object calledAddressValue is NULL");
	else
		return mcalledAddressValue;
}

capstd::INTEGER* CalledAddressAndService::getserviceKey() {//throw(const char*)
	if(NULL == mserviceKey)
		throw("Object serviceKey is NULL");
	else
		return mserviceKey;
}

bool CalledAddressAndService::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CalledAddressAndService::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setcalledAddressValue())
					return -1;
				if(mcalledAddressValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setserviceKey())
					return -1;
				if(mserviceKey->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CalledAddressAndService Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CalledAddressAndService: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CalledAddressAndService::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CalledAddressAndService: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CalledAddressAndService_CALLEDADDRESSVALUE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcalledAddressValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CalledAddressAndService_SERVICEKEY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceKey->Encode(array) < 0) || 
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

	return 0;
}

int CalledAddressAndService::Display(int tab){
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
			case CalledAddressAndService_CALLEDADDRESSVALUE:
			{
				printf(temp, " ", "calledAddressValue");
				if(mcalledAddressValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CalledAddressAndService_SERVICEKEY:
			{
				printf(temp, " ", "serviceKey");
				if(mserviceKey->Display(tab+1) < 0)
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

bool CalledAddressAndService::ValidateMandatory(char *errStr){
	if(NULL == mcalledAddressValue)
	{
		strcpy(errStr, "calledAddressValue");
		return false;
	}
	else if(NULL == mserviceKey)
	{
		strcpy(errStr, "serviceKey");
		return false;
	}

	return true;
}
CallingAddressAndService::CallingAddressAndService()
{
	mcallingAddressValue = NULL;
	mserviceKey = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, false};
}

CallingAddressAndService::~CallingAddressAndService()
{
	if(mcallingAddressValue != NULL)
		delete mcallingAddressValue;
	if(mserviceKey != NULL)
		delete mserviceKey;
}

capstd::OctetString* CallingAddressAndService::setcallingAddressValue(){
	if(mcallingAddressValue == NULL)
	{
		mcallingAddressValue = new capstd::OctetString(2, 16);
		mTagsPresent |= CallingAddressAndService_CALLINGADDRESSVALUE;
		return mcallingAddressValue;
	}
	else
		return mcallingAddressValue;

}

bool CallingAddressAndService::setcallingAddressValue(capstd::OctetString* callingAddressValue){
	if(mcallingAddressValue == NULL)
	{
		return -1;
	}
	else
	{
		mcallingAddressValue = callingAddressValue;
		return true;
	}

}

capstd::INTEGER* CallingAddressAndService::setserviceKey(){
	if(mserviceKey == NULL)
	{
		mserviceKey = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= CallingAddressAndService_SERVICEKEY;
		return mserviceKey;
	}
	else
		return mserviceKey;

}

bool CallingAddressAndService::setserviceKey(capstd::INTEGER* serviceKey){
	if(mserviceKey == NULL)
	{
		return -1;
	}
	else
	{
		mserviceKey = serviceKey;
		return true;
	}

}

capstd::OctetString* CallingAddressAndService::getcallingAddressValue() {//throw(const char*)
	if(NULL == mcallingAddressValue)
		throw("Object callingAddressValue is NULL");
	else
		return mcallingAddressValue;
}

capstd::INTEGER* CallingAddressAndService::getserviceKey() {//throw(const char*)
	if(NULL == mserviceKey)
		throw("Object serviceKey is NULL");
	else
		return mserviceKey;
}

bool CallingAddressAndService::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CallingAddressAndService::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setcallingAddressValue())
					return -1;
				if(mcallingAddressValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setserviceKey())
					return -1;
				if(mserviceKey->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CallingAddressAndService Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CallingAddressAndService: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CallingAddressAndService::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CallingAddressAndService: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CallingAddressAndService_CALLINGADDRESSVALUE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingAddressValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallingAddressAndService_SERVICEKEY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceKey->Encode(array) < 0) || 
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

	return 0;
}

int CallingAddressAndService::Display(int tab){
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
			case CallingAddressAndService_CALLINGADDRESSVALUE:
			{
				printf(temp, " ", "callingAddressValue");
				if(mcallingAddressValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallingAddressAndService_SERVICEKEY:
			{
				printf(temp, " ", "serviceKey");
				if(mserviceKey->Display(tab+1) < 0)
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

bool CallingAddressAndService::ValidateMandatory(char *errStr){
	if(NULL == mcallingAddressValue)
	{
		strcpy(errStr, "callingAddressValue");
		return false;
	}
	else if(NULL == mserviceKey)
	{
		strcpy(errStr, "serviceKey");
		return false;
	}

	return true;
}
CellGlobalIdOrServiceAreaIdOrLAI::CellGlobalIdOrServiceAreaIdOrLAI()
{
	mcellGlobalIdOrServiceAreaIdFixedLength = NULL;
	mlaiFixedLength = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081};
}

CellGlobalIdOrServiceAreaIdOrLAI::~CellGlobalIdOrServiceAreaIdOrLAI()
{
	if(mcellGlobalIdOrServiceAreaIdFixedLength != NULL)
		delete mcellGlobalIdOrServiceAreaIdFixedLength;
	if(mlaiFixedLength != NULL)
		delete mlaiFixedLength;
}

capstd::CellGlobalIdOrServiceAreaIdFixedLength* CellGlobalIdOrServiceAreaIdOrLAI::setcellGlobalIdOrServiceAreaIdFixedLength(){
if(mParamSet == true)
	{
		if(mcellGlobalIdOrServiceAreaIdFixedLength != NULL)
			return mcellGlobalIdOrServiceAreaIdFixedLength;
		else
			return NULL;
	}
	if(mcellGlobalIdOrServiceAreaIdFixedLength == NULL)
	{
		mcellGlobalIdOrServiceAreaIdFixedLength = new capstd::CellGlobalIdOrServiceAreaIdFixedLength();
		mTagsPresent |= CellGlobalIdOrServiceAreaIdOrLAI_CELLGLOBALIDORSERVICEAREAIDFIXEDLENGTH;
		mParamSet = true;
		return mcellGlobalIdOrServiceAreaIdFixedLength;
	}
}

bool CellGlobalIdOrServiceAreaIdOrLAI::setcellGlobalIdOrServiceAreaIdFixedLength(capstd::CellGlobalIdOrServiceAreaIdFixedLength* cellGlobalIdOrServiceAreaIdFixedLength){
	if(mcellGlobalIdOrServiceAreaIdFixedLength == NULL)
	{
		return -1;
	}
	else
	{
		mcellGlobalIdOrServiceAreaIdFixedLength = cellGlobalIdOrServiceAreaIdFixedLength;
		return true;
	}

}

capstd::LAIFixedLength* CellGlobalIdOrServiceAreaIdOrLAI::setlaiFixedLength(){
if(mParamSet == true)
	{
		if(mlaiFixedLength != NULL)
			return mlaiFixedLength;
		else
			return NULL;
	}
	if(mlaiFixedLength == NULL)
	{
		mlaiFixedLength = new capstd::LAIFixedLength();
		mTagsPresent |= CellGlobalIdOrServiceAreaIdOrLAI_LAIFIXEDLENGTH;
		mParamSet = true;
		return mlaiFixedLength;
	}
}

bool CellGlobalIdOrServiceAreaIdOrLAI::setlaiFixedLength(capstd::LAIFixedLength* laiFixedLength){
	if(mlaiFixedLength == NULL)
	{
		return -1;
	}
	else
	{
		mlaiFixedLength = laiFixedLength;
		return true;
	}

}

capstd::CellGlobalIdOrServiceAreaIdFixedLength* CellGlobalIdOrServiceAreaIdOrLAI::getcellGlobalIdOrServiceAreaIdFixedLength() {//throw(const char*)
	if(NULL == mcellGlobalIdOrServiceAreaIdFixedLength)
		throw("Object cellGlobalIdOrServiceAreaIdFixedLength is NULL");
	else
		return mcellGlobalIdOrServiceAreaIdFixedLength;
}

capstd::LAIFixedLength* CellGlobalIdOrServiceAreaIdOrLAI::getlaiFixedLength() {//throw(const char*)
	if(NULL == mlaiFixedLength)
		throw("Object laiFixedLength is NULL");
	else
		return mlaiFixedLength;
}

bool CellGlobalIdOrServiceAreaIdOrLAI::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CellGlobalIdOrServiceAreaIdOrLAI::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setcellGlobalIdOrServiceAreaIdFixedLength())
					return -1;
				if(mcellGlobalIdOrServiceAreaIdFixedLength->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setlaiFixedLength())
					return -1;
				if(mlaiFixedLength->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CellGlobalIdOrServiceAreaIdOrLAI Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CellGlobalIdOrServiceAreaIdOrLAI: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CellGlobalIdOrServiceAreaIdOrLAI::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CellGlobalIdOrServiceAreaIdOrLAI: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CellGlobalIdOrServiceAreaIdOrLAI_CELLGLOBALIDORSERVICEAREAIDFIXEDLENGTH:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcellGlobalIdOrServiceAreaIdFixedLength->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case CellGlobalIdOrServiceAreaIdOrLAI_LAIFIXEDLENGTH:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlaiFixedLength->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CellGlobalIdOrServiceAreaIdOrLAI::Display(int tab){
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
			case CellGlobalIdOrServiceAreaIdOrLAI_CELLGLOBALIDORSERVICEAREAIDFIXEDLENGTH:
			{
				printf(temp, " ", "cellGlobalIdOrServiceAreaIdFixedLength");
				if(mcellGlobalIdOrServiceAreaIdFixedLength->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CellGlobalIdOrServiceAreaIdOrLAI_LAIFIXEDLENGTH:
			{
				printf(temp, " ", "laiFixedLength");
				if(mlaiFixedLength->Display(tab+1) < 0)
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

bool CellGlobalIdOrServiceAreaIdOrLAI::ValidateMandatory(char *errStr){

	return true;
}
Code::Code()
{
	mlocal = NULL;
	mglobal = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0002, 0X0006};
}

Code::~Code()
{
	if(mlocal != NULL)
		delete mlocal;
	if(mglobal != NULL)
		delete mglobal;
}

capstd::INTEGER* Code::setlocal(){
if(mParamSet == true)
	{
		if(mlocal != NULL)
			return mlocal;
		else
			return NULL;
	}
	if(mlocal == NULL)
	{
		mlocal = new capstd::INTEGER();
		mTagsPresent |= Code_LOCAL;
		mParamSet = true;
		return mlocal;
	}
}

bool Code::setlocal(capstd::INTEGER* local){
	if(mlocal == NULL)
	{
		return -1;
	}
	else
	{
		mlocal = local;
		return true;
	}

}

capstd::ObjectIdentifier* Code::setglobal(){
if(mParamSet == true)
	{
		if(mglobal != NULL)
			return mglobal;
		else
			return NULL;
	}
	if(mglobal == NULL)
	{
		mglobal = new capstd::ObjectIdentifier();
		mTagsPresent |= Code_GLOBAL;
		mParamSet = true;
		return mglobal;
	}
}

bool Code::setglobal(capstd::ObjectIdentifier* global){
	if(mglobal == NULL)
	{
		return -1;
	}
	else
	{
		mglobal = global;
		return true;
	}

}

capstd::INTEGER* Code::getlocal() {//throw(const char*)
	if(NULL == mlocal)
		throw("Object local is NULL");
	else
		return mlocal;
}

capstd::ObjectIdentifier* Code::getglobal() {//throw(const char*)
	if(NULL == mglobal)
		throw("Object global is NULL");
	else
		return mglobal;
}

bool Code::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int Code::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0002:
				if(NULL == this->setlocal())
					return -1;
				if(mlocal->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0006:
				if(NULL == this->setglobal())
					return -1;
				if(mglobal->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: Code Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("Code: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int Code::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("Code: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case Code_LOCAL:
				if(asn1_tag_encode(2, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocal->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case Code_GLOBAL:
				if(asn1_tag_encode(6, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mglobal->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int Code::Display(int tab){
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
			case Code_LOCAL:
			{
				printf(temp, " ", "local");
				if(mlocal->Display(tab+1) < 0)
					return -1;
				break;
			}
			case Code_GLOBAL:
			{
				printf(temp, " ", "global");
				if(mglobal->Display(tab+1) < 0)
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

bool Code::ValidateMandatory(char *errStr){

	return true;
}
CollectedDigits::CollectedDigits()
{
	minimumNbOfDigitsDefault = new capstd::INTEGER();
	minimumNbOfDigitsDefault->setValue(1);
	mminimumNbOfDigits = NULL;
	mmaximumNbOfDigits = NULL;
	mendOfReplyDigit = NULL;
	mcancelDigit = NULL;
	mstartDigit = NULL;
	mfirstDigitTimeOut = NULL;
	minterDigitTimeOut = NULL;
	errorTreatmentDefault = new ErrorTreatment();
	errorTreatmentDefault->setValue(stdErrorAndInfo);;
	merrorTreatment = NULL;
	interruptableAnnIndDefault = new capstd::Boolean();
	interruptableAnnIndDefault->setValue(true);
	minterruptableAnnInd = NULL;
	voiceInformationDefault = new capstd::Boolean();
	voiceInformationDefault->setValue(true);
	mvoiceInformation = NULL;
	voiceBackDefault = new capstd::Boolean();
	voiceBackDefault->setValue(true);
	mvoiceBack = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X0084, 0X0085, 0X0086, 0X0087, 0X0088, 0X0089, 0X008A};
	mTagOptional = {false, false, true, true, true, true, true, false, false, false, false};
}

CollectedDigits::~CollectedDigits()
{
	if(mminimumNbOfDigits != NULL)
		delete mminimumNbOfDigits;
	if(minimumNbOfDigitsDefault != NULL)
		delete minimumNbOfDigitsDefault;
	if(mmaximumNbOfDigits != NULL)
		delete mmaximumNbOfDigits;
	if(mendOfReplyDigit != NULL)
		delete mendOfReplyDigit;
	if(mcancelDigit != NULL)
		delete mcancelDigit;
	if(mstartDigit != NULL)
		delete mstartDigit;
	if(mfirstDigitTimeOut != NULL)
		delete mfirstDigitTimeOut;
	if(minterDigitTimeOut != NULL)
		delete minterDigitTimeOut;
	if(merrorTreatment != NULL)
		delete merrorTreatment;
	if(errorTreatmentDefault != NULL)
		delete errorTreatmentDefault;
	if(minterruptableAnnInd != NULL)
		delete minterruptableAnnInd;
	if(interruptableAnnIndDefault != NULL)
		delete interruptableAnnIndDefault;
	if(mvoiceInformation != NULL)
		delete mvoiceInformation;
	if(voiceInformationDefault != NULL)
		delete voiceInformationDefault;
	if(mvoiceBack != NULL)
		delete mvoiceBack;
	if(voiceBackDefault != NULL)
		delete voiceBackDefault;
}

capstd::INTEGER* CollectedDigits::setminimumNbOfDigits(){
	if(mminimumNbOfDigits == NULL)
	{
		mminimumNbOfDigits = new capstd::INTEGER(1, 30);
		mTagsPresent |= CollectedDigits_MINIMUMNBOFDIGITS;
		return mminimumNbOfDigits;
	}
	else
		return mminimumNbOfDigits;

}

bool CollectedDigits::setminimumNbOfDigits(capstd::INTEGER* minimumNbOfDigits){
	if(mminimumNbOfDigits == NULL)
	{
		return -1;
	}
	else
	{
		mminimumNbOfDigits = minimumNbOfDigits;
		return true;
	}

}

capstd::INTEGER* CollectedDigits::setmaximumNbOfDigits(){
	if(mmaximumNbOfDigits == NULL)
	{
		mmaximumNbOfDigits = new capstd::INTEGER(1, 30);
		mTagsPresent |= CollectedDigits_MAXIMUMNBOFDIGITS;
		return mmaximumNbOfDigits;
	}
	else
		return mmaximumNbOfDigits;

}

bool CollectedDigits::setmaximumNbOfDigits(capstd::INTEGER* maximumNbOfDigits){
	if(mmaximumNbOfDigits == NULL)
	{
		return -1;
	}
	else
	{
		mmaximumNbOfDigits = maximumNbOfDigits;
		return true;
	}

}

capstd::OctetString* CollectedDigits::setendOfReplyDigit(){
	if(mendOfReplyDigit == NULL)
	{
		mendOfReplyDigit = new capstd::OctetString(1, 2);
		mTagsPresent |= CollectedDigits_ENDOFREPLYDIGIT;
		return mendOfReplyDigit;
	}
	else
		return mendOfReplyDigit;

}

bool CollectedDigits::setendOfReplyDigit(capstd::OctetString* endOfReplyDigit){
	if(mendOfReplyDigit == NULL)
	{
		return -1;
	}
	else
	{
		mendOfReplyDigit = endOfReplyDigit;
		return true;
	}

}

capstd::OctetString* CollectedDigits::setcancelDigit(){
	if(mcancelDigit == NULL)
	{
		mcancelDigit = new capstd::OctetString(1, 2);
		mTagsPresent |= CollectedDigits_CANCELDIGIT;
		return mcancelDigit;
	}
	else
		return mcancelDigit;

}

bool CollectedDigits::setcancelDigit(capstd::OctetString* cancelDigit){
	if(mcancelDigit == NULL)
	{
		return -1;
	}
	else
	{
		mcancelDigit = cancelDigit;
		return true;
	}

}

capstd::OctetString* CollectedDigits::setstartDigit(){
	if(mstartDigit == NULL)
	{
		mstartDigit = new capstd::OctetString(1, 2);
		mTagsPresent |= CollectedDigits_STARTDIGIT;
		return mstartDigit;
	}
	else
		return mstartDigit;

}

bool CollectedDigits::setstartDigit(capstd::OctetString* startDigit){
	if(mstartDigit == NULL)
	{
		return -1;
	}
	else
	{
		mstartDigit = startDigit;
		return true;
	}

}

capstd::INTEGER* CollectedDigits::setfirstDigitTimeOut(){
	if(mfirstDigitTimeOut == NULL)
	{
		mfirstDigitTimeOut = new capstd::INTEGER(1, 127);
		mTagsPresent |= CollectedDigits_FIRSTDIGITTIMEOUT;
		return mfirstDigitTimeOut;
	}
	else
		return mfirstDigitTimeOut;

}

bool CollectedDigits::setfirstDigitTimeOut(capstd::INTEGER* firstDigitTimeOut){
	if(mfirstDigitTimeOut == NULL)
	{
		return -1;
	}
	else
	{
		mfirstDigitTimeOut = firstDigitTimeOut;
		return true;
	}

}

capstd::INTEGER* CollectedDigits::setinterDigitTimeOut(){
	if(minterDigitTimeOut == NULL)
	{
		minterDigitTimeOut = new capstd::INTEGER(1, 127);
		mTagsPresent |= CollectedDigits_INTERDIGITTIMEOUT;
		return minterDigitTimeOut;
	}
	else
		return minterDigitTimeOut;

}

bool CollectedDigits::setinterDigitTimeOut(capstd::INTEGER* interDigitTimeOut){
	if(minterDigitTimeOut == NULL)
	{
		return -1;
	}
	else
	{
		minterDigitTimeOut = interDigitTimeOut;
		return true;
	}

}

ErrorTreatment* CollectedDigits::seterrorTreatment(){
	if(merrorTreatment == NULL)
	{
		merrorTreatment = new ErrorTreatment();
		mTagsPresent |= CollectedDigits_ERRORTREATMENT;
		return merrorTreatment;
	}
	else
		return merrorTreatment;

}

bool CollectedDigits::seterrorTreatment(ErrorTreatment* errorTreatment){
	if(merrorTreatment == NULL)
	{
		return -1;
	}
	else
	{
		merrorTreatment = errorTreatment;
		return true;
	}

}

capstd::Boolean* CollectedDigits::setinterruptableAnnInd(){
	if(minterruptableAnnInd == NULL)
	{
		minterruptableAnnInd = new capstd::Boolean();
		mTagsPresent |= CollectedDigits_INTERRUPTABLEANNIND;
		return minterruptableAnnInd;
	}
	else
		return minterruptableAnnInd;

}

bool CollectedDigits::setinterruptableAnnInd(capstd::Boolean* interruptableAnnInd){
	if(minterruptableAnnInd == NULL)
	{
		return -1;
	}
	else
	{
		minterruptableAnnInd = interruptableAnnInd;
		return true;
	}

}

capstd::Boolean* CollectedDigits::setvoiceInformation(){
	if(mvoiceInformation == NULL)
	{
		mvoiceInformation = new capstd::Boolean();
		mTagsPresent |= CollectedDigits_VOICEINFORMATION;
		return mvoiceInformation;
	}
	else
		return mvoiceInformation;

}

bool CollectedDigits::setvoiceInformation(capstd::Boolean* voiceInformation){
	if(mvoiceInformation == NULL)
	{
		return -1;
	}
	else
	{
		mvoiceInformation = voiceInformation;
		return true;
	}

}

capstd::Boolean* CollectedDigits::setvoiceBack(){
	if(mvoiceBack == NULL)
	{
		mvoiceBack = new capstd::Boolean();
		mTagsPresent |= CollectedDigits_VOICEBACK;
		return mvoiceBack;
	}
	else
		return mvoiceBack;

}

bool CollectedDigits::setvoiceBack(capstd::Boolean* voiceBack){
	if(mvoiceBack == NULL)
	{
		return -1;
	}
	else
	{
		mvoiceBack = voiceBack;
		return true;
	}

}

capstd::INTEGER* CollectedDigits::getminimumNbOfDigits() {//throw(const char*)
	if(NULL == mminimumNbOfDigits)
		throw("Object minimumNbOfDigits is NULL");
	else
		return mminimumNbOfDigits;
}

capstd::INTEGER* CollectedDigits::getmaximumNbOfDigits() {//throw(const char*)
	if(NULL == mmaximumNbOfDigits)
		throw("Object maximumNbOfDigits is NULL");
	else
		return mmaximumNbOfDigits;
}

capstd::OctetString* CollectedDigits::getendOfReplyDigit() {//throw(const char*)
	if(NULL == mendOfReplyDigit)
		throw("Object endOfReplyDigit is NULL");
	else
		return mendOfReplyDigit;
}

capstd::OctetString* CollectedDigits::getcancelDigit() {//throw(const char*)
	if(NULL == mcancelDigit)
		throw("Object cancelDigit is NULL");
	else
		return mcancelDigit;
}

capstd::OctetString* CollectedDigits::getstartDigit() {//throw(const char*)
	if(NULL == mstartDigit)
		throw("Object startDigit is NULL");
	else
		return mstartDigit;
}

capstd::INTEGER* CollectedDigits::getfirstDigitTimeOut() {//throw(const char*)
	if(NULL == mfirstDigitTimeOut)
		throw("Object firstDigitTimeOut is NULL");
	else
		return mfirstDigitTimeOut;
}

capstd::INTEGER* CollectedDigits::getinterDigitTimeOut() {//throw(const char*)
	if(NULL == minterDigitTimeOut)
		throw("Object interDigitTimeOut is NULL");
	else
		return minterDigitTimeOut;
}

ErrorTreatment* CollectedDigits::geterrorTreatment() {//throw(const char*)
	if(NULL == merrorTreatment)
		throw("Object errorTreatment is NULL");
	else
		return merrorTreatment;
}

capstd::Boolean* CollectedDigits::getinterruptableAnnInd() {//throw(const char*)
	if(NULL == minterruptableAnnInd)
		throw("Object interruptableAnnInd is NULL");
	else
		return minterruptableAnnInd;
}

capstd::Boolean* CollectedDigits::getvoiceInformation() {//throw(const char*)
	if(NULL == mvoiceInformation)
		throw("Object voiceInformation is NULL");
	else
		return mvoiceInformation;
}

capstd::Boolean* CollectedDigits::getvoiceBack() {//throw(const char*)
	if(NULL == mvoiceBack)
		throw("Object voiceBack is NULL");
	else
		return mvoiceBack;
}

bool CollectedDigits::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CollectedDigits::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setminimumNbOfDigits())
					return -1;
				if(mminimumNbOfDigits->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setmaximumNbOfDigits())
					return -1;
				if(mmaximumNbOfDigits->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setendOfReplyDigit())
					return -1;
				if(mendOfReplyDigit->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setcancelDigit())
					return -1;
				if(mcancelDigit->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setstartDigit())
					return -1;
				if(mstartDigit->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setfirstDigitTimeOut())
					return -1;
				if(mfirstDigitTimeOut->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setinterDigitTimeOut())
					return -1;
				if(minterDigitTimeOut->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->seterrorTreatment())
					return -1;
				if(merrorTreatment->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->setinterruptableAnnInd())
					return -1;
				if(minterruptableAnnInd->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setvoiceInformation())
					return -1;
				if(mvoiceInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setvoiceBack())
					return -1;
				if(mvoiceBack->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CollectedDigits Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CollectedDigits: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CollectedDigits::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CollectedDigits: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CollectedDigits_MINIMUMNBOFDIGITS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mminimumNbOfDigits->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_MAXIMUMNBOFDIGITS:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmaximumNbOfDigits->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_ENDOFREPLYDIGIT:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mendOfReplyDigit->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_CANCELDIGIT:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcancelDigit->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_STARTDIGIT:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mstartDigit->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_FIRSTDIGITTIMEOUT:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mfirstDigitTimeOut->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_INTERDIGITTIMEOUT:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minterDigitTimeOut->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_ERRORTREATMENT:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((merrorTreatment->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_INTERRUPTABLEANNIND:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minterruptableAnnInd->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_VOICEINFORMATION:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mvoiceInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CollectedDigits_VOICEBACK:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mvoiceBack->Encode(array) < 0) || 
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

	return 0;
}

int CollectedDigits::Display(int tab){
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
			case CollectedDigits_MINIMUMNBOFDIGITS:
			{
				printf(temp, " ", "minimumNbOfDigits");
				if(mminimumNbOfDigits->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_MAXIMUMNBOFDIGITS:
			{
				printf(temp, " ", "maximumNbOfDigits");
				if(mmaximumNbOfDigits->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_ENDOFREPLYDIGIT:
			{
				printf(temp, " ", "endOfReplyDigit");
				if(mendOfReplyDigit->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_CANCELDIGIT:
			{
				printf(temp, " ", "cancelDigit");
				if(mcancelDigit->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_STARTDIGIT:
			{
				printf(temp, " ", "startDigit");
				if(mstartDigit->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_FIRSTDIGITTIMEOUT:
			{
				printf(temp, " ", "firstDigitTimeOut");
				if(mfirstDigitTimeOut->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_INTERDIGITTIMEOUT:
			{
				printf(temp, " ", "interDigitTimeOut");
				if(minterDigitTimeOut->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_ERRORTREATMENT:
			{
				printf(temp, " ", "errorTreatment");
				if(merrorTreatment->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_INTERRUPTABLEANNIND:
			{
				printf(temp, " ", "interruptableAnnInd");
				if(minterruptableAnnInd->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_VOICEINFORMATION:
			{
				printf(temp, " ", "voiceInformation");
				if(mvoiceInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CollectedDigits_VOICEBACK:
			{
				printf(temp, " ", "voiceBack");
				if(mvoiceBack->Display(tab+1) < 0)
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

bool CollectedDigits::ValidateMandatory(char *errStr){
	if(NULL == mminimumNbOfDigits)
	{
		strcpy(errStr, "minimumNbOfDigits");
		return false;
	}
	else if(NULL == mmaximumNbOfDigits)
	{
		strcpy(errStr, "maximumNbOfDigits");
		return false;
	}
	else if(NULL == merrorTreatment)
	{
		strcpy(errStr, "errorTreatment");
		return false;
	}
	else if(NULL == minterruptableAnnInd)
	{
		strcpy(errStr, "interruptableAnnInd");
		return false;
	}
	else if(NULL == mvoiceInformation)
	{
		strcpy(errStr, "voiceInformation");
		return false;
	}
	else if(NULL == mvoiceBack)
	{
		strcpy(errStr, "voiceBack");
		return false;
	}

	return true;
}
CollectedInfo::CollectedInfo()
{
	mcollectedDigits = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0};
}

CollectedInfo::~CollectedInfo()
{
	if(mcollectedDigits != NULL)
		delete mcollectedDigits;
}

CollectedDigits* CollectedInfo::setcollectedDigits(){
if(mParamSet == true)
	{
		if(mcollectedDigits != NULL)
			return mcollectedDigits;
		else
			return NULL;
	}
	if(mcollectedDigits == NULL)
	{
		mcollectedDigits = new CollectedDigits();
		mTagsPresent |= CollectedInfo_COLLECTEDDIGITS;
		mParamSet = true;
		return mcollectedDigits;
	}
}

bool CollectedInfo::setcollectedDigits(CollectedDigits* collectedDigits){
	if(mcollectedDigits == NULL)
	{
		return -1;
	}
	else
	{
		mcollectedDigits = collectedDigits;
		return true;
	}

}

CollectedDigits* CollectedInfo::getcollectedDigits() {//throw(const char*)
	if(NULL == mcollectedDigits)
		throw("Object collectedDigits is NULL");
	else
		return mcollectedDigits;
}

bool CollectedInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CollectedInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setcollectedDigits())
					return -1;
				if(mcollectedDigits->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CollectedInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CollectedInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CollectedInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CollectedInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CollectedInfo_COLLECTEDDIGITS:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcollectedDigits->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int CollectedInfo::Display(int tab){
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
			case CollectedInfo_COLLECTEDDIGITS:
			{
				printf(temp, " ", "collectedDigits");
				if(mcollectedDigits->Display(tab+1) < 0)
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

bool CollectedInfo::ValidateMandatory(char *errStr){

	return true;
}
CompoundCriteria::CompoundCriteria()
{
	mbasicGapCriteria = NULL;
	mscfID = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081};
	mTagOptional = {false, true};
}

CompoundCriteria::~CompoundCriteria()
{
	if(mbasicGapCriteria != NULL)
		delete mbasicGapCriteria;
	if(mscfID != NULL)
		delete mscfID;
}

BasicGapCriteria* CompoundCriteria::setbasicGapCriteria(){
	if(mbasicGapCriteria == NULL)
	{
		mbasicGapCriteria = new BasicGapCriteria();
		mTagsPresent |= CompoundCriteria_BASICGAPCRITERIA;
		return mbasicGapCriteria;
	}
	else
		return mbasicGapCriteria;

}

bool CompoundCriteria::setbasicGapCriteria(BasicGapCriteria* basicGapCriteria){
	if(mbasicGapCriteria == NULL)
	{
		return -1;
	}
	else
	{
		mbasicGapCriteria = basicGapCriteria;
		return true;
	}

}

capstd::OctetString* CompoundCriteria::setscfID(){
	if(mscfID == NULL)
	{
		mscfID = new capstd::OctetString(2, 10);
		mTagsPresent |= CompoundCriteria_SCFID;
		return mscfID;
	}
	else
		return mscfID;

}

bool CompoundCriteria::setscfID(capstd::OctetString* scfID){
	if(mscfID == NULL)
	{
		return -1;
	}
	else
	{
		mscfID = scfID;
		return true;
	}

}

BasicGapCriteria* CompoundCriteria::getbasicGapCriteria() {//throw(const char*)
	if(NULL == mbasicGapCriteria)
		throw("Object basicGapCriteria is NULL");
	else
		return mbasicGapCriteria;
}

capstd::OctetString* CompoundCriteria::getscfID() {//throw(const char*)
	if(NULL == mscfID)
		throw("Object scfID is NULL");
	else
		return mscfID;
}

bool CompoundCriteria::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CompoundCriteria::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setbasicGapCriteria())
					return -1;
				if(mbasicGapCriteria->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setscfID())
					return -1;
				if(mscfID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CompoundCriteria Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CompoundCriteria: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CompoundCriteria::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CompoundCriteria: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CompoundCriteria_BASICGAPCRITERIA:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbasicGapCriteria->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CompoundCriteria_SCFID:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mscfID->Encode(array) < 0) || 
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

	return 0;
}

int CompoundCriteria::Display(int tab){
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
			case CompoundCriteria_BASICGAPCRITERIA:
			{
				printf(temp, " ", "basicGapCriteria");
				if(mbasicGapCriteria->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CompoundCriteria_SCFID:
			{
				printf(temp, " ", "scfID");
				if(mscfID->Display(tab+1) < 0)
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

bool CompoundCriteria::ValidateMandatory(char *errStr){
	if(NULL == mbasicGapCriteria)
	{
		strcpy(errStr, "basicGapCriteria");
		return false;
	}

	return true;
}

ConnectedNumberTreatmentInd::ConnectedNumberTreatmentInd()
{
	mTag = 0X000A;
}

ConnectedNumberTreatmentInd::~ConnectedNumberTreatmentInd()
{
}

bool ConnectedNumberTreatmentInd::setValue(CONNECTEDNUMBERTREATMENTIND val)
{
	mValue = val;
	return true;
}

CONNECTEDNUMBERTREATMENTIND ConnectedNumberTreatmentInd::getValue()
{
	return mValue;
}

int ConnectedNumberTreatmentInd::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (CONNECTEDNUMBERTREATMENTIND)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int ConnectedNumberTreatmentInd::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int ConnectedNumberTreatmentInd::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", CONNECTEDNUMBERTREATMENTIND_str(mValue), mValue);
	return 0;
}


ControlType::ControlType()
{
	mTag = 0X000A;
}

ControlType::~ControlType()
{
}

bool ControlType::setValue(CONTROLTYPE val)
{
	mValue = val;
	return true;
}

CONTROLTYPE ControlType::getValue()
{
	return mValue;
}

int ControlType::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (CONTROLTYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int ControlType::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int ControlType::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", CONTROLTYPE_str(mValue), mValue);
	return 0;
}


CriticalityType::CriticalityType()
{
	mTag = 0X000A;
}

CriticalityType::~CriticalityType()
{
}

bool CriticalityType::setValue(CRITICALITYTYPE val)
{
	mValue = val;
	return true;
}

CRITICALITYTYPE CriticalityType::getValue()
{
	return mValue;
}

int CriticalityType::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (CRITICALITYTYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int CriticalityType::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int CriticalityType::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", CRITICALITYTYPE_str(mValue), mValue);
	return 0;
}


DestinationRoutingAddress::DestinationRoutingAddress()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 1;
	mParamList.clear();
}

DestinationRoutingAddress::~DestinationRoutingAddress()
{
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

capstd::OctetString* DestinationRoutingAddress::getOctetString()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* DestinationRoutingAddress::getNextOctetString()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* DestinationRoutingAddress::getOctetStringAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object OctetString is NULL");
}

unsigned DestinationRoutingAddress::getNoOfOctetString()
{
	return mParamList.size();
}

bool DestinationRoutingAddress::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

capstd::OctetString* DestinationRoutingAddress::setNewOctetString()
{
	mOctetString = new capstd::OctetString(2, 18);
	if(NULL == mOctetString)
		return NULL;
	mParamList.push_back(mOctetString);
	mCounter++;
	return mOctetString;
}

capstd::OctetString* DestinationRoutingAddress::setOctetString()
{
	if(NULL == mOctetString)
		return NULL;
	return mOctetString;
}

int DestinationRoutingAddress::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0004:
				this->setNewOctetString();
				if(mOctetString->Decode(array, &bytesDecoded) < 0)
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
int DestinationRoutingAddress::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(4, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int DestinationRoutingAddress::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "OctetString");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}


DomainType::DomainType()
{
	mTag = 0X000A;
}

DomainType::~DomainType()
{
}

bool DomainType::setValue(DOMAINTYPE val)
{
	mValue = val;
	return true;
}

DOMAINTYPE DomainType::getValue()
{
	return mValue;
}

int DomainType::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (DOMAINTYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int DomainType::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int DomainType::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", DOMAINTYPE_str(mValue), mValue);
	return 0;
}

DpSpecificCriteria::DpSpecificCriteria()
{
	mapplicationTimer = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0081};
}

DpSpecificCriteria::~DpSpecificCriteria()
{
	if(mapplicationTimer != NULL)
		delete mapplicationTimer;
}

capstd::INTEGER* DpSpecificCriteria::setapplicationTimer(){
if(mParamSet == true)
	{
		if(mapplicationTimer != NULL)
			return mapplicationTimer;
		else
			return NULL;
	}
	if(mapplicationTimer == NULL)
	{
		mapplicationTimer = new capstd::INTEGER(0, 2047);
		mTagsPresent |= DpSpecificCriteria_APPLICATIONTIMER;
		mParamSet = true;
		return mapplicationTimer;
	}
}

bool DpSpecificCriteria::setapplicationTimer(capstd::INTEGER* applicationTimer){
	if(mapplicationTimer == NULL)
	{
		return -1;
	}
	else
	{
		mapplicationTimer = applicationTimer;
		return true;
	}

}

capstd::INTEGER* DpSpecificCriteria::getapplicationTimer() {//throw(const char*)
	if(NULL == mapplicationTimer)
		throw("Object applicationTimer is NULL");
	else
		return mapplicationTimer;
}

bool DpSpecificCriteria::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int DpSpecificCriteria::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0081:
				if(NULL == this->setapplicationTimer())
					return -1;
				if(mapplicationTimer->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: DpSpecificCriteria Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("DpSpecificCriteria: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int DpSpecificCriteria::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("DpSpecificCriteria: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case DpSpecificCriteria_APPLICATIONTIMER:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mapplicationTimer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int DpSpecificCriteria::Display(int tab){
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
			case DpSpecificCriteria_APPLICATIONTIMER:
			{
				printf(temp, " ", "applicationTimer");
				if(mapplicationTimer->Display(tab+1) < 0)
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

bool DpSpecificCriteria::ValidateMandatory(char *errStr){

	return true;
}
ElapsedTime::ElapsedTime()
{
	mtimeGPRSIfNoTariffSwitch = NULL;
	mtimeGPRSIfTariffSwitch = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X00A1};
}

ElapsedTime::~ElapsedTime()
{
	if(mtimeGPRSIfNoTariffSwitch != NULL)
		delete mtimeGPRSIfNoTariffSwitch;
	if(mtimeGPRSIfTariffSwitch != NULL)
		delete mtimeGPRSIfTariffSwitch;
}

capstd::INTEGER* ElapsedTime::settimeGPRSIfNoTariffSwitch(){
if(mParamSet == true)
	{
		if(mtimeGPRSIfNoTariffSwitch != NULL)
			return mtimeGPRSIfNoTariffSwitch;
		else
			return NULL;
	}
	if(mtimeGPRSIfNoTariffSwitch == NULL)
	{
		mtimeGPRSIfNoTariffSwitch = new capstd::INTEGER(0, 86400);
		mTagsPresent |= ElapsedTime_TIMEGPRSIFNOTARIFFSWITCH;
		mParamSet = true;
		return mtimeGPRSIfNoTariffSwitch;
	}
}

bool ElapsedTime::settimeGPRSIfNoTariffSwitch(capstd::INTEGER* timeGPRSIfNoTariffSwitch){
	if(mtimeGPRSIfNoTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeGPRSIfNoTariffSwitch = timeGPRSIfNoTariffSwitch;
		return true;
	}

}

TimeGPRSIfTariffSwitch* ElapsedTime::settimeGPRSIfTariffSwitch(){
if(mParamSet == true)
	{
		if(mtimeGPRSIfTariffSwitch != NULL)
			return mtimeGPRSIfTariffSwitch;
		else
			return NULL;
	}
	if(mtimeGPRSIfTariffSwitch == NULL)
	{
		mtimeGPRSIfTariffSwitch = new TimeGPRSIfTariffSwitch();
		mTagsPresent |= ElapsedTime_TIMEGPRSIFTARIFFSWITCH;
		mParamSet = true;
		return mtimeGPRSIfTariffSwitch;
	}
}

bool ElapsedTime::settimeGPRSIfTariffSwitch(TimeGPRSIfTariffSwitch* timeGPRSIfTariffSwitch){
	if(mtimeGPRSIfTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeGPRSIfTariffSwitch = timeGPRSIfTariffSwitch;
		return true;
	}

}

capstd::INTEGER* ElapsedTime::gettimeGPRSIfNoTariffSwitch() {//throw(const char*)
	if(NULL == mtimeGPRSIfNoTariffSwitch)
		throw("Object timeGPRSIfNoTariffSwitch is NULL");
	else
		return mtimeGPRSIfNoTariffSwitch;
}

TimeGPRSIfTariffSwitch* ElapsedTime::gettimeGPRSIfTariffSwitch() {//throw(const char*)
	if(NULL == mtimeGPRSIfTariffSwitch)
		throw("Object timeGPRSIfTariffSwitch is NULL");
	else
		return mtimeGPRSIfTariffSwitch;
}

bool ElapsedTime::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ElapsedTime::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->settimeGPRSIfNoTariffSwitch())
					return -1;
				if(mtimeGPRSIfNoTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->settimeGPRSIfTariffSwitch())
					return -1;
				if(mtimeGPRSIfTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: ElapsedTime Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ElapsedTime: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ElapsedTime::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ElapsedTime: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ElapsedTime_TIMEGPRSIFNOTARIFFSWITCH:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeGPRSIfNoTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case ElapsedTime_TIMEGPRSIFTARIFFSWITCH:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeGPRSIfTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int ElapsedTime::Display(int tab){
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
			case ElapsedTime_TIMEGPRSIFNOTARIFFSWITCH:
			{
				printf(temp, " ", "timeGPRSIfNoTariffSwitch");
				if(mtimeGPRSIfNoTariffSwitch->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ElapsedTime_TIMEGPRSIFTARIFFSWITCH:
			{
				printf(temp, " ", "timeGPRSIfTariffSwitch");
				if(mtimeGPRSIfTariffSwitch->Display(tab+1) < 0)
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

bool ElapsedTime::ValidateMandatory(char *errStr){

	return true;
}

ErrorTreatment::ErrorTreatment()
{
	mTag = 0X000A;
}

ErrorTreatment::~ErrorTreatment()
{
}

bool ErrorTreatment::setValue(ERRORTREATMENT val)
{
	mValue = val;
	return true;
}

ERRORTREATMENT ErrorTreatment::getValue()
{
	return mValue;
}

int ErrorTreatment::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (ERRORTREATMENT)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int ErrorTreatment::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int ErrorTreatment::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", ERRORTREATMENT_str(mValue), mValue);
	return 0;
}

EventSpecificInformationBCSM::EventSpecificInformationBCSM()
{
	mrouteSelectFailureSpecificInfo = NULL;
	moCalledPartyBusySpecificInfo = NULL;
	moAnswerSpecificInfo = NULL;
	moDisconnectSpecificInfo = NULL;
	mtBusySpecificInfo = NULL;
	mtNoAnswerSpecificInfo = NULL;
	mtAnswerSpecificInfo = NULL;
	mtDisconnectSpecificInfo = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A2, 0X00A3, 0X00A5, 0X00A7, 0X00A8, 0X00A9, 0X00AA, 0X00AC};
}

EventSpecificInformationBCSM::~EventSpecificInformationBCSM()
{
	if(mrouteSelectFailureSpecificInfo != NULL)
		delete mrouteSelectFailureSpecificInfo;
	if(moCalledPartyBusySpecificInfo != NULL)
		delete moCalledPartyBusySpecificInfo;
	if(moAnswerSpecificInfo != NULL)
		delete moAnswerSpecificInfo;
	if(moDisconnectSpecificInfo != NULL)
		delete moDisconnectSpecificInfo;
	if(mtBusySpecificInfo != NULL)
		delete mtBusySpecificInfo;
	if(mtNoAnswerSpecificInfo != NULL)
		delete mtNoAnswerSpecificInfo;
	if(mtAnswerSpecificInfo != NULL)
		delete mtAnswerSpecificInfo;
	if(mtDisconnectSpecificInfo != NULL)
		delete mtDisconnectSpecificInfo;
}

RouteSelectFailureSpecificInfo* EventSpecificInformationBCSM::setrouteSelectFailureSpecificInfo(){
if(mParamSet == true)
	{
		if(mrouteSelectFailureSpecificInfo != NULL)
			return mrouteSelectFailureSpecificInfo;
		else
			return NULL;
	}
	if(mrouteSelectFailureSpecificInfo == NULL)
	{
		mrouteSelectFailureSpecificInfo = new RouteSelectFailureSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_ROUTESELECTFAILURESPECIFICINFO;
		mParamSet = true;
		return mrouteSelectFailureSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::setrouteSelectFailureSpecificInfo(RouteSelectFailureSpecificInfo* routeSelectFailureSpecificInfo){
	if(mrouteSelectFailureSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mrouteSelectFailureSpecificInfo = routeSelectFailureSpecificInfo;
		return true;
	}

}

OCalledPartyBusySpecificInfo* EventSpecificInformationBCSM::setoCalledPartyBusySpecificInfo(){
if(mParamSet == true)
	{
		if(moCalledPartyBusySpecificInfo != NULL)
			return moCalledPartyBusySpecificInfo;
		else
			return NULL;
	}
	if(moCalledPartyBusySpecificInfo == NULL)
	{
		moCalledPartyBusySpecificInfo = new OCalledPartyBusySpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_OCALLEDPARTYBUSYSPECIFICINFO;
		mParamSet = true;
		return moCalledPartyBusySpecificInfo;
	}
}

bool EventSpecificInformationBCSM::setoCalledPartyBusySpecificInfo(OCalledPartyBusySpecificInfo* oCalledPartyBusySpecificInfo){
	if(moCalledPartyBusySpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		moCalledPartyBusySpecificInfo = oCalledPartyBusySpecificInfo;
		return true;
	}

}

OAnswerSpecificInfo* EventSpecificInformationBCSM::setoAnswerSpecificInfo(){
if(mParamSet == true)
	{
		if(moAnswerSpecificInfo != NULL)
			return moAnswerSpecificInfo;
		else
			return NULL;
	}
	if(moAnswerSpecificInfo == NULL)
	{
		moAnswerSpecificInfo = new OAnswerSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_OANSWERSPECIFICINFO;
		mParamSet = true;
		return moAnswerSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::setoAnswerSpecificInfo(OAnswerSpecificInfo* oAnswerSpecificInfo){
	if(moAnswerSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		moAnswerSpecificInfo = oAnswerSpecificInfo;
		return true;
	}

}

ODisconnectSpecificInfo* EventSpecificInformationBCSM::setoDisconnectSpecificInfo(){
if(mParamSet == true)
	{
		if(moDisconnectSpecificInfo != NULL)
			return moDisconnectSpecificInfo;
		else
			return NULL;
	}
	if(moDisconnectSpecificInfo == NULL)
	{
		moDisconnectSpecificInfo = new ODisconnectSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_ODISCONNECTSPECIFICINFO;
		mParamSet = true;
		return moDisconnectSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::setoDisconnectSpecificInfo(ODisconnectSpecificInfo* oDisconnectSpecificInfo){
	if(moDisconnectSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		moDisconnectSpecificInfo = oDisconnectSpecificInfo;
		return true;
	}

}

TBusySpecificInfo* EventSpecificInformationBCSM::settBusySpecificInfo(){
if(mParamSet == true)
	{
		if(mtBusySpecificInfo != NULL)
			return mtBusySpecificInfo;
		else
			return NULL;
	}
	if(mtBusySpecificInfo == NULL)
	{
		mtBusySpecificInfo = new TBusySpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_TBUSYSPECIFICINFO;
		mParamSet = true;
		return mtBusySpecificInfo;
	}
}

bool EventSpecificInformationBCSM::settBusySpecificInfo(TBusySpecificInfo* tBusySpecificInfo){
	if(mtBusySpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mtBusySpecificInfo = tBusySpecificInfo;
		return true;
	}

}

TNoAnswerSpecificInfo* EventSpecificInformationBCSM::settNoAnswerSpecificInfo(){
if(mParamSet == true)
	{
		if(mtNoAnswerSpecificInfo != NULL)
			return mtNoAnswerSpecificInfo;
		else
			return NULL;
	}
	if(mtNoAnswerSpecificInfo == NULL)
	{
		mtNoAnswerSpecificInfo = new TNoAnswerSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_TNOANSWERSPECIFICINFO;
		mParamSet = true;
		return mtNoAnswerSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::settNoAnswerSpecificInfo(TNoAnswerSpecificInfo* tNoAnswerSpecificInfo){
	if(mtNoAnswerSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mtNoAnswerSpecificInfo = tNoAnswerSpecificInfo;
		return true;
	}

}

TAnswerSpecificInfo* EventSpecificInformationBCSM::settAnswerSpecificInfo(){
if(mParamSet == true)
	{
		if(mtAnswerSpecificInfo != NULL)
			return mtAnswerSpecificInfo;
		else
			return NULL;
	}
	if(mtAnswerSpecificInfo == NULL)
	{
		mtAnswerSpecificInfo = new TAnswerSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_TANSWERSPECIFICINFO;
		mParamSet = true;
		return mtAnswerSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::settAnswerSpecificInfo(TAnswerSpecificInfo* tAnswerSpecificInfo){
	if(mtAnswerSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mtAnswerSpecificInfo = tAnswerSpecificInfo;
		return true;
	}

}

TDisconnectSpecificInfo* EventSpecificInformationBCSM::settDisconnectSpecificInfo(){
if(mParamSet == true)
	{
		if(mtDisconnectSpecificInfo != NULL)
			return mtDisconnectSpecificInfo;
		else
			return NULL;
	}
	if(mtDisconnectSpecificInfo == NULL)
	{
		mtDisconnectSpecificInfo = new TDisconnectSpecificInfo();
		mTagsPresent |= EventSpecificInformationBCSM_TDISCONNECTSPECIFICINFO;
		mParamSet = true;
		return mtDisconnectSpecificInfo;
	}
}

bool EventSpecificInformationBCSM::settDisconnectSpecificInfo(TDisconnectSpecificInfo* tDisconnectSpecificInfo){
	if(mtDisconnectSpecificInfo == NULL)
	{
		return -1;
	}
	else
	{
		mtDisconnectSpecificInfo = tDisconnectSpecificInfo;
		return true;
	}

}

RouteSelectFailureSpecificInfo* EventSpecificInformationBCSM::getrouteSelectFailureSpecificInfo() {//throw(const char*)
	if(NULL == mrouteSelectFailureSpecificInfo)
		throw("Object routeSelectFailureSpecificInfo is NULL");
	else
		return mrouteSelectFailureSpecificInfo;
}

OCalledPartyBusySpecificInfo* EventSpecificInformationBCSM::getoCalledPartyBusySpecificInfo() {//throw(const char*)
	if(NULL == moCalledPartyBusySpecificInfo)
		throw("Object oCalledPartyBusySpecificInfo is NULL");
	else
		return moCalledPartyBusySpecificInfo;
}

OAnswerSpecificInfo* EventSpecificInformationBCSM::getoAnswerSpecificInfo() {//throw(const char*)
	if(NULL == moAnswerSpecificInfo)
		throw("Object oAnswerSpecificInfo is NULL");
	else
		return moAnswerSpecificInfo;
}

ODisconnectSpecificInfo* EventSpecificInformationBCSM::getoDisconnectSpecificInfo() {//throw(const char*)
	if(NULL == moDisconnectSpecificInfo)
		throw("Object oDisconnectSpecificInfo is NULL");
	else
		return moDisconnectSpecificInfo;
}

TBusySpecificInfo* EventSpecificInformationBCSM::gettBusySpecificInfo() {//throw(const char*)
	if(NULL == mtBusySpecificInfo)
		throw("Object tBusySpecificInfo is NULL");
	else
		return mtBusySpecificInfo;
}

TNoAnswerSpecificInfo* EventSpecificInformationBCSM::gettNoAnswerSpecificInfo() {//throw(const char*)
	if(NULL == mtNoAnswerSpecificInfo)
		throw("Object tNoAnswerSpecificInfo is NULL");
	else
		return mtNoAnswerSpecificInfo;
}

TAnswerSpecificInfo* EventSpecificInformationBCSM::gettAnswerSpecificInfo() {//throw(const char*)
	if(NULL == mtAnswerSpecificInfo)
		throw("Object tAnswerSpecificInfo is NULL");
	else
		return mtAnswerSpecificInfo;
}

TDisconnectSpecificInfo* EventSpecificInformationBCSM::gettDisconnectSpecificInfo() {//throw(const char*)
	if(NULL == mtDisconnectSpecificInfo)
		throw("Object tDisconnectSpecificInfo is NULL");
	else
		return mtDisconnectSpecificInfo;
}

bool EventSpecificInformationBCSM::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int EventSpecificInformationBCSM::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setrouteSelectFailureSpecificInfo())
					return -1;
				if(mrouteSelectFailureSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A3:
				if(NULL == this->setoCalledPartyBusySpecificInfo())
					return -1;
				if(moCalledPartyBusySpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A5:
				if(NULL == this->setoAnswerSpecificInfo())
					return -1;
				if(moAnswerSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A7:
				if(NULL == this->setoDisconnectSpecificInfo())
					return -1;
				if(moDisconnectSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A8:
				if(NULL == this->settBusySpecificInfo())
					return -1;
				if(mtBusySpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A9:
				if(NULL == this->settNoAnswerSpecificInfo())
					return -1;
				if(mtNoAnswerSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00AA:
				if(NULL == this->settAnswerSpecificInfo())
					return -1;
				if(mtAnswerSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00AC:
				if(NULL == this->settDisconnectSpecificInfo())
					return -1;
				if(mtDisconnectSpecificInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: EventSpecificInformationBCSM Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("EventSpecificInformationBCSM: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int EventSpecificInformationBCSM::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("EventSpecificInformationBCSM: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case EventSpecificInformationBCSM_ROUTESELECTFAILURESPECIFICINFO:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrouteSelectFailureSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_OCALLEDPARTYBUSYSPECIFICINFO:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((moCalledPartyBusySpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_OANSWERSPECIFICINFO:
				if(asn1_tag_encode(165, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((moAnswerSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_ODISCONNECTSPECIFICINFO:
				if(asn1_tag_encode(167, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((moDisconnectSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_TBUSYSPECIFICINFO:
				if(asn1_tag_encode(168, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtBusySpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_TNOANSWERSPECIFICINFO:
				if(asn1_tag_encode(169, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtNoAnswerSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_TANSWERSPECIFICINFO:
				if(asn1_tag_encode(170, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtAnswerSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EventSpecificInformationBCSM_TDISCONNECTSPECIFICINFO:
				if(asn1_tag_encode(172, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtDisconnectSpecificInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int EventSpecificInformationBCSM::Display(int tab){
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
			case EventSpecificInformationBCSM_ROUTESELECTFAILURESPECIFICINFO:
			{
				printf(temp, " ", "routeSelectFailureSpecificInfo");
				if(mrouteSelectFailureSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_OCALLEDPARTYBUSYSPECIFICINFO:
			{
				printf(temp, " ", "oCalledPartyBusySpecificInfo");
				if(moCalledPartyBusySpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_OANSWERSPECIFICINFO:
			{
				printf(temp, " ", "oAnswerSpecificInfo");
				if(moAnswerSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_ODISCONNECTSPECIFICINFO:
			{
				printf(temp, " ", "oDisconnectSpecificInfo");
				if(moDisconnectSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_TBUSYSPECIFICINFO:
			{
				printf(temp, " ", "tBusySpecificInfo");
				if(mtBusySpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_TNOANSWERSPECIFICINFO:
			{
				printf(temp, " ", "tNoAnswerSpecificInfo");
				if(mtNoAnswerSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_TANSWERSPECIFICINFO:
			{
				printf(temp, " ", "tAnswerSpecificInfo");
				if(mtAnswerSpecificInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EventSpecificInformationBCSM_TDISCONNECTSPECIFICINFO:
			{
				printf(temp, " ", "tDisconnectSpecificInfo");
				if(mtDisconnectSpecificInfo->Display(tab+1) < 0)
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

bool EventSpecificInformationBCSM::ValidateMandatory(char *errStr){

	return true;
}

EventTypeBCSM::EventTypeBCSM()
{
	mTag = 0X000A;
}

EventTypeBCSM::~EventTypeBCSM()
{
}

bool EventTypeBCSM::setValue(EVENTTYPEBCSM val)
{
	mValue = val;
	return true;
}

EVENTTYPEBCSM EventTypeBCSM::getValue()
{
	return mValue;
}

int EventTypeBCSM::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (EVENTTYPEBCSM)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int EventTypeBCSM::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int EventTypeBCSM::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", EVENTTYPEBCSM_str(mValue), mValue);
	return 0;
}

Ext_BasicServiceCode::Ext_BasicServiceCode()
{
	mext_BearerService = NULL;
	mext_Teleservice = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0082, 0X0083};
}

Ext_BasicServiceCode::~Ext_BasicServiceCode()
{
	if(mext_BearerService != NULL)
		delete mext_BearerService;
	if(mext_Teleservice != NULL)
		delete mext_Teleservice;
}

capstd::OctetString* Ext_BasicServiceCode::setext_BearerService(){
if(mParamSet == true)
	{
		if(mext_BearerService != NULL)
			return mext_BearerService;
		else
			return NULL;
	}
	if(mext_BearerService == NULL)
	{
		mext_BearerService = new capstd::OctetString(1, 5);
		mTagsPresent |= Ext_BasicServiceCode_EXT_BEARERSERVICE;
		mParamSet = true;
		return mext_BearerService;
	}
}

bool Ext_BasicServiceCode::setext_BearerService(capstd::OctetString* ext_BearerService){
	if(mext_BearerService == NULL)
	{
		return -1;
	}
	else
	{
		mext_BearerService = ext_BearerService;
		return true;
	}

}

capstd::OctetString* Ext_BasicServiceCode::setext_Teleservice(){
if(mParamSet == true)
	{
		if(mext_Teleservice != NULL)
			return mext_Teleservice;
		else
			return NULL;
	}
	if(mext_Teleservice == NULL)
	{
		mext_Teleservice = new capstd::OctetString(1, 5);
		mTagsPresent |= Ext_BasicServiceCode_EXT_TELESERVICE;
		mParamSet = true;
		return mext_Teleservice;
	}
}

bool Ext_BasicServiceCode::setext_Teleservice(capstd::OctetString* ext_Teleservice){
	if(mext_Teleservice == NULL)
	{
		return -1;
	}
	else
	{
		mext_Teleservice = ext_Teleservice;
		return true;
	}

}

capstd::OctetString* Ext_BasicServiceCode::getext_BearerService() {//throw(const char*)
	if(NULL == mext_BearerService)
		throw("Object ext_BearerService is NULL");
	else
		return mext_BearerService;
}

capstd::OctetString* Ext_BasicServiceCode::getext_Teleservice() {//throw(const char*)
	if(NULL == mext_Teleservice)
		throw("Object ext_Teleservice is NULL");
	else
		return mext_Teleservice;
}

bool Ext_BasicServiceCode::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int Ext_BasicServiceCode::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0082:
				if(NULL == this->setext_BearerService())
					return -1;
				if(mext_BearerService->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0083:
				if(NULL == this->setext_Teleservice())
					return -1;
				if(mext_Teleservice->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: Ext_BasicServiceCode Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("Ext_BasicServiceCode: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int Ext_BasicServiceCode::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("Ext_BasicServiceCode: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case Ext_BasicServiceCode_EXT_BEARERSERVICE:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mext_BearerService->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case Ext_BasicServiceCode_EXT_TELESERVICE:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mext_Teleservice->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int Ext_BasicServiceCode::Display(int tab){
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
			case Ext_BasicServiceCode_EXT_BEARERSERVICE:
			{
				printf(temp, " ", "ext_BearerService");
				if(mext_BearerService->Display(tab+1) < 0)
					return -1;
				break;
			}
			case Ext_BasicServiceCode_EXT_TELESERVICE:
			{
				printf(temp, " ", "ext_Teleservice");
				if(mext_Teleservice->Display(tab+1) < 0)
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

bool Ext_BasicServiceCode::ValidateMandatory(char *errStr){

	return true;
}
ExtensionContainer::ExtensionContainer()
{
	mprivateExtensionList = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0};
	mTagOptional = {true};
}

ExtensionContainer::~ExtensionContainer()
{
	if(mprivateExtensionList != NULL)
		delete mprivateExtensionList;
}

PrivateExtensionList* ExtensionContainer::setprivateExtensionList(){
	if(mprivateExtensionList == NULL)
	{
		mprivateExtensionList = new PrivateExtensionList();
		mTagsPresent |= ExtensionContainer_PRIVATEEXTENSIONLIST;
		return mprivateExtensionList;
	}
	else
		return mprivateExtensionList;

}

bool ExtensionContainer::setprivateExtensionList(PrivateExtensionList* privateExtensionList){
	if(mprivateExtensionList == NULL)
	{
		return -1;
	}
	else
	{
		mprivateExtensionList = privateExtensionList;
		return true;
	}

}

PrivateExtensionList* ExtensionContainer::getprivateExtensionList() {//throw(const char*)
	if(NULL == mprivateExtensionList)
		throw("Object privateExtensionList is NULL");
	else
		return mprivateExtensionList;
}

bool ExtensionContainer::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ExtensionContainer::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setprivateExtensionList())
					return -1;
				if(mprivateExtensionList->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ExtensionContainer Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ExtensionContainer: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ExtensionContainer::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ExtensionContainer: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ExtensionContainer_PRIVATEEXTENSIONLIST:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mprivateExtensionList->Encode(array) < 0) || 
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

	return 0;
}

int ExtensionContainer::Display(int tab){
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
			case ExtensionContainer_PRIVATEEXTENSIONLIST:
			{
				printf(temp, " ", "privateExtensionList");
				if(mprivateExtensionList->Display(tab+1) < 0)
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

bool ExtensionContainer::ValidateMandatory(char *errStr){

	return true;
}
ExtensionField::ExtensionField()
{
	mtype = NULL;
	criticalityDefault = new CriticalityType();
	criticalityDefault->setValue(ignore);;
	mcriticality = NULL;
	mvalue = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0XFFFFFFF0, 0X000A, 0X00A1};
	mTagOptional = {false, false, false};
}

ExtensionField::~ExtensionField()
{
	if(mtype != NULL)
		delete mtype;
	if(mcriticality != NULL)
		delete mcriticality;
	if(criticalityDefault != NULL)
		delete criticalityDefault;
	if(mvalue != NULL)
		delete mvalue;
}

Code* ExtensionField::settype(){
	if(mtype == NULL)
	{
		mtype = new Code();
		mTagsPresent |= ExtensionField_TYPE;
		return mtype;
	}
	else
		return mtype;

}

bool ExtensionField::settype(Code* type){
	if(mtype == NULL)
	{
		return -1;
	}
	else
	{
		mtype = type;
		return true;
	}

}

CriticalityType* ExtensionField::setcriticality(){
	if(mcriticality == NULL)
	{
		mcriticality = new CriticalityType();
		mTagsPresent |= ExtensionField_CRITICALITY;
		return mcriticality;
	}
	else
		return mcriticality;

}

bool ExtensionField::setcriticality(CriticalityType* criticality){
	if(mcriticality == NULL)
	{
		return -1;
	}
	else
	{
		mcriticality = criticality;
		return true;
	}

}

SupportedExtensionsExtensionType* ExtensionField::setvalue(){
	if(mvalue == NULL)
	{
		mvalue = new SupportedExtensionsExtensionType();
		mTagsPresent |= ExtensionField_VALUE;
		return mvalue;
	}
	else
		return mvalue;

}

bool ExtensionField::setvalue(SupportedExtensionsExtensionType* value){
	if(mvalue == NULL)
	{
		return -1;
	}
	else
	{
		mvalue = value;
		return true;
	}

}

Code* ExtensionField::gettype() {//throw(const char*)
	if(NULL == mtype)
		throw("Object type is NULL");
	else
		return mtype;
}

CriticalityType* ExtensionField::getcriticality() {//throw(const char*)
	if(NULL == mcriticality)
		throw("Object criticality is NULL");
	else
		return mcriticality;
}

SupportedExtensionsExtensionType* ExtensionField::getvalue() {//throw(const char*)
	if(NULL == mvalue)
		throw("Object value is NULL");
	else
		return mvalue;
}

bool ExtensionField::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ExtensionField::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0XFFFFFFF0:
				if(NULL == this->settype())
					return -1;
				if(mtype->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X000A:
				if(NULL == this->setcriticality())
					return -1;
				if(mcriticality->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setvalue())
					return -1;
				if(mvalue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ExtensionField Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ExtensionField: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ExtensionField::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ExtensionField: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ExtensionField_TYPE:
				if(asn1_tag_encode(-16, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtype->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ExtensionField_CRITICALITY:
				if(asn1_tag_encode(10, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcriticality->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ExtensionField_VALUE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mvalue->Encode(array) < 0) || 
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

	return 0;
}

int ExtensionField::Display(int tab){
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
			case ExtensionField_TYPE:
			{
				printf(temp, " ", "type");
				if(mtype->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ExtensionField_CRITICALITY:
			{
				printf(temp, " ", "criticality");
				if(mcriticality->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ExtensionField_VALUE:
			{
				printf(temp, " ", "value");
				if(mvalue->Display(tab+1) < 0)
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

bool ExtensionField::ValidateMandatory(char *errStr){
	if(NULL == mtype)
	{
		strcpy(errStr, "type");
		return false;
	}
	else if(NULL == mcriticality)
	{
		strcpy(errStr, "criticality");
		return false;
	}
	else if(NULL == mvalue)
	{
		strcpy(errStr, "value");
		return false;
	}

	return true;
}

Extensions::Extensions()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 0;
	mParamList.clear();
}

Extensions::~Extensions()
{
	vector<ExtensionField *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

ExtensionField* Extensions::getExtensionField()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<ExtensionField *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object ExtensionField is NULL");
}

ExtensionField* Extensions::getNextExtensionField()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<ExtensionField *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object ExtensionField is NULL");
}

ExtensionField* Extensions::getExtensionFieldAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<ExtensionField *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object ExtensionField is NULL");
}

unsigned Extensions::getNoOfExtensionField()
{
	return mParamList.size();
}

bool Extensions::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

ExtensionField* Extensions::setNewExtensionField()
{
	mExtensionField = new ExtensionField();
	if(NULL == mExtensionField)
		return NULL;
	mParamList.push_back(mExtensionField);
	mCounter++;
	return mExtensionField;
}

ExtensionField* Extensions::setExtensionField()
{
	if(NULL == mExtensionField)
		return NULL;
	return mExtensionField;
}

int Extensions::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				this->setNewExtensionField();
				if(mExtensionField->Decode(array, &bytesDecoded) < 0)
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
int Extensions::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<ExtensionField *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(48, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int Extensions::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<ExtensionField *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "ExtensionField");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

FCIBCCCAMELsequence1::FCIBCCCAMELsequence1()
{
	mfreeFormatData = NULL;
	partyToChargeDefault = new SendingSideID();
	partyToChargeDefault->setsendingSideID()->setValue("1");;
	mpartyToCharge = NULL;
	appendFreeFormatDataDefault = new AppendFreeFormatData();
	appendFreeFormatDataDefault->setValue(overwrite);;
	mappendFreeFormatData = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X00A1, 0X0082};
	mTagOptional = {false, false, false};
}

FCIBCCCAMELsequence1::~FCIBCCCAMELsequence1()
{
	if(mfreeFormatData != NULL)
		delete mfreeFormatData;
	if(mpartyToCharge != NULL)
		delete mpartyToCharge;
	if(partyToChargeDefault != NULL)
		delete partyToChargeDefault;
	if(mappendFreeFormatData != NULL)
		delete mappendFreeFormatData;
	if(appendFreeFormatDataDefault != NULL)
		delete appendFreeFormatDataDefault;
}

capstd::OctetString* FCIBCCCAMELsequence1::setfreeFormatData(){
	if(mfreeFormatData == NULL)
	{
		mfreeFormatData = new capstd::OctetString(1, 160);
		mTagsPresent |= FCIBCCCAMELsequence1_FREEFORMATDATA;
		return mfreeFormatData;
	}
	else
		return mfreeFormatData;

}

bool FCIBCCCAMELsequence1::setfreeFormatData(capstd::OctetString* freeFormatData){
	if(mfreeFormatData == NULL)
	{
		return -1;
	}
	else
	{
		mfreeFormatData = freeFormatData;
		return true;
	}

}

SendingSideID* FCIBCCCAMELsequence1::setpartyToCharge(){
	if(mpartyToCharge == NULL)
	{
		mpartyToCharge = new SendingSideID();
		mTagsPresent |= FCIBCCCAMELsequence1_PARTYTOCHARGE;
		return mpartyToCharge;
	}
	else
		return mpartyToCharge;

}

bool FCIBCCCAMELsequence1::setpartyToCharge(SendingSideID* partyToCharge){
	if(mpartyToCharge == NULL)
	{
		return -1;
	}
	else
	{
		mpartyToCharge = partyToCharge;
		return true;
	}

}

AppendFreeFormatData* FCIBCCCAMELsequence1::setappendFreeFormatData(){
	if(mappendFreeFormatData == NULL)
	{
		mappendFreeFormatData = new AppendFreeFormatData();
		mTagsPresent |= FCIBCCCAMELsequence1_APPENDFREEFORMATDATA;
		return mappendFreeFormatData;
	}
	else
		return mappendFreeFormatData;

}

bool FCIBCCCAMELsequence1::setappendFreeFormatData(AppendFreeFormatData* appendFreeFormatData){
	if(mappendFreeFormatData == NULL)
	{
		return -1;
	}
	else
	{
		mappendFreeFormatData = appendFreeFormatData;
		return true;
	}

}

capstd::OctetString* FCIBCCCAMELsequence1::getfreeFormatData() {//throw(const char*)
	if(NULL == mfreeFormatData)
		throw("Object freeFormatData is NULL");
	else
		return mfreeFormatData;
}

SendingSideID* FCIBCCCAMELsequence1::getpartyToCharge() {//throw(const char*)
	if(NULL == mpartyToCharge)
		throw("Object partyToCharge is NULL");
	else
		return mpartyToCharge;
}

AppendFreeFormatData* FCIBCCCAMELsequence1::getappendFreeFormatData() {//throw(const char*)
	if(NULL == mappendFreeFormatData)
		throw("Object appendFreeFormatData is NULL");
	else
		return mappendFreeFormatData;
}

bool FCIBCCCAMELsequence1::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int FCIBCCCAMELsequence1::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setfreeFormatData())
					return -1;
				if(mfreeFormatData->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setpartyToCharge())
					return -1;
				if(mpartyToCharge->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setappendFreeFormatData())
					return -1;
				if(mappendFreeFormatData->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: FCIBCCCAMELsequence1 Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("FCIBCCCAMELsequence1: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int FCIBCCCAMELsequence1::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("FCIBCCCAMELsequence1: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case FCIBCCCAMELsequence1_FREEFORMATDATA:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mfreeFormatData->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case FCIBCCCAMELsequence1_PARTYTOCHARGE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpartyToCharge->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case FCIBCCCAMELsequence1_APPENDFREEFORMATDATA:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mappendFreeFormatData->Encode(array) < 0) || 
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

	return 0;
}

int FCIBCCCAMELsequence1::Display(int tab){
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
			case FCIBCCCAMELsequence1_FREEFORMATDATA:
			{
				printf(temp, " ", "freeFormatData");
				if(mfreeFormatData->Display(tab+1) < 0)
					return -1;
				break;
			}
			case FCIBCCCAMELsequence1_PARTYTOCHARGE:
			{
				printf(temp, " ", "partyToCharge");
				if(mpartyToCharge->Display(tab+1) < 0)
					return -1;
				break;
			}
			case FCIBCCCAMELsequence1_APPENDFREEFORMATDATA:
			{
				printf(temp, " ", "appendFreeFormatData");
				if(mappendFreeFormatData->Display(tab+1) < 0)
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

bool FCIBCCCAMELsequence1::ValidateMandatory(char *errStr){
	if(NULL == mfreeFormatData)
	{
		strcpy(errStr, "freeFormatData");
		return false;
	}
	else if(NULL == mpartyToCharge)
	{
		strcpy(errStr, "partyToCharge");
		return false;
	}
	else if(NULL == mappendFreeFormatData)
	{
		strcpy(errStr, "appendFreeFormatData");
		return false;
	}

	return true;
}
ForwardServiceInteractionInd::ForwardServiceInteractionInd()
{
	mconferenceTreatmentIndicator = NULL;
	mcallDiversionTreatmentIndicator = NULL;
	mcallingPartyRestrictionIndicator = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0081, 0X0082, 0X0084};
	mTagOptional = {true, true, true};
}

ForwardServiceInteractionInd::~ForwardServiceInteractionInd()
{
	if(mconferenceTreatmentIndicator != NULL)
		delete mconferenceTreatmentIndicator;
	if(mcallDiversionTreatmentIndicator != NULL)
		delete mcallDiversionTreatmentIndicator;
	if(mcallingPartyRestrictionIndicator != NULL)
		delete mcallingPartyRestrictionIndicator;
}

capstd::OctetString* ForwardServiceInteractionInd::setconferenceTreatmentIndicator(){
	if(mconferenceTreatmentIndicator == NULL)
	{
		mconferenceTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ForwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR;
		return mconferenceTreatmentIndicator;
	}
	else
		return mconferenceTreatmentIndicator;

}

bool ForwardServiceInteractionInd::setconferenceTreatmentIndicator(capstd::OctetString* conferenceTreatmentIndicator){
	if(mconferenceTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mconferenceTreatmentIndicator = conferenceTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* ForwardServiceInteractionInd::setcallDiversionTreatmentIndicator(){
	if(mcallDiversionTreatmentIndicator == NULL)
	{
		mcallDiversionTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ForwardServiceInteractionInd_CALLDIVERSIONTREATMENTINDICATOR;
		return mcallDiversionTreatmentIndicator;
	}
	else
		return mcallDiversionTreatmentIndicator;

}

bool ForwardServiceInteractionInd::setcallDiversionTreatmentIndicator(capstd::OctetString* callDiversionTreatmentIndicator){
	if(mcallDiversionTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mcallDiversionTreatmentIndicator = callDiversionTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* ForwardServiceInteractionInd::setcallingPartyRestrictionIndicator(){
	if(mcallingPartyRestrictionIndicator == NULL)
	{
		mcallingPartyRestrictionIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ForwardServiceInteractionInd_CALLINGPARTYRESTRICTIONINDICATOR;
		return mcallingPartyRestrictionIndicator;
	}
	else
		return mcallingPartyRestrictionIndicator;

}

bool ForwardServiceInteractionInd::setcallingPartyRestrictionIndicator(capstd::OctetString* callingPartyRestrictionIndicator){
	if(mcallingPartyRestrictionIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mcallingPartyRestrictionIndicator = callingPartyRestrictionIndicator;
		return true;
	}

}

capstd::OctetString* ForwardServiceInteractionInd::getconferenceTreatmentIndicator() {//throw(const char*)
	if(NULL == mconferenceTreatmentIndicator)
		throw("Object conferenceTreatmentIndicator is NULL");
	else
		return mconferenceTreatmentIndicator;
}

capstd::OctetString* ForwardServiceInteractionInd::getcallDiversionTreatmentIndicator() {//throw(const char*)
	if(NULL == mcallDiversionTreatmentIndicator)
		throw("Object callDiversionTreatmentIndicator is NULL");
	else
		return mcallDiversionTreatmentIndicator;
}

capstd::OctetString* ForwardServiceInteractionInd::getcallingPartyRestrictionIndicator() {//throw(const char*)
	if(NULL == mcallingPartyRestrictionIndicator)
		throw("Object callingPartyRestrictionIndicator is NULL");
	else
		return mcallingPartyRestrictionIndicator;
}

bool ForwardServiceInteractionInd::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ForwardServiceInteractionInd::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X0081:
				if(NULL == this->setconferenceTreatmentIndicator())
					return -1;
				if(mconferenceTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setcallDiversionTreatmentIndicator())
					return -1;
				if(mcallDiversionTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setcallingPartyRestrictionIndicator())
					return -1;
				if(mcallingPartyRestrictionIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ForwardServiceInteractionInd Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ForwardServiceInteractionInd: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ForwardServiceInteractionInd::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ForwardServiceInteractionInd: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ForwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mconferenceTreatmentIndicator->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ForwardServiceInteractionInd_CALLDIVERSIONTREATMENTINDICATOR:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallDiversionTreatmentIndicator->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ForwardServiceInteractionInd_CALLINGPARTYRESTRICTIONINDICATOR:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallingPartyRestrictionIndicator->Encode(array) < 0) || 
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

	return 0;
}

int ForwardServiceInteractionInd::Display(int tab){
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
			case ForwardServiceInteractionInd_CONFERENCETREATMENTINDICATOR:
			{
				printf(temp, " ", "conferenceTreatmentIndicator");
				if(mconferenceTreatmentIndicator->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ForwardServiceInteractionInd_CALLDIVERSIONTREATMENTINDICATOR:
			{
				printf(temp, " ", "callDiversionTreatmentIndicator");
				if(mcallDiversionTreatmentIndicator->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ForwardServiceInteractionInd_CALLINGPARTYRESTRICTIONINDICATOR:
			{
				printf(temp, " ", "callingPartyRestrictionIndicator");
				if(mcallingPartyRestrictionIndicator->Display(tab+1) < 0)
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

bool ForwardServiceInteractionInd::ValidateMandatory(char *errStr){

	return true;
}
GPRSMSClass::GPRSMSClass()
{
	mmSNetworkCapability = NULL;
	mmSRadioAccessCapability = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, true};
}

GPRSMSClass::~GPRSMSClass()
{
	if(mmSNetworkCapability != NULL)
		delete mmSNetworkCapability;
	if(mmSRadioAccessCapability != NULL)
		delete mmSRadioAccessCapability;
}

capstd::OctetString* GPRSMSClass::setmSNetworkCapability(){
	if(mmSNetworkCapability == NULL)
	{
		mmSNetworkCapability = new capstd::OctetString(1, 8);
		mTagsPresent |= GPRSMSClass_MSNETWORKCAPABILITY;
		return mmSNetworkCapability;
	}
	else
		return mmSNetworkCapability;

}

bool GPRSMSClass::setmSNetworkCapability(capstd::OctetString* mSNetworkCapability){
	if(mmSNetworkCapability == NULL)
	{
		return -1;
	}
	else
	{
		mmSNetworkCapability = mSNetworkCapability;
		return true;
	}

}

capstd::OctetString* GPRSMSClass::setmSRadioAccessCapability(){
	if(mmSRadioAccessCapability == NULL)
	{
		mmSRadioAccessCapability = new capstd::OctetString(1, 50);
		mTagsPresent |= GPRSMSClass_MSRADIOACCESSCAPABILITY;
		return mmSRadioAccessCapability;
	}
	else
		return mmSRadioAccessCapability;

}

bool GPRSMSClass::setmSRadioAccessCapability(capstd::OctetString* mSRadioAccessCapability){
	if(mmSRadioAccessCapability == NULL)
	{
		return -1;
	}
	else
	{
		mmSRadioAccessCapability = mSRadioAccessCapability;
		return true;
	}

}

capstd::OctetString* GPRSMSClass::getmSNetworkCapability() {//throw(const char*)
	if(NULL == mmSNetworkCapability)
		throw("Object mSNetworkCapability is NULL");
	else
		return mmSNetworkCapability;
}

capstd::OctetString* GPRSMSClass::getmSRadioAccessCapability() {//throw(const char*)
	if(NULL == mmSRadioAccessCapability)
		throw("Object mSRadioAccessCapability is NULL");
	else
		return mmSRadioAccessCapability;
}

bool GPRSMSClass::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int GPRSMSClass::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setmSNetworkCapability())
					return -1;
				if(mmSNetworkCapability->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setmSRadioAccessCapability())
					return -1;
				if(mmSRadioAccessCapability->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: GPRSMSClass Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("GPRSMSClass: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int GPRSMSClass::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("GPRSMSClass: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case GPRSMSClass_MSNETWORKCAPABILITY:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmSNetworkCapability->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case GPRSMSClass_MSRADIOACCESSCAPABILITY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmSRadioAccessCapability->Encode(array) < 0) || 
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

	return 0;
}

int GPRSMSClass::Display(int tab){
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
			case GPRSMSClass_MSNETWORKCAPABILITY:
			{
				printf(temp, " ", "mSNetworkCapability");
				if(mmSNetworkCapability->Display(tab+1) < 0)
					return -1;
				break;
			}
			case GPRSMSClass_MSRADIOACCESSCAPABILITY:
			{
				printf(temp, " ", "mSRadioAccessCapability");
				if(mmSRadioAccessCapability->Display(tab+1) < 0)
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

bool GPRSMSClass::ValidateMandatory(char *errStr){
	if(NULL == mmSNetworkCapability)
	{
		strcpy(errStr, "mSNetworkCapability");
		return false;
	}

	return true;
}
GapCriteria::GapCriteria()
{
	mbasicGapCriteria = NULL;
	mcompoundGapCriteria = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0XFFFFFFFF, 0X0030};
}

GapCriteria::~GapCriteria()
{
	if(mbasicGapCriteria != NULL)
		delete mbasicGapCriteria;
	if(mcompoundGapCriteria != NULL)
		delete mcompoundGapCriteria;
}

BasicGapCriteria* GapCriteria::setbasicGapCriteria(){
if(mParamSet == true)
	{
		if(mbasicGapCriteria != NULL)
			return mbasicGapCriteria;
		else
			return NULL;
	}
	if(mbasicGapCriteria == NULL)
	{
		mbasicGapCriteria = new BasicGapCriteria();
		mTagsPresent |= GapCriteria_BASICGAPCRITERIA;
		mParamSet = true;
		return mbasicGapCriteria;
	}
}

bool GapCriteria::setbasicGapCriteria(BasicGapCriteria* basicGapCriteria){
	if(mbasicGapCriteria == NULL)
	{
		return -1;
	}
	else
	{
		mbasicGapCriteria = basicGapCriteria;
		return true;
	}

}

CompoundCriteria* GapCriteria::setcompoundGapCriteria(){
if(mParamSet == true)
	{
		if(mcompoundGapCriteria != NULL)
			return mcompoundGapCriteria;
		else
			return NULL;
	}
	if(mcompoundGapCriteria == NULL)
	{
		mcompoundGapCriteria = new CompoundCriteria();
		mTagsPresent |= GapCriteria_COMPOUNDGAPCRITERIA;
		mParamSet = true;
		return mcompoundGapCriteria;
	}
}

bool GapCriteria::setcompoundGapCriteria(CompoundCriteria* compoundGapCriteria){
	if(mcompoundGapCriteria == NULL)
	{
		return -1;
	}
	else
	{
		mcompoundGapCriteria = compoundGapCriteria;
		return true;
	}

}

BasicGapCriteria* GapCriteria::getbasicGapCriteria() {//throw(const char*)
	if(NULL == mbasicGapCriteria)
		throw("Object basicGapCriteria is NULL");
	else
		return mbasicGapCriteria;
}

CompoundCriteria* GapCriteria::getcompoundGapCriteria() {//throw(const char*)
	if(NULL == mcompoundGapCriteria)
		throw("Object compoundGapCriteria is NULL");
	else
		return mcompoundGapCriteria;
}

bool GapCriteria::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int GapCriteria::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
			case 0X00A2:
			case 0X00BD:
			case 0X00BE:
				array->offset -= tagSize;
				tagSize = 0;
				if(NULL == this->setbasicGapCriteria())
					return -1;
				if(mbasicGapCriteria->Decode(array, &bytesDecoded, false) < 0)
					decode = false;
				break;
			case 0X0030:
				if(NULL == this->setcompoundGapCriteria())
					return -1;
				if(mcompoundGapCriteria->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: GapCriteria Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("GapCriteria: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int GapCriteria::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("GapCriteria: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case GapCriteria_BASICGAPCRITERIA:
				if((mbasicGapCriteria->Encode(array) < 0))
					return -1;
				mParamSet = false;
				break;
			case GapCriteria_COMPOUNDGAPCRITERIA:
				if(asn1_tag_encode(48, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcompoundGapCriteria->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int GapCriteria::Display(int tab){
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
			case GapCriteria_BASICGAPCRITERIA:
			{
				printf(temp, " ", "basicGapCriteria");
				if(mbasicGapCriteria->Display(tab+1) < 0)
					return -1;
				break;
			}
			case GapCriteria_COMPOUNDGAPCRITERIA:
			{
				printf(temp, " ", "compoundGapCriteria");
				if(mcompoundGapCriteria->Display(tab+1) < 0)
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

bool GapCriteria::ValidateMandatory(char *errStr){

	return true;
}
GapIndicators::GapIndicators()
{
	mduration = NULL;
	mgapInterval = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, false};
}

GapIndicators::~GapIndicators()
{
	if(mduration != NULL)
		delete mduration;
	if(mgapInterval != NULL)
		delete mgapInterval;
}

capstd::INTEGER* GapIndicators::setduration(){
	if(mduration == NULL)
	{
		mduration = new capstd::INTEGER(2, 86400);
		mTagsPresent |= GapIndicators_DURATION;
		return mduration;
	}
	else
		return mduration;

}

bool GapIndicators::setduration(capstd::INTEGER* duration){
	if(mduration == NULL)
	{
		return -1;
	}
	else
	{
		mduration = duration;
		return true;
	}

}

capstd::INTEGER* GapIndicators::setgapInterval(){
	if(mgapInterval == NULL)
	{
		mgapInterval = new capstd::INTEGER(1, 60000);
		mTagsPresent |= GapIndicators_GAPINTERVAL;
		return mgapInterval;
	}
	else
		return mgapInterval;

}

bool GapIndicators::setgapInterval(capstd::INTEGER* gapInterval){
	if(mgapInterval == NULL)
	{
		return -1;
	}
	else
	{
		mgapInterval = gapInterval;
		return true;
	}

}

capstd::INTEGER* GapIndicators::getduration() {//throw(const char*)
	if(NULL == mduration)
		throw("Object duration is NULL");
	else
		return mduration;
}

capstd::INTEGER* GapIndicators::getgapInterval() {//throw(const char*)
	if(NULL == mgapInterval)
		throw("Object gapInterval is NULL");
	else
		return mgapInterval;
}

bool GapIndicators::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int GapIndicators::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setduration())
					return -1;
				if(mduration->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setgapInterval())
					return -1;
				if(mgapInterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: GapIndicators Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("GapIndicators: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int GapIndicators::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("GapIndicators: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case GapIndicators_DURATION:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mduration->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case GapIndicators_GAPINTERVAL:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgapInterval->Encode(array) < 0) || 
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

	return 0;
}

int GapIndicators::Display(int tab){
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
			case GapIndicators_DURATION:
			{
				printf(temp, " ", "duration");
				if(mduration->Display(tab+1) < 0)
					return -1;
				break;
			}
			case GapIndicators_GAPINTERVAL:
			{
				printf(temp, " ", "gapInterval");
				if(mgapInterval->Display(tab+1) < 0)
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

bool GapIndicators::ValidateMandatory(char *errStr){
	if(NULL == mduration)
	{
		strcpy(errStr, "duration");
		return false;
	}
	else if(NULL == mgapInterval)
	{
		strcpy(errStr, "gapInterval");
		return false;
	}

	return true;
}
GapOnService::GapOnService()
{
	mserviceKey = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {false};
}

GapOnService::~GapOnService()
{
	if(mserviceKey != NULL)
		delete mserviceKey;
}

capstd::INTEGER* GapOnService::setserviceKey(){
	if(mserviceKey == NULL)
	{
		mserviceKey = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= GapOnService_SERVICEKEY;
		return mserviceKey;
	}
	else
		return mserviceKey;

}

bool GapOnService::setserviceKey(capstd::INTEGER* serviceKey){
	if(mserviceKey == NULL)
	{
		return -1;
	}
	else
	{
		mserviceKey = serviceKey;
		return true;
	}

}

capstd::INTEGER* GapOnService::getserviceKey() {//throw(const char*)
	if(NULL == mserviceKey)
		throw("Object serviceKey is NULL");
	else
		return mserviceKey;
}

bool GapOnService::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int GapOnService::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setserviceKey())
					return -1;
				if(mserviceKey->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: GapOnService Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("GapOnService: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int GapOnService::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("GapOnService: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case GapOnService_SERVICEKEY:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mserviceKey->Encode(array) < 0) || 
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

	return 0;
}

int GapOnService::Display(int tab){
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
			case GapOnService_SERVICEKEY:
			{
				printf(temp, " ", "serviceKey");
				if(mserviceKey->Display(tab+1) < 0)
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

bool GapOnService::ValidateMandatory(char *errStr){
	if(NULL == mserviceKey)
	{
		strcpy(errStr, "serviceKey");
		return false;
	}

	return true;
}
GapTreatment::GapTreatment()
{
	minformationToSend = NULL;
	mreleaseCause = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0, 0X0081};
}

GapTreatment::~GapTreatment()
{
	if(minformationToSend != NULL)
		delete minformationToSend;
	if(mreleaseCause != NULL)
		delete mreleaseCause;
}

InformationToSend* GapTreatment::setinformationToSend(){
if(mParamSet == true)
	{
		if(minformationToSend != NULL)
			return minformationToSend;
		else
			return NULL;
	}
	if(minformationToSend == NULL)
	{
		minformationToSend = new InformationToSend();
		mTagsPresent |= GapTreatment_INFORMATIONTOSEND;
		mParamSet = true;
		return minformationToSend;
	}
}

bool GapTreatment::setinformationToSend(InformationToSend* informationToSend){
	if(minformationToSend == NULL)
	{
		return -1;
	}
	else
	{
		minformationToSend = informationToSend;
		return true;
	}

}

capstd::GENERIC* GapTreatment::setreleaseCause(){
if(mParamSet == true)
	{
		if(mreleaseCause != NULL)
			return mreleaseCause;
		else
			return NULL;
	}
	if(mreleaseCause == NULL)
	{
		mreleaseCause = new capstd::GENERIC();
		mTagsPresent |= GapTreatment_RELEASECAUSE;
		mParamSet = true;
		return mreleaseCause;
	}
}

bool GapTreatment::setreleaseCause(capstd::GENERIC* releaseCause){
	if(mreleaseCause == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseCause = releaseCause;
		return true;
	}

}

InformationToSend* GapTreatment::getinformationToSend() {//throw(const char*)
	if(NULL == minformationToSend)
		throw("Object informationToSend is NULL");
	else
		return minformationToSend;
}

capstd::GENERIC* GapTreatment::getreleaseCause() {//throw(const char*)
	if(NULL == mreleaseCause)
		throw("Object releaseCause is NULL");
	else
		return mreleaseCause;
}

bool GapTreatment::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int GapTreatment::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setinformationToSend())
					return -1;
				if(minformationToSend->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setreleaseCause())
					return -1;
				if(mreleaseCause->Decode(array, &bytesDecoded, mTagArray, GapTreatment_RELEASECAUSE) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: GapTreatment Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("GapTreatment: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int GapTreatment::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("GapTreatment: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case GapTreatment_INFORMATIONTOSEND:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minformationToSend->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case GapTreatment_RELEASECAUSE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseCause->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int GapTreatment::Display(int tab){
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
			case GapTreatment_INFORMATIONTOSEND:
			{
				printf(temp, " ", "informationToSend");
				if(minformationToSend->Display(tab+1) < 0)
					return -1;
				break;
			}
			case GapTreatment_RELEASECAUSE:
			{
				printf(temp, " ", "releaseCause");
				if(mreleaseCause->Display(tab+1) < 0)
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

bool GapTreatment::ValidateMandatory(char *errStr){

	return true;
}

GenericNumbers::GenericNumbers()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 5;
	mParamList.clear();
}

GenericNumbers::~GenericNumbers()
{
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

capstd::OctetString* GenericNumbers::getOctetString()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* GenericNumbers::getNextOctetString()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* GenericNumbers::getOctetStringAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object OctetString is NULL");
}

unsigned GenericNumbers::getNoOfOctetString()
{
	return mParamList.size();
}

bool GenericNumbers::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

capstd::OctetString* GenericNumbers::setNewOctetString()
{
	mOctetString = new capstd::OctetString(3, 11);
	if(NULL == mOctetString)
		return NULL;
	mParamList.push_back(mOctetString);
	mCounter++;
	return mOctetString;
}

capstd::OctetString* GenericNumbers::setOctetString()
{
	if(NULL == mOctetString)
		return NULL;
	return mOctetString;
}

int GenericNumbers::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0004:
				this->setNewOctetString();
				if(mOctetString->Decode(array, &bytesDecoded) < 0)
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
int GenericNumbers::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(4, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int GenericNumbers::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "OctetString");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}


IMS_VoiceOverPS_SessionsInd::IMS_VoiceOverPS_SessionsInd()
{
	mTag = 0X000A;
}

IMS_VoiceOverPS_SessionsInd::~IMS_VoiceOverPS_SessionsInd()
{
}

bool IMS_VoiceOverPS_SessionsInd::setValue(IMS_VOICEOVERPS_SESSIONSIND val)
{
	mValue = val;
	return true;
}

IMS_VOICEOVERPS_SESSIONSIND IMS_VoiceOverPS_SessionsInd::getValue()
{
	return mValue;
}

int IMS_VoiceOverPS_SessionsInd::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (IMS_VOICEOVERPS_SESSIONSIND)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int IMS_VoiceOverPS_SessionsInd::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int IMS_VoiceOverPS_SessionsInd::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", IMS_VOICEOVERPS_SESSIONSIND_str(mValue), mValue);
	return 0;
}

InbandInfo::InbandInfo()
{
	mmessageID = NULL;
	mnumberOfRepetitions = NULL;
	mduration = NULL;
	minterval = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081, 0X0082, 0X0083};
	mTagOptional = {false, true, true, true};
}

InbandInfo::~InbandInfo()
{
	if(mmessageID != NULL)
		delete mmessageID;
	if(mnumberOfRepetitions != NULL)
		delete mnumberOfRepetitions;
	if(mduration != NULL)
		delete mduration;
	if(minterval != NULL)
		delete minterval;
}

MessageID* InbandInfo::setmessageID(){
	if(mmessageID == NULL)
	{
		mmessageID = new MessageID();
		mTagsPresent |= InbandInfo_MESSAGEID;
		return mmessageID;
	}
	else
		return mmessageID;

}

bool InbandInfo::setmessageID(MessageID* messageID){
	if(mmessageID == NULL)
	{
		return -1;
	}
	else
	{
		mmessageID = messageID;
		return true;
	}

}

capstd::INTEGER* InbandInfo::setnumberOfRepetitions(){
	if(mnumberOfRepetitions == NULL)
	{
		mnumberOfRepetitions = new capstd::INTEGER(1, 127);
		mTagsPresent |= InbandInfo_NUMBEROFREPETITIONS;
		return mnumberOfRepetitions;
	}
	else
		return mnumberOfRepetitions;

}

bool InbandInfo::setnumberOfRepetitions(capstd::INTEGER* numberOfRepetitions){
	if(mnumberOfRepetitions == NULL)
	{
		return -1;
	}
	else
	{
		mnumberOfRepetitions = numberOfRepetitions;
		return true;
	}

}

capstd::INTEGER* InbandInfo::setduration(){
	if(mduration == NULL)
	{
		mduration = new capstd::INTEGER(0, 32767);
		mTagsPresent |= InbandInfo_DURATION;
		return mduration;
	}
	else
		return mduration;

}

bool InbandInfo::setduration(capstd::INTEGER* duration){
	if(mduration == NULL)
	{
		return -1;
	}
	else
	{
		mduration = duration;
		return true;
	}

}

capstd::INTEGER* InbandInfo::setinterval(){
	if(minterval == NULL)
	{
		minterval = new capstd::INTEGER(0, 32767);
		mTagsPresent |= InbandInfo_INTERVAL;
		return minterval;
	}
	else
		return minterval;

}

bool InbandInfo::setinterval(capstd::INTEGER* interval){
	if(minterval == NULL)
	{
		return -1;
	}
	else
	{
		minterval = interval;
		return true;
	}

}

MessageID* InbandInfo::getmessageID() {//throw(const char*)
	if(NULL == mmessageID)
		throw("Object messageID is NULL");
	else
		return mmessageID;
}

capstd::INTEGER* InbandInfo::getnumberOfRepetitions() {//throw(const char*)
	if(NULL == mnumberOfRepetitions)
		throw("Object numberOfRepetitions is NULL");
	else
		return mnumberOfRepetitions;
}

capstd::INTEGER* InbandInfo::getduration() {//throw(const char*)
	if(NULL == mduration)
		throw("Object duration is NULL");
	else
		return mduration;
}

capstd::INTEGER* InbandInfo::getinterval() {//throw(const char*)
	if(NULL == minterval)
		throw("Object interval is NULL");
	else
		return minterval;
}

bool InbandInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int InbandInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setmessageID())
					return -1;
				if(mmessageID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setnumberOfRepetitions())
					return -1;
				if(mnumberOfRepetitions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setduration())
					return -1;
				if(mduration->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setinterval())
					return -1;
				if(minterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: InbandInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("InbandInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int InbandInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InbandInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case InbandInfo_MESSAGEID:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmessageID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InbandInfo_NUMBEROFREPETITIONS:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnumberOfRepetitions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InbandInfo_DURATION:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mduration->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case InbandInfo_INTERVAL:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minterval->Encode(array) < 0) || 
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

	return 0;
}

int InbandInfo::Display(int tab){
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
			case InbandInfo_MESSAGEID:
			{
				printf(temp, " ", "messageID");
				if(mmessageID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InbandInfo_NUMBEROFREPETITIONS:
			{
				printf(temp, " ", "numberOfRepetitions");
				if(mnumberOfRepetitions->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InbandInfo_DURATION:
			{
				printf(temp, " ", "duration");
				if(mduration->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InbandInfo_INTERVAL:
			{
				printf(temp, " ", "interval");
				if(minterval->Display(tab+1) < 0)
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

bool InbandInfo::ValidateMandatory(char *errStr){
	if(NULL == mmessageID)
	{
		strcpy(errStr, "messageID");
		return false;
	}

	return true;
}
InformationToSend::InformationToSend()
{
	minbandInfo = NULL;
	mtone = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0, 0X00A1};
}

InformationToSend::~InformationToSend()
{
	if(minbandInfo != NULL)
		delete minbandInfo;
	if(mtone != NULL)
		delete mtone;
}

InbandInfo* InformationToSend::setinbandInfo(){
if(mParamSet == true)
	{
		if(minbandInfo != NULL)
			return minbandInfo;
		else
			return NULL;
	}
	if(minbandInfo == NULL)
	{
		minbandInfo = new InbandInfo();
		mTagsPresent |= InformationToSend_INBANDINFO;
		mParamSet = true;
		return minbandInfo;
	}
}

bool InformationToSend::setinbandInfo(InbandInfo* inbandInfo){
	if(minbandInfo == NULL)
	{
		return -1;
	}
	else
	{
		minbandInfo = inbandInfo;
		return true;
	}

}

Tone* InformationToSend::settone(){
if(mParamSet == true)
	{
		if(mtone != NULL)
			return mtone;
		else
			return NULL;
	}
	if(mtone == NULL)
	{
		mtone = new Tone();
		mTagsPresent |= InformationToSend_TONE;
		mParamSet = true;
		return mtone;
	}
}

bool InformationToSend::settone(Tone* tone){
	if(mtone == NULL)
	{
		return -1;
	}
	else
	{
		mtone = tone;
		return true;
	}

}

InbandInfo* InformationToSend::getinbandInfo() {//throw(const char*)
	if(NULL == minbandInfo)
		throw("Object inbandInfo is NULL");
	else
		return minbandInfo;
}

Tone* InformationToSend::gettone() {//throw(const char*)
	if(NULL == mtone)
		throw("Object tone is NULL");
	else
		return mtone;
}

bool InformationToSend::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int InformationToSend::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setinbandInfo())
					return -1;
				if(minbandInfo->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->settone())
					return -1;
				if(mtone->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: InformationToSend Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("InformationToSend: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int InformationToSend::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InformationToSend: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case InformationToSend_INBANDINFO:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minbandInfo->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case InformationToSend_TONE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtone->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int InformationToSend::Display(int tab){
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
			case InformationToSend_INBANDINFO:
			{
				printf(temp, " ", "inbandInfo");
				if(minbandInfo->Display(tab+1) < 0)
					return -1;
				break;
			}
			case InformationToSend_TONE:
			{
				printf(temp, " ", "tone");
				if(mtone->Display(tab+1) < 0)
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

bool InformationToSend::ValidateMandatory(char *errStr){

	return true;
}
InitialDPArgExtension::InitialDPArgExtension()
{
	mgmscAddress = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {true};
}

InitialDPArgExtension::~InitialDPArgExtension()
{
	if(mgmscAddress != NULL)
		delete mgmscAddress;
}

capstd::OctetString* InitialDPArgExtension::setgmscAddress(){
	if(mgmscAddress == NULL)
	{
		mgmscAddress = new capstd::OctetString(1, 0);
		mTagsPresent |= InitialDPArgExtension_GMSCADDRESS;
		return mgmscAddress;
	}
	else
		return mgmscAddress;

}

bool InitialDPArgExtension::setgmscAddress(capstd::OctetString* gmscAddress){
	if(mgmscAddress == NULL)
	{
		return -1;
	}
	else
	{
		mgmscAddress = gmscAddress;
		return true;
	}

}

capstd::OctetString* InitialDPArgExtension::getgmscAddress() {//throw(const char*)
	if(NULL == mgmscAddress)
		throw("Object gmscAddress is NULL");
	else
		return mgmscAddress;
}

bool InitialDPArgExtension::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int InitialDPArgExtension::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setgmscAddress())
					return -1;
				if(mgmscAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: InitialDPArgExtension Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("InitialDPArgExtension: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int InitialDPArgExtension::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("InitialDPArgExtension: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case InitialDPArgExtension_GMSCADDRESS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgmscAddress->Encode(array) < 0) || 
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

	return 0;
}

int InitialDPArgExtension::Display(int tab){
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
			case InitialDPArgExtension_GMSCADDRESS:
			{
				printf(temp, " ", "gmscAddress");
				if(mgmscAddress->Display(tab+1) < 0)
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

bool InitialDPArgExtension::ValidateMandatory(char *errStr){

	return true;
}

InitiatingEntity::InitiatingEntity()
{
	mTag = 0X000A;
}

InitiatingEntity::~InitiatingEntity()
{
}

bool InitiatingEntity::setValue(INITIATINGENTITY val)
{
	mValue = val;
	return true;
}

INITIATINGENTITY InitiatingEntity::getValue()
{
	return mValue;
}

int InitiatingEntity::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (INITIATINGENTITY)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int InitiatingEntity::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int InitiatingEntity::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", INITIATINGENTITY_str(mValue), mValue);
	return 0;
}


LIPA_AllowedAPNList::LIPA_AllowedAPNList()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 50;
	mParamList.clear();
}

LIPA_AllowedAPNList::~LIPA_AllowedAPNList()
{
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

capstd::OctetString* LIPA_AllowedAPNList::getOctetString()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* LIPA_AllowedAPNList::getNextOctetString()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object OctetString is NULL");
}

capstd::OctetString* LIPA_AllowedAPNList::getOctetStringAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object OctetString is NULL");
}

unsigned LIPA_AllowedAPNList::getNoOfOctetString()
{
	return mParamList.size();
}

bool LIPA_AllowedAPNList::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

capstd::OctetString* LIPA_AllowedAPNList::setNewOctetString()
{
	mOctetString = new capstd::OctetString(2, 63);
	if(NULL == mOctetString)
		return NULL;
	mParamList.push_back(mOctetString);
	mCounter++;
	return mOctetString;
}

capstd::OctetString* LIPA_AllowedAPNList::setOctetString()
{
	if(NULL == mOctetString)
		return NULL;
	return mOctetString;
}

int LIPA_AllowedAPNList::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0004:
				this->setNewOctetString();
				if(mOctetString->Decode(array, &bytesDecoded) < 0)
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
int LIPA_AllowedAPNList::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(4, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int LIPA_AllowedAPNList::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<capstd::OctetString *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "OctetString");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

LegID::LegID()
{
	msendingSideID = NULL;
	mreceivingSideID = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081};
}

LegID::~LegID()
{
	if(msendingSideID != NULL)
		delete msendingSideID;
	if(mreceivingSideID != NULL)
		delete mreceivingSideID;
}

capstd::OctetString* LegID::setsendingSideID(){
if(mParamSet == true)
	{
		if(msendingSideID != NULL)
			return msendingSideID;
		else
			return NULL;
	}
	if(msendingSideID == NULL)
	{
		msendingSideID = new capstd::OctetString(1, 1);
		mTagsPresent |= LegID_SENDINGSIDEID;
		mParamSet = true;
		return msendingSideID;
	}
}

bool LegID::setsendingSideID(capstd::OctetString* sendingSideID){
	if(msendingSideID == NULL)
	{
		return -1;
	}
	else
	{
		msendingSideID = sendingSideID;
		return true;
	}

}

capstd::OctetString* LegID::setreceivingSideID(){
if(mParamSet == true)
	{
		if(mreceivingSideID != NULL)
			return mreceivingSideID;
		else
			return NULL;
	}
	if(mreceivingSideID == NULL)
	{
		mreceivingSideID = new capstd::OctetString(1, 1);
		mTagsPresent |= LegID_RECEIVINGSIDEID;
		mParamSet = true;
		return mreceivingSideID;
	}
}

bool LegID::setreceivingSideID(capstd::OctetString* receivingSideID){
	if(mreceivingSideID == NULL)
	{
		return -1;
	}
	else
	{
		mreceivingSideID = receivingSideID;
		return true;
	}

}

capstd::OctetString* LegID::getsendingSideID() {//throw(const char*)
	if(NULL == msendingSideID)
		throw("Object sendingSideID is NULL");
	else
		return msendingSideID;
}

capstd::OctetString* LegID::getreceivingSideID() {//throw(const char*)
	if(NULL == mreceivingSideID)
		throw("Object receivingSideID is NULL");
	else
		return mreceivingSideID;
}

bool LegID::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int LegID::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setsendingSideID())
					return -1;
				if(msendingSideID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setreceivingSideID())
					return -1;
				if(mreceivingSideID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: LegID Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("LegID: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int LegID::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("LegID: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case LegID_SENDINGSIDEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msendingSideID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case LegID_RECEIVINGSIDEID:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreceivingSideID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int LegID::Display(int tab){
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
			case LegID_SENDINGSIDEID:
			{
				printf(temp, " ", "sendingSideID");
				if(msendingSideID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LegID_RECEIVINGSIDEID:
			{
				printf(temp, " ", "receivingSideID");
				if(mreceivingSideID->Display(tab+1) < 0)
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

bool LegID::ValidateMandatory(char *errStr){

	return true;
}
LocationInformation::LocationInformation()
{
	mageOfLocationInformation = NULL;
	mgeographicalInformation = NULL;
	mvlr_number = NULL;
	mlocationNumber = NULL;
	mcellGlobalIdOrServiceAreaIdOrLAI = NULL;
	mextensionContainer = NULL;
	mselectedLSA_Id = NULL;
	mmsc_Number = NULL;
	mgeodeticInformation = NULL;
	mcurrentLocationRetrieved = false;
	msai_Present = false;
	mlocationInformationEPS = NULL;
	muserCSGInformation = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0002, 0X0080, 0X0081, 0X0082, 0X00A3, 0X00A4, 0X0085, 0X0086, 0X0087, 0X0088, 0X0089, 0X00AA, 0X008B};
	mTagOptional = {true, true, true, true, true, true, true, true, true, true, true, true, true};
}

LocationInformation::~LocationInformation()
{
	if(mageOfLocationInformation != NULL)
		delete mageOfLocationInformation;
	if(mgeographicalInformation != NULL)
		delete mgeographicalInformation;
	if(mvlr_number != NULL)
		delete mvlr_number;
	if(mlocationNumber != NULL)
		delete mlocationNumber;
	if(mcellGlobalIdOrServiceAreaIdOrLAI != NULL)
		delete mcellGlobalIdOrServiceAreaIdOrLAI;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mselectedLSA_Id != NULL)
		delete mselectedLSA_Id;
	if(mmsc_Number != NULL)
		delete mmsc_Number;
	if(mgeodeticInformation != NULL)
		delete mgeodeticInformation;
	if(mlocationInformationEPS != NULL)
		delete mlocationInformationEPS;
	if(muserCSGInformation != NULL)
		delete muserCSGInformation;
}

capstd::INTEGER* LocationInformation::setageOfLocationInformation(){
	if(mageOfLocationInformation == NULL)
	{
		mageOfLocationInformation = new capstd::INTEGER(0, 32767);
		mTagsPresent |= LocationInformation_AGEOFLOCATIONINFORMATION;
		return mageOfLocationInformation;
	}
	else
		return mageOfLocationInformation;

}

bool LocationInformation::setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation){
	if(mageOfLocationInformation == NULL)
	{
		return -1;
	}
	else
	{
		mageOfLocationInformation = ageOfLocationInformation;
		return true;
	}

}

capstd::OctetString* LocationInformation::setgeographicalInformation(){
	if(mgeographicalInformation == NULL)
	{
		mgeographicalInformation = new capstd::OctetString(8, 8);
		mTagsPresent |= LocationInformation_GEOGRAPHICALINFORMATION;
		return mgeographicalInformation;
	}
	else
		return mgeographicalInformation;

}

bool LocationInformation::setgeographicalInformation(capstd::OctetString* geographicalInformation){
	if(mgeographicalInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeographicalInformation = geographicalInformation;
		return true;
	}

}

capstd::OctetString* LocationInformation::setvlr_number(){
	if(mvlr_number == NULL)
	{
		mvlr_number = new capstd::OctetString(1, 0);
		mTagsPresent |= LocationInformation_VLR_NUMBER;
		return mvlr_number;
	}
	else
		return mvlr_number;

}

bool LocationInformation::setvlr_number(capstd::OctetString* vlr_number){
	if(mvlr_number == NULL)
	{
		return -1;
	}
	else
	{
		mvlr_number = vlr_number;
		return true;
	}

}

capstd::OctetString* LocationInformation::setlocationNumber(){
	if(mlocationNumber == NULL)
	{
		mlocationNumber = new capstd::OctetString(2, 10);
		mTagsPresent |= LocationInformation_LOCATIONNUMBER;
		return mlocationNumber;
	}
	else
		return mlocationNumber;

}

bool LocationInformation::setlocationNumber(capstd::OctetString* locationNumber){
	if(mlocationNumber == NULL)
	{
		return -1;
	}
	else
	{
		mlocationNumber = locationNumber;
		return true;
	}

}

CellGlobalIdOrServiceAreaIdOrLAI* LocationInformation::setcellGlobalIdOrServiceAreaIdOrLAI(){
	if(mcellGlobalIdOrServiceAreaIdOrLAI == NULL)
	{
		mcellGlobalIdOrServiceAreaIdOrLAI = new CellGlobalIdOrServiceAreaIdOrLAI();
		mTagsPresent |= LocationInformation_CELLGLOBALIDORSERVICEAREAIDORLAI;
		return mcellGlobalIdOrServiceAreaIdOrLAI;
	}
	else
		return mcellGlobalIdOrServiceAreaIdOrLAI;

}

bool LocationInformation::setcellGlobalIdOrServiceAreaIdOrLAI(CellGlobalIdOrServiceAreaIdOrLAI* cellGlobalIdOrServiceAreaIdOrLAI){
	if(mcellGlobalIdOrServiceAreaIdOrLAI == NULL)
	{
		return -1;
	}
	else
	{
		mcellGlobalIdOrServiceAreaIdOrLAI = cellGlobalIdOrServiceAreaIdOrLAI;
		return true;
	}

}

ExtensionContainer* LocationInformation::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new ExtensionContainer();
		mTagsPresent |= LocationInformation_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool LocationInformation::setextensionContainer(ExtensionContainer* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

capstd::OctetString* LocationInformation::setselectedLSA_Id(){
	if(mselectedLSA_Id == NULL)
	{
		mselectedLSA_Id = new capstd::OctetString(3, 3);
		mTagsPresent |= LocationInformation_SELECTEDLSA_ID;
		return mselectedLSA_Id;
	}
	else
		return mselectedLSA_Id;

}

bool LocationInformation::setselectedLSA_Id(capstd::OctetString* selectedLSA_Id){
	if(mselectedLSA_Id == NULL)
	{
		return -1;
	}
	else
	{
		mselectedLSA_Id = selectedLSA_Id;
		return true;
	}

}

capstd::OctetString* LocationInformation::setmsc_Number(){
	if(mmsc_Number == NULL)
	{
		mmsc_Number = new capstd::OctetString(1, 0);
		mTagsPresent |= LocationInformation_MSC_NUMBER;
		return mmsc_Number;
	}
	else
		return mmsc_Number;

}

bool LocationInformation::setmsc_Number(capstd::OctetString* msc_Number){
	if(mmsc_Number == NULL)
	{
		return -1;
	}
	else
	{
		mmsc_Number = msc_Number;
		return true;
	}

}

capstd::OctetString* LocationInformation::setgeodeticInformation(){
	if(mgeodeticInformation == NULL)
	{
		mgeodeticInformation = new capstd::OctetString(10, 10);
		mTagsPresent |= LocationInformation_GEODETICINFORMATION;
		return mgeodeticInformation;
	}
	else
		return mgeodeticInformation;

}

bool LocationInformation::setgeodeticInformation(capstd::OctetString* geodeticInformation){
	if(mgeodeticInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeodeticInformation = geodeticInformation;
		return true;
	}

}

bool* LocationInformation::setcurrentLocationRetrieved(){
	mcurrentLocationRetrieved = true;
	mTagsPresent |= LocationInformation_CURRENTLOCATIONRETRIEVED;
	mNullcurrentLocationRetrieved = true;
	return &mNullcurrentLocationRetrieved;
}

bool LocationInformation::setcurrentLocationRetrieved(bool currentLocationRetrieved){
	mcurrentLocationRetrieved = currentLocationRetrieved;
	return true;
}

bool* LocationInformation::setsai_Present(){
	msai_Present = true;
	mTagsPresent |= LocationInformation_SAI_PRESENT;
	mNullsai_Present = true;
	return &mNullsai_Present;
}

bool LocationInformation::setsai_Present(bool sai_Present){
	msai_Present = sai_Present;
	return true;
}

LocationInformationEPS* LocationInformation::setlocationInformationEPS(){
	if(mlocationInformationEPS == NULL)
	{
		mlocationInformationEPS = new LocationInformationEPS();
		mTagsPresent |= LocationInformation_LOCATIONINFORMATIONEPS;
		return mlocationInformationEPS;
	}
	else
		return mlocationInformationEPS;

}

bool LocationInformation::setlocationInformationEPS(LocationInformationEPS* locationInformationEPS){
	if(mlocationInformationEPS == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformationEPS = locationInformationEPS;
		return true;
	}

}

capstd::OctetString* LocationInformation::setuserCSGInformation(){
	if(muserCSGInformation == NULL)
	{
		muserCSGInformation = new capstd::OctetString();
		mTagsPresent |= LocationInformation_USERCSGINFORMATION;
		return muserCSGInformation;
	}
	else
		return muserCSGInformation;

}

bool LocationInformation::setuserCSGInformation(capstd::OctetString* userCSGInformation){
	if(muserCSGInformation == NULL)
	{
		return -1;
	}
	else
	{
		muserCSGInformation = userCSGInformation;
		return true;
	}

}

capstd::INTEGER* LocationInformation::getageOfLocationInformation() {//throw(const char*)
	if(NULL == mageOfLocationInformation)
		throw("Object ageOfLocationInformation is NULL");
	else
		return mageOfLocationInformation;
}

capstd::OctetString* LocationInformation::getgeographicalInformation() {//throw(const char*)
	if(NULL == mgeographicalInformation)
		throw("Object geographicalInformation is NULL");
	else
		return mgeographicalInformation;
}

capstd::OctetString* LocationInformation::getvlr_number() {//throw(const char*)
	if(NULL == mvlr_number)
		throw("Object vlr_number is NULL");
	else
		return mvlr_number;
}

capstd::OctetString* LocationInformation::getlocationNumber() {//throw(const char*)
	if(NULL == mlocationNumber)
		throw("Object locationNumber is NULL");
	else
		return mlocationNumber;
}

CellGlobalIdOrServiceAreaIdOrLAI* LocationInformation::getcellGlobalIdOrServiceAreaIdOrLAI() {//throw(const char*)
	if(NULL == mcellGlobalIdOrServiceAreaIdOrLAI)
		throw("Object cellGlobalIdOrServiceAreaIdOrLAI is NULL");
	else
		return mcellGlobalIdOrServiceAreaIdOrLAI;
}

ExtensionContainer* LocationInformation::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

capstd::OctetString* LocationInformation::getselectedLSA_Id() {//throw(const char*)
	if(NULL == mselectedLSA_Id)
		throw("Object selectedLSA_Id is NULL");
	else
		return mselectedLSA_Id;
}

capstd::OctetString* LocationInformation::getmsc_Number() {//throw(const char*)
	if(NULL == mmsc_Number)
		throw("Object msc_Number is NULL");
	else
		return mmsc_Number;
}

capstd::OctetString* LocationInformation::getgeodeticInformation() {//throw(const char*)
	if(NULL == mgeodeticInformation)
		throw("Object geodeticInformation is NULL");
	else
		return mgeodeticInformation;
}

bool LocationInformation::getcurrentLocationRetrieved() {
	return mcurrentLocationRetrieved;
}

bool LocationInformation::getsai_Present() {
	return msai_Present;
}

LocationInformationEPS* LocationInformation::getlocationInformationEPS() {//throw(const char*)
	if(NULL == mlocationInformationEPS)
		throw("Object locationInformationEPS is NULL");
	else
		return mlocationInformationEPS;
}

capstd::OctetString* LocationInformation::getuserCSGInformation() {//throw(const char*)
	if(NULL == muserCSGInformation)
		throw("Object userCSGInformation is NULL");
	else
		return muserCSGInformation;
}

bool LocationInformation::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int LocationInformation::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X0002:
				if(NULL == this->setageOfLocationInformation())
					return -1;
				if(mageOfLocationInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0080:
				if(NULL == this->setgeographicalInformation())
					return -1;
				if(mgeographicalInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setvlr_number())
					return -1;
				if(mvlr_number->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setlocationNumber())
					return -1;
				if(mlocationNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setcellGlobalIdOrServiceAreaIdOrLAI())
					return -1;
				if(mcellGlobalIdOrServiceAreaIdOrLAI->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setselectedLSA_Id())
					return -1;
				if(mselectedLSA_Id->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setmsc_Number())
					return -1;
				if(mmsc_Number->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setgeodeticInformation())
					return -1;
				if(mgeodeticInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->setcurrentLocationRetrieved())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setsai_Present())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AA:
				if(NULL == this->setlocationInformationEPS())
					return -1;
				if(mlocationInformationEPS->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008B:
				if(NULL == this->setuserCSGInformation())
					return -1;
				if(muserCSGInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: LocationInformation Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("LocationInformation: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int LocationInformation::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("LocationInformation: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case LocationInformation_AGEOFLOCATIONINFORMATION:
				if(asn1_tag_encode(2, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mageOfLocationInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_GEOGRAPHICALINFORMATION:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeographicalInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_VLR_NUMBER:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mvlr_number->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_LOCATIONNUMBER:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_CELLGLOBALIDORSERVICEAREAIDORLAI:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcellGlobalIdOrServiceAreaIdOrLAI->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_EXTENSIONCONTAINER:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_SELECTEDLSA_ID:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mselectedLSA_Id->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_MSC_NUMBER:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmsc_Number->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_GEODETICINFORMATION:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeodeticInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_CURRENTLOCATIONRETRIEVED:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case LocationInformation_SAI_PRESENT:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case LocationInformation_LOCATIONINFORMATIONEPS:
				if(asn1_tag_encode(170, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformationEPS->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformation_USERCSGINFORMATION:
				if(asn1_tag_encode(139, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((muserCSGInformation->Encode(array) < 0) || 
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

	return 0;
}

int LocationInformation::Display(int tab){
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
			case LocationInformation_AGEOFLOCATIONINFORMATION:
			{
				printf(temp, " ", "ageOfLocationInformation");
				if(mageOfLocationInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_GEOGRAPHICALINFORMATION:
			{
				printf(temp, " ", "geographicalInformation");
				if(mgeographicalInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_VLR_NUMBER:
			{
				printf(temp, " ", "vlr_number");
				if(mvlr_number->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_LOCATIONNUMBER:
			{
				printf(temp, " ", "locationNumber");
				if(mlocationNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_CELLGLOBALIDORSERVICEAREAIDORLAI:
			{
				printf(temp, " ", "cellGlobalIdOrServiceAreaIdOrLAI");
				if(mcellGlobalIdOrServiceAreaIdOrLAI->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_SELECTEDLSA_ID:
			{
				printf(temp, " ", "selectedLSA_Id");
				if(mselectedLSA_Id->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_MSC_NUMBER:
			{
				printf(temp, " ", "msc_Number");
				if(mmsc_Number->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_GEODETICINFORMATION:
			{
				printf(temp, " ", "geodeticInformation");
				if(mgeodeticInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_CURRENTLOCATIONRETRIEVED:
			{
				printf(temp, " ", "currentLocationRetrieved");
				break;
			}
			case LocationInformation_SAI_PRESENT:
			{
				printf(temp, " ", "sai_Present");
				break;
			}
			case LocationInformation_LOCATIONINFORMATIONEPS:
			{
				printf(temp, " ", "locationInformationEPS");
				if(mlocationInformationEPS->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformation_USERCSGINFORMATION:
			{
				printf(temp, " ", "userCSGInformation");
				if(muserCSGInformation->Display(tab+1) < 0)
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

bool LocationInformation::ValidateMandatory(char *errStr){

	return true;
}
LocationInformationEPS::LocationInformationEPS()
{
	me_utranCellGlobalIdentity = NULL;
	mtrackingAreaIdentity = NULL;
	mextensionContainer = NULL;
	mgeographicalInformation = NULL;
	mgeodeticInformation = NULL;
	mcurrentLocationRetrieved = false;
	mageOfLocationInformation = NULL;
	mmme_Name = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X00A2, 0X0083, 0X0084, 0X0085, 0X0086, 0X0087};
	mTagOptional = {true, true, true, true, true, true, true, true};
}

LocationInformationEPS::~LocationInformationEPS()
{
	if(me_utranCellGlobalIdentity != NULL)
		delete me_utranCellGlobalIdentity;
	if(mtrackingAreaIdentity != NULL)
		delete mtrackingAreaIdentity;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mgeographicalInformation != NULL)
		delete mgeographicalInformation;
	if(mgeodeticInformation != NULL)
		delete mgeodeticInformation;
	if(mageOfLocationInformation != NULL)
		delete mageOfLocationInformation;
	if(mmme_Name != NULL)
		delete mmme_Name;
}

capstd::OctetString* LocationInformationEPS::sete_utranCellGlobalIdentity(){
	if(me_utranCellGlobalIdentity == NULL)
	{
		me_utranCellGlobalIdentity = new capstd::OctetString(7, 7);
		mTagsPresent |= LocationInformationEPS_E_UTRANCELLGLOBALIDENTITY;
		return me_utranCellGlobalIdentity;
	}
	else
		return me_utranCellGlobalIdentity;

}

bool LocationInformationEPS::sete_utranCellGlobalIdentity(capstd::OctetString* e_utranCellGlobalIdentity){
	if(me_utranCellGlobalIdentity == NULL)
	{
		return -1;
	}
	else
	{
		me_utranCellGlobalIdentity = e_utranCellGlobalIdentity;
		return true;
	}

}

capstd::OctetString* LocationInformationEPS::settrackingAreaIdentity(){
	if(mtrackingAreaIdentity == NULL)
	{
		mtrackingAreaIdentity = new capstd::OctetString(5, 5);
		mTagsPresent |= LocationInformationEPS_TRACKINGAREAIDENTITY;
		return mtrackingAreaIdentity;
	}
	else
		return mtrackingAreaIdentity;

}

bool LocationInformationEPS::settrackingAreaIdentity(capstd::OctetString* trackingAreaIdentity){
	if(mtrackingAreaIdentity == NULL)
	{
		return -1;
	}
	else
	{
		mtrackingAreaIdentity = trackingAreaIdentity;
		return true;
	}

}

ExtensionContainer* LocationInformationEPS::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new ExtensionContainer();
		mTagsPresent |= LocationInformationEPS_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool LocationInformationEPS::setextensionContainer(ExtensionContainer* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

capstd::OctetString* LocationInformationEPS::setgeographicalInformation(){
	if(mgeographicalInformation == NULL)
	{
		mgeographicalInformation = new capstd::OctetString(8, 8);
		mTagsPresent |= LocationInformationEPS_GEOGRAPHICALINFORMATION;
		return mgeographicalInformation;
	}
	else
		return mgeographicalInformation;

}

bool LocationInformationEPS::setgeographicalInformation(capstd::OctetString* geographicalInformation){
	if(mgeographicalInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeographicalInformation = geographicalInformation;
		return true;
	}

}

capstd::OctetString* LocationInformationEPS::setgeodeticInformation(){
	if(mgeodeticInformation == NULL)
	{
		mgeodeticInformation = new capstd::OctetString(10, 10);
		mTagsPresent |= LocationInformationEPS_GEODETICINFORMATION;
		return mgeodeticInformation;
	}
	else
		return mgeodeticInformation;

}

bool LocationInformationEPS::setgeodeticInformation(capstd::OctetString* geodeticInformation){
	if(mgeodeticInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeodeticInformation = geodeticInformation;
		return true;
	}

}

bool* LocationInformationEPS::setcurrentLocationRetrieved(){
	mcurrentLocationRetrieved = true;
	mTagsPresent |= LocationInformationEPS_CURRENTLOCATIONRETRIEVED;
	mNullcurrentLocationRetrieved = true;
	return &mNullcurrentLocationRetrieved;
}

bool LocationInformationEPS::setcurrentLocationRetrieved(bool currentLocationRetrieved){
	mcurrentLocationRetrieved = currentLocationRetrieved;
	return true;
}

capstd::INTEGER* LocationInformationEPS::setageOfLocationInformation(){
	if(mageOfLocationInformation == NULL)
	{
		mageOfLocationInformation = new capstd::INTEGER(0, 32767);
		mTagsPresent |= LocationInformationEPS_AGEOFLOCATIONINFORMATION;
		return mageOfLocationInformation;
	}
	else
		return mageOfLocationInformation;

}

bool LocationInformationEPS::setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation){
	if(mageOfLocationInformation == NULL)
	{
		return -1;
	}
	else
	{
		mageOfLocationInformation = ageOfLocationInformation;
		return true;
	}

}

capstd::OctetString* LocationInformationEPS::setmme_Name(){
	if(mmme_Name == NULL)
	{
		mmme_Name = new capstd::OctetString(9, 55);
		mTagsPresent |= LocationInformationEPS_MME_NAME;
		return mmme_Name;
	}
	else
		return mmme_Name;

}

bool LocationInformationEPS::setmme_Name(capstd::OctetString* mme_Name){
	if(mmme_Name == NULL)
	{
		return -1;
	}
	else
	{
		mmme_Name = mme_Name;
		return true;
	}

}

capstd::OctetString* LocationInformationEPS::gete_utranCellGlobalIdentity() {//throw(const char*)
	if(NULL == me_utranCellGlobalIdentity)
		throw("Object e_utranCellGlobalIdentity is NULL");
	else
		return me_utranCellGlobalIdentity;
}

capstd::OctetString* LocationInformationEPS::gettrackingAreaIdentity() {//throw(const char*)
	if(NULL == mtrackingAreaIdentity)
		throw("Object trackingAreaIdentity is NULL");
	else
		return mtrackingAreaIdentity;
}

ExtensionContainer* LocationInformationEPS::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

capstd::OctetString* LocationInformationEPS::getgeographicalInformation() {//throw(const char*)
	if(NULL == mgeographicalInformation)
		throw("Object geographicalInformation is NULL");
	else
		return mgeographicalInformation;
}

capstd::OctetString* LocationInformationEPS::getgeodeticInformation() {//throw(const char*)
	if(NULL == mgeodeticInformation)
		throw("Object geodeticInformation is NULL");
	else
		return mgeodeticInformation;
}

bool LocationInformationEPS::getcurrentLocationRetrieved() {
	return mcurrentLocationRetrieved;
}

capstd::INTEGER* LocationInformationEPS::getageOfLocationInformation() {//throw(const char*)
	if(NULL == mageOfLocationInformation)
		throw("Object ageOfLocationInformation is NULL");
	else
		return mageOfLocationInformation;
}

capstd::OctetString* LocationInformationEPS::getmme_Name() {//throw(const char*)
	if(NULL == mmme_Name)
		throw("Object mme_Name is NULL");
	else
		return mmme_Name;
}

bool LocationInformationEPS::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int LocationInformationEPS::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->sete_utranCellGlobalIdentity())
					return -1;
				if(me_utranCellGlobalIdentity->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->settrackingAreaIdentity())
					return -1;
				if(mtrackingAreaIdentity->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setgeographicalInformation())
					return -1;
				if(mgeographicalInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setgeodeticInformation())
					return -1;
				if(mgeodeticInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setcurrentLocationRetrieved())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setageOfLocationInformation())
					return -1;
				if(mageOfLocationInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setmme_Name())
					return -1;
				if(mmme_Name->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: LocationInformationEPS Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("LocationInformationEPS: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int LocationInformationEPS::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("LocationInformationEPS: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case LocationInformationEPS_E_UTRANCELLGLOBALIDENTITY:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((me_utranCellGlobalIdentity->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_TRACKINGAREAIDENTITY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtrackingAreaIdentity->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_EXTENSIONCONTAINER:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_GEOGRAPHICALINFORMATION:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeographicalInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_GEODETICINFORMATION:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeodeticInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_CURRENTLOCATIONRETRIEVED:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case LocationInformationEPS_AGEOFLOCATIONINFORMATION:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mageOfLocationInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationEPS_MME_NAME:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmme_Name->Encode(array) < 0) || 
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

	return 0;
}

int LocationInformationEPS::Display(int tab){
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
			case LocationInformationEPS_E_UTRANCELLGLOBALIDENTITY:
			{
				printf(temp, " ", "e_utranCellGlobalIdentity");
				if(me_utranCellGlobalIdentity->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_TRACKINGAREAIDENTITY:
			{
				printf(temp, " ", "trackingAreaIdentity");
				if(mtrackingAreaIdentity->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_GEOGRAPHICALINFORMATION:
			{
				printf(temp, " ", "geographicalInformation");
				if(mgeographicalInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_GEODETICINFORMATION:
			{
				printf(temp, " ", "geodeticInformation");
				if(mgeodeticInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_CURRENTLOCATIONRETRIEVED:
			{
				printf(temp, " ", "currentLocationRetrieved");
				break;
			}
			case LocationInformationEPS_AGEOFLOCATIONINFORMATION:
			{
				printf(temp, " ", "ageOfLocationInformation");
				if(mageOfLocationInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationEPS_MME_NAME:
			{
				printf(temp, " ", "mme_Name");
				if(mmme_Name->Display(tab+1) < 0)
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

bool LocationInformationEPS::ValidateMandatory(char *errStr){

	return true;
}
LocationInformationGPRS::LocationInformationGPRS()
{
	mcellGlobalIdOrServiceAreaIdOrLAI = NULL;
	mrouteingAreaIdentity = NULL;
	mgeographicalInformation = NULL;
	msgsn_Number = NULL;
	mselectedLSAIdentity = NULL;
	mextensionContainer = NULL;
	msai_Present = false;
	mgeodeticInformation = NULL;
	mcurrentLocationRetrieved = false;
	mageOfLocationInformation = NULL;
	muserCSGInformation = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081, 0X0082, 0X0083, 0X0084, 0X00A5, 0X0086, 0X0087, 0X0088, 0X0089, 0X008A};
	mTagOptional = {true, true, true, true, true, true, true, true, true, true, true};
}

LocationInformationGPRS::~LocationInformationGPRS()
{
	if(mcellGlobalIdOrServiceAreaIdOrLAI != NULL)
		delete mcellGlobalIdOrServiceAreaIdOrLAI;
	if(mrouteingAreaIdentity != NULL)
		delete mrouteingAreaIdentity;
	if(mgeographicalInformation != NULL)
		delete mgeographicalInformation;
	if(msgsn_Number != NULL)
		delete msgsn_Number;
	if(mselectedLSAIdentity != NULL)
		delete mselectedLSAIdentity;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mgeodeticInformation != NULL)
		delete mgeodeticInformation;
	if(mageOfLocationInformation != NULL)
		delete mageOfLocationInformation;
	if(muserCSGInformation != NULL)
		delete muserCSGInformation;
}

CellGlobalIdOrServiceAreaIdOrLAI* LocationInformationGPRS::setcellGlobalIdOrServiceAreaIdOrLAI(){
	if(mcellGlobalIdOrServiceAreaIdOrLAI == NULL)
	{
		mcellGlobalIdOrServiceAreaIdOrLAI = new CellGlobalIdOrServiceAreaIdOrLAI();
		mTagsPresent |= LocationInformationGPRS_CELLGLOBALIDORSERVICEAREAIDORLAI;
		return mcellGlobalIdOrServiceAreaIdOrLAI;
	}
	else
		return mcellGlobalIdOrServiceAreaIdOrLAI;

}

bool LocationInformationGPRS::setcellGlobalIdOrServiceAreaIdOrLAI(CellGlobalIdOrServiceAreaIdOrLAI* cellGlobalIdOrServiceAreaIdOrLAI){
	if(mcellGlobalIdOrServiceAreaIdOrLAI == NULL)
	{
		return -1;
	}
	else
	{
		mcellGlobalIdOrServiceAreaIdOrLAI = cellGlobalIdOrServiceAreaIdOrLAI;
		return true;
	}

}

capstd::OctetString* LocationInformationGPRS::setrouteingAreaIdentity(){
	if(mrouteingAreaIdentity == NULL)
	{
		mrouteingAreaIdentity = new capstd::OctetString(6, 6);
		mTagsPresent |= LocationInformationGPRS_ROUTEINGAREAIDENTITY;
		return mrouteingAreaIdentity;
	}
	else
		return mrouteingAreaIdentity;

}

bool LocationInformationGPRS::setrouteingAreaIdentity(capstd::OctetString* routeingAreaIdentity){
	if(mrouteingAreaIdentity == NULL)
	{
		return -1;
	}
	else
	{
		mrouteingAreaIdentity = routeingAreaIdentity;
		return true;
	}

}

capstd::OctetString* LocationInformationGPRS::setgeographicalInformation(){
	if(mgeographicalInformation == NULL)
	{
		mgeographicalInformation = new capstd::OctetString(8, 8);
		mTagsPresent |= LocationInformationGPRS_GEOGRAPHICALINFORMATION;
		return mgeographicalInformation;
	}
	else
		return mgeographicalInformation;

}

bool LocationInformationGPRS::setgeographicalInformation(capstd::OctetString* geographicalInformation){
	if(mgeographicalInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeographicalInformation = geographicalInformation;
		return true;
	}

}

capstd::OctetString* LocationInformationGPRS::setsgsn_Number(){
	if(msgsn_Number == NULL)
	{
		msgsn_Number = new capstd::OctetString(1, 0);
		mTagsPresent |= LocationInformationGPRS_SGSN_NUMBER;
		return msgsn_Number;
	}
	else
		return msgsn_Number;

}

bool LocationInformationGPRS::setsgsn_Number(capstd::OctetString* sgsn_Number){
	if(msgsn_Number == NULL)
	{
		return -1;
	}
	else
	{
		msgsn_Number = sgsn_Number;
		return true;
	}

}

capstd::OctetString* LocationInformationGPRS::setselectedLSAIdentity(){
	if(mselectedLSAIdentity == NULL)
	{
		mselectedLSAIdentity = new capstd::OctetString(3, 3);
		mTagsPresent |= LocationInformationGPRS_SELECTEDLSAIDENTITY;
		return mselectedLSAIdentity;
	}
	else
		return mselectedLSAIdentity;

}

bool LocationInformationGPRS::setselectedLSAIdentity(capstd::OctetString* selectedLSAIdentity){
	if(mselectedLSAIdentity == NULL)
	{
		return -1;
	}
	else
	{
		mselectedLSAIdentity = selectedLSAIdentity;
		return true;
	}

}

capstd::GENERIC* LocationInformationGPRS::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= LocationInformationGPRS_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool LocationInformationGPRS::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

bool* LocationInformationGPRS::setsai_Present(){
	msai_Present = true;
	mTagsPresent |= LocationInformationGPRS_SAI_PRESENT;
	mNullsai_Present = true;
	return &mNullsai_Present;
}

bool LocationInformationGPRS::setsai_Present(bool sai_Present){
	msai_Present = sai_Present;
	return true;
}

capstd::OctetString* LocationInformationGPRS::setgeodeticInformation(){
	if(mgeodeticInformation == NULL)
	{
		mgeodeticInformation = new capstd::OctetString(10, 10);
		mTagsPresent |= LocationInformationGPRS_GEODETICINFORMATION;
		return mgeodeticInformation;
	}
	else
		return mgeodeticInformation;

}

bool LocationInformationGPRS::setgeodeticInformation(capstd::OctetString* geodeticInformation){
	if(mgeodeticInformation == NULL)
	{
		return -1;
	}
	else
	{
		mgeodeticInformation = geodeticInformation;
		return true;
	}

}

bool* LocationInformationGPRS::setcurrentLocationRetrieved(){
	mcurrentLocationRetrieved = true;
	mTagsPresent |= LocationInformationGPRS_CURRENTLOCATIONRETRIEVED;
	mNullcurrentLocationRetrieved = true;
	return &mNullcurrentLocationRetrieved;
}

bool LocationInformationGPRS::setcurrentLocationRetrieved(bool currentLocationRetrieved){
	mcurrentLocationRetrieved = currentLocationRetrieved;
	return true;
}

capstd::INTEGER* LocationInformationGPRS::setageOfLocationInformation(){
	if(mageOfLocationInformation == NULL)
	{
		mageOfLocationInformation = new capstd::INTEGER(0, 32767);
		mTagsPresent |= LocationInformationGPRS_AGEOFLOCATIONINFORMATION;
		return mageOfLocationInformation;
	}
	else
		return mageOfLocationInformation;

}

bool LocationInformationGPRS::setageOfLocationInformation(capstd::INTEGER* ageOfLocationInformation){
	if(mageOfLocationInformation == NULL)
	{
		return -1;
	}
	else
	{
		mageOfLocationInformation = ageOfLocationInformation;
		return true;
	}

}

capstd::OctetString* LocationInformationGPRS::setuserCSGInformation(){
	if(muserCSGInformation == NULL)
	{
		muserCSGInformation = new capstd::OctetString();
		mTagsPresent |= LocationInformationGPRS_USERCSGINFORMATION;
		return muserCSGInformation;
	}
	else
		return muserCSGInformation;

}

bool LocationInformationGPRS::setuserCSGInformation(capstd::OctetString* userCSGInformation){
	if(muserCSGInformation == NULL)
	{
		return -1;
	}
	else
	{
		muserCSGInformation = userCSGInformation;
		return true;
	}

}

CellGlobalIdOrServiceAreaIdOrLAI* LocationInformationGPRS::getcellGlobalIdOrServiceAreaIdOrLAI() {//throw(const char*)
	if(NULL == mcellGlobalIdOrServiceAreaIdOrLAI)
		throw("Object cellGlobalIdOrServiceAreaIdOrLAI is NULL");
	else
		return mcellGlobalIdOrServiceAreaIdOrLAI;
}

capstd::OctetString* LocationInformationGPRS::getrouteingAreaIdentity() {//throw(const char*)
	if(NULL == mrouteingAreaIdentity)
		throw("Object routeingAreaIdentity is NULL");
	else
		return mrouteingAreaIdentity;
}

capstd::OctetString* LocationInformationGPRS::getgeographicalInformation() {//throw(const char*)
	if(NULL == mgeographicalInformation)
		throw("Object geographicalInformation is NULL");
	else
		return mgeographicalInformation;
}

capstd::OctetString* LocationInformationGPRS::getsgsn_Number() {//throw(const char*)
	if(NULL == msgsn_Number)
		throw("Object sgsn_Number is NULL");
	else
		return msgsn_Number;
}

capstd::OctetString* LocationInformationGPRS::getselectedLSAIdentity() {//throw(const char*)
	if(NULL == mselectedLSAIdentity)
		throw("Object selectedLSAIdentity is NULL");
	else
		return mselectedLSAIdentity;
}

capstd::GENERIC* LocationInformationGPRS::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

bool LocationInformationGPRS::getsai_Present() {
	return msai_Present;
}

capstd::OctetString* LocationInformationGPRS::getgeodeticInformation() {//throw(const char*)
	if(NULL == mgeodeticInformation)
		throw("Object geodeticInformation is NULL");
	else
		return mgeodeticInformation;
}

bool LocationInformationGPRS::getcurrentLocationRetrieved() {
	return mcurrentLocationRetrieved;
}

capstd::INTEGER* LocationInformationGPRS::getageOfLocationInformation() {//throw(const char*)
	if(NULL == mageOfLocationInformation)
		throw("Object ageOfLocationInformation is NULL");
	else
		return mageOfLocationInformation;
}

capstd::OctetString* LocationInformationGPRS::getuserCSGInformation() {//throw(const char*)
	if(NULL == muserCSGInformation)
		throw("Object userCSGInformation is NULL");
	else
		return muserCSGInformation;
}

bool LocationInformationGPRS::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int LocationInformationGPRS::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setcellGlobalIdOrServiceAreaIdOrLAI())
					return -1;
				if(mcellGlobalIdOrServiceAreaIdOrLAI->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setrouteingAreaIdentity())
					return -1;
				if(mrouteingAreaIdentity->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setgeographicalInformation())
					return -1;
				if(mgeographicalInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setsgsn_Number())
					return -1;
				if(msgsn_Number->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setselectedLSAIdentity())
					return -1;
				if(mselectedLSAIdentity->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A5:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, LocationInformationGPRS_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setsai_Present())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setgeodeticInformation())
					return -1;
				if(mgeodeticInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->setcurrentLocationRetrieved())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setageOfLocationInformation())
					return -1;
				if(mageOfLocationInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setuserCSGInformation())
					return -1;
				if(muserCSGInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: LocationInformationGPRS Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("LocationInformationGPRS: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int LocationInformationGPRS::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("LocationInformationGPRS: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case LocationInformationGPRS_CELLGLOBALIDORSERVICEAREAIDORLAI:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcellGlobalIdOrServiceAreaIdOrLAI->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_ROUTEINGAREAIDENTITY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrouteingAreaIdentity->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_GEOGRAPHICALINFORMATION:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeographicalInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_SGSN_NUMBER:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msgsn_Number->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_SELECTEDLSAIDENTITY:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mselectedLSAIdentity->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_EXTENSIONCONTAINER:
				if(asn1_tag_encode(165, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_SAI_PRESENT:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case LocationInformationGPRS_GEODETICINFORMATION:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgeodeticInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_CURRENTLOCATIONRETRIEVED:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case LocationInformationGPRS_AGEOFLOCATIONINFORMATION:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mageOfLocationInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case LocationInformationGPRS_USERCSGINFORMATION:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((muserCSGInformation->Encode(array) < 0) || 
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

	return 0;
}

int LocationInformationGPRS::Display(int tab){
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
			case LocationInformationGPRS_CELLGLOBALIDORSERVICEAREAIDORLAI:
			{
				printf(temp, " ", "cellGlobalIdOrServiceAreaIdOrLAI");
				if(mcellGlobalIdOrServiceAreaIdOrLAI->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_ROUTEINGAREAIDENTITY:
			{
				printf(temp, " ", "routeingAreaIdentity");
				if(mrouteingAreaIdentity->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_GEOGRAPHICALINFORMATION:
			{
				printf(temp, " ", "geographicalInformation");
				if(mgeographicalInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_SGSN_NUMBER:
			{
				printf(temp, " ", "sgsn_Number");
				if(msgsn_Number->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_SELECTEDLSAIDENTITY:
			{
				printf(temp, " ", "selectedLSAIdentity");
				if(mselectedLSAIdentity->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_SAI_PRESENT:
			{
				printf(temp, " ", "sai_Present");
				break;
			}
			case LocationInformationGPRS_GEODETICINFORMATION:
			{
				printf(temp, " ", "geodeticInformation");
				if(mgeodeticInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_CURRENTLOCATIONRETRIEVED:
			{
				printf(temp, " ", "currentLocationRetrieved");
				break;
			}
			case LocationInformationGPRS_AGEOFLOCATIONINFORMATION:
			{
				printf(temp, " ", "ageOfLocationInformation");
				if(mageOfLocationInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case LocationInformationGPRS_USERCSGINFORMATION:
			{
				printf(temp, " ", "userCSGInformation");
				if(muserCSGInformation->Display(tab+1) < 0)
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

bool LocationInformationGPRS::ValidateMandatory(char *errStr){

	return true;
}
MNPInfoRes::MNPInfoRes()
{
	mrouteingNumber = NULL;
	mimsi = NULL;
	mmsisdn = NULL;
	mnumberPortabilityStatus = NULL;
	mextensionContainer = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X00A4};
	mTagOptional = {true, true, true, true, true};
}

MNPInfoRes::~MNPInfoRes()
{
	if(mrouteingNumber != NULL)
		delete mrouteingNumber;
	if(mimsi != NULL)
		delete mimsi;
	if(mmsisdn != NULL)
		delete mmsisdn;
	if(mnumberPortabilityStatus != NULL)
		delete mnumberPortabilityStatus;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
}

capstd::OctetString* MNPInfoRes::setrouteingNumber(){
	if(mrouteingNumber == NULL)
	{
		mrouteingNumber = new capstd::OctetString();
		mTagsPresent |= MNPInfoRes_ROUTEINGNUMBER;
		return mrouteingNumber;
	}
	else
		return mrouteingNumber;

}

bool MNPInfoRes::setrouteingNumber(capstd::OctetString* routeingNumber){
	if(mrouteingNumber == NULL)
	{
		return -1;
	}
	else
	{
		mrouteingNumber = routeingNumber;
		return true;
	}

}

capstd::IMSI* MNPInfoRes::setimsi(){
	if(mimsi == NULL)
	{
		mimsi = new capstd::IMSI();
		mTagsPresent |= MNPInfoRes_IMSI;
		return mimsi;
	}
	else
		return mimsi;

}

bool MNPInfoRes::setimsi(capstd::IMSI* imsi){
	if(mimsi == NULL)
	{
		return -1;
	}
	else
	{
		mimsi = imsi;
		return true;
	}

}

capstd::OctetString* MNPInfoRes::setmsisdn(){
	if(mmsisdn == NULL)
	{
		mmsisdn = new capstd::OctetString(1, 0);
		mTagsPresent |= MNPInfoRes_MSISDN;
		return mmsisdn;
	}
	else
		return mmsisdn;

}

bool MNPInfoRes::setmsisdn(capstd::OctetString* msisdn){
	if(mmsisdn == NULL)
	{
		return -1;
	}
	else
	{
		mmsisdn = msisdn;
		return true;
	}

}

NumberPortabilityStatus* MNPInfoRes::setnumberPortabilityStatus(){
	if(mnumberPortabilityStatus == NULL)
	{
		mnumberPortabilityStatus = new NumberPortabilityStatus();
		mTagsPresent |= MNPInfoRes_NUMBERPORTABILITYSTATUS;
		return mnumberPortabilityStatus;
	}
	else
		return mnumberPortabilityStatus;

}

bool MNPInfoRes::setnumberPortabilityStatus(NumberPortabilityStatus* numberPortabilityStatus){
	if(mnumberPortabilityStatus == NULL)
	{
		return -1;
	}
	else
	{
		mnumberPortabilityStatus = numberPortabilityStatus;
		return true;
	}

}

capstd::GENERIC* MNPInfoRes::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= MNPInfoRes_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool MNPInfoRes::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

capstd::OctetString* MNPInfoRes::getrouteingNumber() {//throw(const char*)
	if(NULL == mrouteingNumber)
		throw("Object routeingNumber is NULL");
	else
		return mrouteingNumber;
}

capstd::IMSI* MNPInfoRes::getimsi() {//throw(const char*)
	if(NULL == mimsi)
		throw("Object imsi is NULL");
	else
		return mimsi;
}

capstd::OctetString* MNPInfoRes::getmsisdn() {//throw(const char*)
	if(NULL == mmsisdn)
		throw("Object msisdn is NULL");
	else
		return mmsisdn;
}

NumberPortabilityStatus* MNPInfoRes::getnumberPortabilityStatus() {//throw(const char*)
	if(NULL == mnumberPortabilityStatus)
		throw("Object numberPortabilityStatus is NULL");
	else
		return mnumberPortabilityStatus;
}

capstd::GENERIC* MNPInfoRes::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

bool MNPInfoRes::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int MNPInfoRes::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setrouteingNumber())
					return -1;
				if(mrouteingNumber->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setimsi())
					return -1;
				if(mimsi->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setmsisdn())
					return -1;
				if(mmsisdn->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setnumberPortabilityStatus())
					return -1;
				if(mnumberPortabilityStatus->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, MNPInfoRes_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: MNPInfoRes Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("MNPInfoRes: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int MNPInfoRes::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("MNPInfoRes: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case MNPInfoRes_ROUTEINGNUMBER:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrouteingNumber->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case MNPInfoRes_IMSI:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mimsi->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case MNPInfoRes_MSISDN:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmsisdn->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case MNPInfoRes_NUMBERPORTABILITYSTATUS:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnumberPortabilityStatus->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case MNPInfoRes_EXTENSIONCONTAINER:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
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

	return 0;
}

int MNPInfoRes::Display(int tab){
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
			case MNPInfoRes_ROUTEINGNUMBER:
			{
				printf(temp, " ", "routeingNumber");
				if(mrouteingNumber->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MNPInfoRes_IMSI:
			{
				printf(temp, " ", "imsi");
				if(mimsi->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MNPInfoRes_MSISDN:
			{
				printf(temp, " ", "msisdn");
				if(mmsisdn->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MNPInfoRes_NUMBERPORTABILITYSTATUS:
			{
				printf(temp, " ", "numberPortabilityStatus");
				if(mnumberPortabilityStatus->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MNPInfoRes_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
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

bool MNPInfoRes::ValidateMandatory(char *errStr){

	return true;
}
MessageID::MessageID()
{
	melementaryMessageID = NULL;
	mtext = NULL;
	mvariableMessage = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X00A1, 0X00BE};
}

MessageID::~MessageID()
{
	if(melementaryMessageID != NULL)
		delete melementaryMessageID;
	if(mtext != NULL)
		delete mtext;
	if(mvariableMessage != NULL)
		delete mvariableMessage;
}

capstd::INTEGER* MessageID::setelementaryMessageID(){
if(mParamSet == true)
	{
		if(melementaryMessageID != NULL)
			return melementaryMessageID;
		else
			return NULL;
	}
	if(melementaryMessageID == NULL)
	{
		melementaryMessageID = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= MessageID_ELEMENTARYMESSAGEID;
		mParamSet = true;
		return melementaryMessageID;
	}
}

bool MessageID::setelementaryMessageID(capstd::INTEGER* elementaryMessageID){
	if(melementaryMessageID == NULL)
	{
		return -1;
	}
	else
	{
		melementaryMessageID = elementaryMessageID;
		return true;
	}

}

Text* MessageID::settext(){
if(mParamSet == true)
	{
		if(mtext != NULL)
			return mtext;
		else
			return NULL;
	}
	if(mtext == NULL)
	{
		mtext = new Text();
		mTagsPresent |= MessageID_TEXT;
		mParamSet = true;
		return mtext;
	}
}

bool MessageID::settext(Text* text){
	if(mtext == NULL)
	{
		return -1;
	}
	else
	{
		mtext = text;
		return true;
	}

}

VariableMessage* MessageID::setvariableMessage(){
if(mParamSet == true)
	{
		if(mvariableMessage != NULL)
			return mvariableMessage;
		else
			return NULL;
	}
	if(mvariableMessage == NULL)
	{
		mvariableMessage = new VariableMessage();
		mTagsPresent |= MessageID_VARIABLEMESSAGE;
		mParamSet = true;
		return mvariableMessage;
	}
}

bool MessageID::setvariableMessage(VariableMessage* variableMessage){
	if(mvariableMessage == NULL)
	{
		return -1;
	}
	else
	{
		mvariableMessage = variableMessage;
		return true;
	}

}

capstd::INTEGER* MessageID::getelementaryMessageID() {//throw(const char*)
	if(NULL == melementaryMessageID)
		throw("Object elementaryMessageID is NULL");
	else
		return melementaryMessageID;
}

Text* MessageID::gettext() {//throw(const char*)
	if(NULL == mtext)
		throw("Object text is NULL");
	else
		return mtext;
}

VariableMessage* MessageID::getvariableMessage() {//throw(const char*)
	if(NULL == mvariableMessage)
		throw("Object variableMessage is NULL");
	else
		return mvariableMessage;
}

bool MessageID::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int MessageID::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setelementaryMessageID())
					return -1;
				if(melementaryMessageID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->settext())
					return -1;
				if(mtext->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00BE:
				if(NULL == this->setvariableMessage())
					return -1;
				if(mvariableMessage->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: MessageID Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("MessageID: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int MessageID::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("MessageID: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case MessageID_ELEMENTARYMESSAGEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((melementaryMessageID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case MessageID_TEXT:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtext->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case MessageID_VARIABLEMESSAGE:
				if(asn1_tag_encode(190, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mvariableMessage->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int MessageID::Display(int tab){
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
			case MessageID_ELEMENTARYMESSAGEID:
			{
				printf(temp, " ", "elementaryMessageID");
				if(melementaryMessageID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MessageID_TEXT:
			{
				printf(temp, " ", "text");
				if(mtext->Display(tab+1) < 0)
					return -1;
				break;
			}
			case MessageID_VARIABLEMESSAGE:
			{
				printf(temp, " ", "variableMessage");
				if(mvariableMessage->Display(tab+1) < 0)
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

bool MessageID::ValidateMandatory(char *errStr){

	return true;
}

MessageType::MessageType()
{
	mTag = 0X000A;
}

MessageType::~MessageType()
{
}

bool MessageType::setValue(MESSAGETYPE val)
{
	mValue = val;
	return true;
}

MESSAGETYPE MessageType::getValue()
{
	return mValue;
}

int MessageType::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (MESSAGETYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int MessageType::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int MessageType::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", MESSAGETYPE_str(mValue), mValue);
	return 0;
}

MiscCallInfo::MiscCallInfo()
{
	mmessageType = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {false};
}

MiscCallInfo::~MiscCallInfo()
{
	if(mmessageType != NULL)
		delete mmessageType;
}

MessageType* MiscCallInfo::setmessageType(){
	if(mmessageType == NULL)
	{
		mmessageType = new MessageType();
		mTagsPresent |= MiscCallInfo_MESSAGETYPE;
		return mmessageType;
	}
	else
		return mmessageType;

}

bool MiscCallInfo::setmessageType(MessageType* messageType){
	if(mmessageType == NULL)
	{
		return -1;
	}
	else
	{
		mmessageType = messageType;
		return true;
	}

}

MessageType* MiscCallInfo::getmessageType() {//throw(const char*)
	if(NULL == mmessageType)
		throw("Object messageType is NULL");
	else
		return mmessageType;
}

bool MiscCallInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int MiscCallInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setmessageType())
					return -1;
				if(mmessageType->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: MiscCallInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("MiscCallInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int MiscCallInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("MiscCallInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case MiscCallInfo_MESSAGETYPE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmessageType->Encode(array) < 0) || 
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

	return 0;
}

int MiscCallInfo::Display(int tab){
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
			case MiscCallInfo_MESSAGETYPE:
			{
				printf(temp, " ", "messageType");
				if(mmessageType->Display(tab+1) < 0)
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

bool MiscCallInfo::ValidateMandatory(char *errStr){
	if(NULL == mmessageType)
	{
		strcpy(errStr, "messageType");
		return false;
	}

	return true;
}

MonitorMode::MonitorMode()
{
	mTag = 0X000A;
}

MonitorMode::~MonitorMode()
{
}

bool MonitorMode::setValue(MONITORMODE val)
{
	mValue = val;
	return true;
}

MONITORMODE MonitorMode::getValue()
{
	return mValue;
}

int MonitorMode::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (MONITORMODE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int MonitorMode::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int MonitorMode::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", MONITORMODE_str(mValue), mValue);
	return 0;
}


NotReachableReason::NotReachableReason()
{
	mTag = 0X000A;
}

NotReachableReason::~NotReachableReason()
{
}

bool NotReachableReason::setValue(NOTREACHABLEREASON val)
{
	mValue = val;
	return true;
}

NOTREACHABLEREASON NotReachableReason::getValue()
{
	return mValue;
}

int NotReachableReason::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (NOTREACHABLEREASON)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int NotReachableReason::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int NotReachableReason::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", NOTREACHABLEREASON_str(mValue), mValue);
	return 0;
}


NumberPortabilityStatus::NumberPortabilityStatus()
{
	mTag = 0X000A;
}

NumberPortabilityStatus::~NumberPortabilityStatus()
{
}

bool NumberPortabilityStatus::setValue(NUMBERPORTABILITYSTATUS val)
{
	mValue = val;
	return true;
}

NUMBERPORTABILITYSTATUS NumberPortabilityStatus::getValue()
{
	return mValue;
}

int NumberPortabilityStatus::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (NUMBERPORTABILITYSTATUS)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int NumberPortabilityStatus::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int NumberPortabilityStatus::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", NUMBERPORTABILITYSTATUS_str(mValue), mValue);
	return 0;
}

OAnswerSpecificInfo::OAnswerSpecificInfo()
{
	mdestinationAddress = NULL;
	mor_Call = false;
	mforwardedCall = false;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X9F32, 0X9F33, 0X9F34};
	mTagOptional = {true, true, true};
}

OAnswerSpecificInfo::~OAnswerSpecificInfo()
{
	if(mdestinationAddress != NULL)
		delete mdestinationAddress;
}

capstd::OctetString* OAnswerSpecificInfo::setdestinationAddress(){
	if(mdestinationAddress == NULL)
	{
		mdestinationAddress = new capstd::OctetString(2, 18);
		mTagsPresent |= OAnswerSpecificInfo_DESTINATIONADDRESS;
		return mdestinationAddress;
	}
	else
		return mdestinationAddress;

}

bool OAnswerSpecificInfo::setdestinationAddress(capstd::OctetString* destinationAddress){
	if(mdestinationAddress == NULL)
	{
		return -1;
	}
	else
	{
		mdestinationAddress = destinationAddress;
		return true;
	}

}

bool* OAnswerSpecificInfo::setor_Call(){
	mor_Call = true;
	mTagsPresent |= OAnswerSpecificInfo_OR_CALL;
	mNullor_Call = true;
	return &mNullor_Call;
}

bool OAnswerSpecificInfo::setor_Call(bool or_Call){
	mor_Call = or_Call;
	return true;
}

bool* OAnswerSpecificInfo::setforwardedCall(){
	mforwardedCall = true;
	mTagsPresent |= OAnswerSpecificInfo_FORWARDEDCALL;
	mNullforwardedCall = true;
	return &mNullforwardedCall;
}

bool OAnswerSpecificInfo::setforwardedCall(bool forwardedCall){
	mforwardedCall = forwardedCall;
	return true;
}

capstd::OctetString* OAnswerSpecificInfo::getdestinationAddress() {//throw(const char*)
	if(NULL == mdestinationAddress)
		throw("Object destinationAddress is NULL");
	else
		return mdestinationAddress;
}

bool OAnswerSpecificInfo::getor_Call() {
	return mor_Call;
}

bool OAnswerSpecificInfo::getforwardedCall() {
	return mforwardedCall;
}

bool OAnswerSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int OAnswerSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X9F32:
				if(NULL == this->setdestinationAddress())
					return -1;
				if(mdestinationAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F33:
				if(NULL == this->setor_Call())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F34:
				if(NULL == this->setforwardedCall())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: OAnswerSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("OAnswerSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int OAnswerSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("OAnswerSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case OAnswerSpecificInfo_DESTINATIONADDRESS:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdestinationAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case OAnswerSpecificInfo_OR_CALL:
				if(asn1_tag_encode(40755, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case OAnswerSpecificInfo_FORWARDEDCALL:
				if(asn1_tag_encode(40756, array) < 0)
					return -1;
				asn1_null_encode(array);
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

	return 0;
}

int OAnswerSpecificInfo::Display(int tab){
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
			case OAnswerSpecificInfo_DESTINATIONADDRESS:
			{
				printf(temp, " ", "destinationAddress");
				if(mdestinationAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case OAnswerSpecificInfo_OR_CALL:
			{
				printf(temp, " ", "or_Call");
				break;
			}
			case OAnswerSpecificInfo_FORWARDEDCALL:
			{
				printf(temp, " ", "forwardedCall");
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

bool OAnswerSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
OCalledPartyBusySpecificInfo::OCalledPartyBusySpecificInfo()
{
	mbusyCause = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {true};
}

OCalledPartyBusySpecificInfo::~OCalledPartyBusySpecificInfo()
{
	if(mbusyCause != NULL)
		delete mbusyCause;
}

capstd::GENERIC* OCalledPartyBusySpecificInfo::setbusyCause(){
	if(mbusyCause == NULL)
	{
		mbusyCause = new capstd::GENERIC();
		mTagsPresent |= OCalledPartyBusySpecificInfo_BUSYCAUSE;
		return mbusyCause;
	}
	else
		return mbusyCause;

}

bool OCalledPartyBusySpecificInfo::setbusyCause(capstd::GENERIC* busyCause){
	if(mbusyCause == NULL)
	{
		return -1;
	}
	else
	{
		mbusyCause = busyCause;
		return true;
	}

}

capstd::GENERIC* OCalledPartyBusySpecificInfo::getbusyCause() {//throw(const char*)
	if(NULL == mbusyCause)
		throw("Object busyCause is NULL");
	else
		return mbusyCause;
}

bool OCalledPartyBusySpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int OCalledPartyBusySpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setbusyCause())
					return -1;
				if(mbusyCause->Decode(array, &bytesDecoded, mTagArray, OCalledPartyBusySpecificInfo_BUSYCAUSE) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: OCalledPartyBusySpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("OCalledPartyBusySpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int OCalledPartyBusySpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("OCalledPartyBusySpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case OCalledPartyBusySpecificInfo_BUSYCAUSE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbusyCause->Encode(array) < 0) || 
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

	return 0;
}

int OCalledPartyBusySpecificInfo::Display(int tab){
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
			case OCalledPartyBusySpecificInfo_BUSYCAUSE:
			{
				printf(temp, " ", "busyCause");
				if(mbusyCause->Display(tab+1) < 0)
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

bool OCalledPartyBusySpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
ODisconnectSpecificInfo::ODisconnectSpecificInfo()
{
	mreleaseCause = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {true};
}

ODisconnectSpecificInfo::~ODisconnectSpecificInfo()
{
	if(mreleaseCause != NULL)
		delete mreleaseCause;
}

capstd::GENERIC* ODisconnectSpecificInfo::setreleaseCause(){
	if(mreleaseCause == NULL)
	{
		mreleaseCause = new capstd::GENERIC();
		mTagsPresent |= ODisconnectSpecificInfo_RELEASECAUSE;
		return mreleaseCause;
	}
	else
		return mreleaseCause;

}

bool ODisconnectSpecificInfo::setreleaseCause(capstd::GENERIC* releaseCause){
	if(mreleaseCause == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseCause = releaseCause;
		return true;
	}

}

capstd::GENERIC* ODisconnectSpecificInfo::getreleaseCause() {//throw(const char*)
	if(NULL == mreleaseCause)
		throw("Object releaseCause is NULL");
	else
		return mreleaseCause;
}

bool ODisconnectSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ODisconnectSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setreleaseCause())
					return -1;
				if(mreleaseCause->Decode(array, &bytesDecoded, mTagArray, ODisconnectSpecificInfo_RELEASECAUSE) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ODisconnectSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ODisconnectSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ODisconnectSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ODisconnectSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ODisconnectSpecificInfo_RELEASECAUSE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseCause->Encode(array) < 0) || 
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

	return 0;
}

int ODisconnectSpecificInfo::Display(int tab){
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
			case ODisconnectSpecificInfo_RELEASECAUSE:
			{
				printf(temp, " ", "releaseCause");
				if(mreleaseCause->Display(tab+1) < 0)
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

bool ODisconnectSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
PDP_ContextInfo::PDP_ContextInfo()
{
	mpdp_ContextIdentifier = NULL;
	mpdp_ContextActive = false;
	mpdp_Type = NULL;
	mpdp_Address = NULL;
	mapn_Subscribed = NULL;
	mapn_InUse = NULL;
	mnsapi = NULL;
	mtransactionId = NULL;
	mteid_ForGnAndGp = NULL;
	mteid_ForIu = NULL;
	mggsn_Address = NULL;
	mqos_Subscribed = NULL;
	mqos_Requested = NULL;
	mqos_Negotiated = NULL;
	mchargingId = NULL;
	mchargingCharacteristics = NULL;
	mrnc_Address = NULL;
	mextensionContainer = NULL;
	mqos2_Subscribed = NULL;
	mqos2_Requested = NULL;
	mqos2_Negotiated = NULL;
	mqos3_Subscribed = NULL;
	mqos3_Requested = NULL;
	mqos3_Negotiated = NULL;
	mqos4_Subscribed = NULL;
	mqos4_Requested = NULL;
	mqos4_Negotiated = NULL;
	mext_pdp_Type = NULL;
	mext_pdp_Address = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X0084, 0X0085, 0X0086, 0X0087, 0X0088, 0X0089, 0X008A, 0X008B, 0X008C, 0X008D, 0X008E, 0X008F, 0X0090, 0X00B1, 0X0092, 0X0093, 0X0094, 0X0095, 0X0096, 0X0097, 0X0099, 0X009A, 0X009B, 0X009C, 0X009D};
	mTagOptional = {false, true, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
}

PDP_ContextInfo::~PDP_ContextInfo()
{
	if(mpdp_ContextIdentifier != NULL)
		delete mpdp_ContextIdentifier;
	if(mpdp_Type != NULL)
		delete mpdp_Type;
	if(mpdp_Address != NULL)
		delete mpdp_Address;
	if(mapn_Subscribed != NULL)
		delete mapn_Subscribed;
	if(mapn_InUse != NULL)
		delete mapn_InUse;
	if(mnsapi != NULL)
		delete mnsapi;
	if(mtransactionId != NULL)
		delete mtransactionId;
	if(mteid_ForGnAndGp != NULL)
		delete mteid_ForGnAndGp;
	if(mteid_ForIu != NULL)
		delete mteid_ForIu;
	if(mggsn_Address != NULL)
		delete mggsn_Address;
	if(mqos_Subscribed != NULL)
		delete mqos_Subscribed;
	if(mqos_Requested != NULL)
		delete mqos_Requested;
	if(mqos_Negotiated != NULL)
		delete mqos_Negotiated;
	if(mchargingId != NULL)
		delete mchargingId;
	if(mchargingCharacteristics != NULL)
		delete mchargingCharacteristics;
	if(mrnc_Address != NULL)
		delete mrnc_Address;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mqos2_Subscribed != NULL)
		delete mqos2_Subscribed;
	if(mqos2_Requested != NULL)
		delete mqos2_Requested;
	if(mqos2_Negotiated != NULL)
		delete mqos2_Negotiated;
	if(mqos3_Subscribed != NULL)
		delete mqos3_Subscribed;
	if(mqos3_Requested != NULL)
		delete mqos3_Requested;
	if(mqos3_Negotiated != NULL)
		delete mqos3_Negotiated;
	if(mqos4_Subscribed != NULL)
		delete mqos4_Subscribed;
	if(mqos4_Requested != NULL)
		delete mqos4_Requested;
	if(mqos4_Negotiated != NULL)
		delete mqos4_Negotiated;
	if(mext_pdp_Type != NULL)
		delete mext_pdp_Type;
	if(mext_pdp_Address != NULL)
		delete mext_pdp_Address;
}

capstd::INTEGER* PDP_ContextInfo::setpdp_ContextIdentifier(){
	if(mpdp_ContextIdentifier == NULL)
	{
		mpdp_ContextIdentifier = new capstd::INTEGER(1, 50);
		mTagsPresent |= PDP_ContextInfo_PDP_CONTEXTIDENTIFIER;
		return mpdp_ContextIdentifier;
	}
	else
		return mpdp_ContextIdentifier;

}

bool PDP_ContextInfo::setpdp_ContextIdentifier(capstd::INTEGER* pdp_ContextIdentifier){
	if(mpdp_ContextIdentifier == NULL)
	{
		return -1;
	}
	else
	{
		mpdp_ContextIdentifier = pdp_ContextIdentifier;
		return true;
	}

}

bool* PDP_ContextInfo::setpdp_ContextActive(){
	mpdp_ContextActive = true;
	mTagsPresent |= PDP_ContextInfo_PDP_CONTEXTACTIVE;
	mNullpdp_ContextActive = true;
	return &mNullpdp_ContextActive;
}

bool PDP_ContextInfo::setpdp_ContextActive(bool pdp_ContextActive){
	mpdp_ContextActive = pdp_ContextActive;
	return true;
}

capstd::OctetString* PDP_ContextInfo::setpdp_Type(){
	if(mpdp_Type == NULL)
	{
		mpdp_Type = new capstd::OctetString(2, 2);
		mTagsPresent |= PDP_ContextInfo_PDP_TYPE;
		return mpdp_Type;
	}
	else
		return mpdp_Type;

}

bool PDP_ContextInfo::setpdp_Type(capstd::OctetString* pdp_Type){
	if(mpdp_Type == NULL)
	{
		return -1;
	}
	else
	{
		mpdp_Type = pdp_Type;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setpdp_Address(){
	if(mpdp_Address == NULL)
	{
		mpdp_Address = new capstd::OctetString(1, 16);
		mTagsPresent |= PDP_ContextInfo_PDP_ADDRESS;
		return mpdp_Address;
	}
	else
		return mpdp_Address;

}

bool PDP_ContextInfo::setpdp_Address(capstd::OctetString* pdp_Address){
	if(mpdp_Address == NULL)
	{
		return -1;
	}
	else
	{
		mpdp_Address = pdp_Address;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setapn_Subscribed(){
	if(mapn_Subscribed == NULL)
	{
		mapn_Subscribed = new capstd::OctetString(2, 63);
		mTagsPresent |= PDP_ContextInfo_APN_SUBSCRIBED;
		return mapn_Subscribed;
	}
	else
		return mapn_Subscribed;

}

bool PDP_ContextInfo::setapn_Subscribed(capstd::OctetString* apn_Subscribed){
	if(mapn_Subscribed == NULL)
	{
		return -1;
	}
	else
	{
		mapn_Subscribed = apn_Subscribed;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setapn_InUse(){
	if(mapn_InUse == NULL)
	{
		mapn_InUse = new capstd::OctetString(2, 63);
		mTagsPresent |= PDP_ContextInfo_APN_INUSE;
		return mapn_InUse;
	}
	else
		return mapn_InUse;

}

bool PDP_ContextInfo::setapn_InUse(capstd::OctetString* apn_InUse){
	if(mapn_InUse == NULL)
	{
		return -1;
	}
	else
	{
		mapn_InUse = apn_InUse;
		return true;
	}

}

capstd::INTEGER* PDP_ContextInfo::setnsapi(){
	if(mnsapi == NULL)
	{
		mnsapi = new capstd::INTEGER(0, 15);
		mTagsPresent |= PDP_ContextInfo_NSAPI;
		return mnsapi;
	}
	else
		return mnsapi;

}

bool PDP_ContextInfo::setnsapi(capstd::INTEGER* nsapi){
	if(mnsapi == NULL)
	{
		return -1;
	}
	else
	{
		mnsapi = nsapi;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::settransactionId(){
	if(mtransactionId == NULL)
	{
		mtransactionId = new capstd::OctetString(1, 2);
		mTagsPresent |= PDP_ContextInfo_TRANSACTIONID;
		return mtransactionId;
	}
	else
		return mtransactionId;

}

bool PDP_ContextInfo::settransactionId(capstd::OctetString* transactionId){
	if(mtransactionId == NULL)
	{
		return -1;
	}
	else
	{
		mtransactionId = transactionId;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setteid_ForGnAndGp(){
	if(mteid_ForGnAndGp == NULL)
	{
		mteid_ForGnAndGp = new capstd::OctetString(4, 4);
		mTagsPresent |= PDP_ContextInfo_TEID_FORGNANDGP;
		return mteid_ForGnAndGp;
	}
	else
		return mteid_ForGnAndGp;

}

bool PDP_ContextInfo::setteid_ForGnAndGp(capstd::OctetString* teid_ForGnAndGp){
	if(mteid_ForGnAndGp == NULL)
	{
		return -1;
	}
	else
	{
		mteid_ForGnAndGp = teid_ForGnAndGp;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setteid_ForIu(){
	if(mteid_ForIu == NULL)
	{
		mteid_ForIu = new capstd::OctetString(4, 4);
		mTagsPresent |= PDP_ContextInfo_TEID_FORIU;
		return mteid_ForIu;
	}
	else
		return mteid_ForIu;

}

bool PDP_ContextInfo::setteid_ForIu(capstd::OctetString* teid_ForIu){
	if(mteid_ForIu == NULL)
	{
		return -1;
	}
	else
	{
		mteid_ForIu = teid_ForIu;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setggsn_Address(){
	if(mggsn_Address == NULL)
	{
		mggsn_Address = new capstd::OctetString(5, 17);
		mTagsPresent |= PDP_ContextInfo_GGSN_ADDRESS;
		return mggsn_Address;
	}
	else
		return mggsn_Address;

}

bool PDP_ContextInfo::setggsn_Address(capstd::OctetString* ggsn_Address){
	if(mggsn_Address == NULL)
	{
		return -1;
	}
	else
	{
		mggsn_Address = ggsn_Address;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos_Subscribed(){
	if(mqos_Subscribed == NULL)
	{
		mqos_Subscribed = new capstd::OctetString(1, 9);
		mTagsPresent |= PDP_ContextInfo_QOS_SUBSCRIBED;
		return mqos_Subscribed;
	}
	else
		return mqos_Subscribed;

}

bool PDP_ContextInfo::setqos_Subscribed(capstd::OctetString* qos_Subscribed){
	if(mqos_Subscribed == NULL)
	{
		return -1;
	}
	else
	{
		mqos_Subscribed = qos_Subscribed;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos_Requested(){
	if(mqos_Requested == NULL)
	{
		mqos_Requested = new capstd::OctetString(1, 9);
		mTagsPresent |= PDP_ContextInfo_QOS_REQUESTED;
		return mqos_Requested;
	}
	else
		return mqos_Requested;

}

bool PDP_ContextInfo::setqos_Requested(capstd::OctetString* qos_Requested){
	if(mqos_Requested == NULL)
	{
		return -1;
	}
	else
	{
		mqos_Requested = qos_Requested;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos_Negotiated(){
	if(mqos_Negotiated == NULL)
	{
		mqos_Negotiated = new capstd::OctetString(1, 9);
		mTagsPresent |= PDP_ContextInfo_QOS_NEGOTIATED;
		return mqos_Negotiated;
	}
	else
		return mqos_Negotiated;

}

bool PDP_ContextInfo::setqos_Negotiated(capstd::OctetString* qos_Negotiated){
	if(mqos_Negotiated == NULL)
	{
		return -1;
	}
	else
	{
		mqos_Negotiated = qos_Negotiated;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setchargingId(){
	if(mchargingId == NULL)
	{
		mchargingId = new capstd::OctetString(4, 4);
		mTagsPresent |= PDP_ContextInfo_CHARGINGID;
		return mchargingId;
	}
	else
		return mchargingId;

}

bool PDP_ContextInfo::setchargingId(capstd::OctetString* chargingId){
	if(mchargingId == NULL)
	{
		return -1;
	}
	else
	{
		mchargingId = chargingId;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setchargingCharacteristics(){
	if(mchargingCharacteristics == NULL)
	{
		mchargingCharacteristics = new capstd::OctetString(2, 2);
		mTagsPresent |= PDP_ContextInfo_CHARGINGCHARACTERISTICS;
		return mchargingCharacteristics;
	}
	else
		return mchargingCharacteristics;

}

bool PDP_ContextInfo::setchargingCharacteristics(capstd::OctetString* chargingCharacteristics){
	if(mchargingCharacteristics == NULL)
	{
		return -1;
	}
	else
	{
		mchargingCharacteristics = chargingCharacteristics;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setrnc_Address(){
	if(mrnc_Address == NULL)
	{
		mrnc_Address = new capstd::OctetString(5, 17);
		mTagsPresent |= PDP_ContextInfo_RNC_ADDRESS;
		return mrnc_Address;
	}
	else
		return mrnc_Address;

}

bool PDP_ContextInfo::setrnc_Address(capstd::OctetString* rnc_Address){
	if(mrnc_Address == NULL)
	{
		return -1;
	}
	else
	{
		mrnc_Address = rnc_Address;
		return true;
	}

}

capstd::GENERIC* PDP_ContextInfo::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= PDP_ContextInfo_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool PDP_ContextInfo::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos2_Subscribed(){
	if(mqos2_Subscribed == NULL)
	{
		mqos2_Subscribed = new capstd::OctetString(1, 3);
		mTagsPresent |= PDP_ContextInfo_QOS2_SUBSCRIBED;
		return mqos2_Subscribed;
	}
	else
		return mqos2_Subscribed;

}

bool PDP_ContextInfo::setqos2_Subscribed(capstd::OctetString* qos2_Subscribed){
	if(mqos2_Subscribed == NULL)
	{
		return -1;
	}
	else
	{
		mqos2_Subscribed = qos2_Subscribed;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos2_Requested(){
	if(mqos2_Requested == NULL)
	{
		mqos2_Requested = new capstd::OctetString(1, 3);
		mTagsPresent |= PDP_ContextInfo_QOS2_REQUESTED;
		return mqos2_Requested;
	}
	else
		return mqos2_Requested;

}

bool PDP_ContextInfo::setqos2_Requested(capstd::OctetString* qos2_Requested){
	if(mqos2_Requested == NULL)
	{
		return -1;
	}
	else
	{
		mqos2_Requested = qos2_Requested;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos2_Negotiated(){
	if(mqos2_Negotiated == NULL)
	{
		mqos2_Negotiated = new capstd::OctetString(1, 3);
		mTagsPresent |= PDP_ContextInfo_QOS2_NEGOTIATED;
		return mqos2_Negotiated;
	}
	else
		return mqos2_Negotiated;

}

bool PDP_ContextInfo::setqos2_Negotiated(capstd::OctetString* qos2_Negotiated){
	if(mqos2_Negotiated == NULL)
	{
		return -1;
	}
	else
	{
		mqos2_Negotiated = qos2_Negotiated;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos3_Subscribed(){
	if(mqos3_Subscribed == NULL)
	{
		mqos3_Subscribed = new capstd::OctetString(1, 2);
		mTagsPresent |= PDP_ContextInfo_QOS3_SUBSCRIBED;
		return mqos3_Subscribed;
	}
	else
		return mqos3_Subscribed;

}

bool PDP_ContextInfo::setqos3_Subscribed(capstd::OctetString* qos3_Subscribed){
	if(mqos3_Subscribed == NULL)
	{
		return -1;
	}
	else
	{
		mqos3_Subscribed = qos3_Subscribed;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos3_Requested(){
	if(mqos3_Requested == NULL)
	{
		mqos3_Requested = new capstd::OctetString(1, 2);
		mTagsPresent |= PDP_ContextInfo_QOS3_REQUESTED;
		return mqos3_Requested;
	}
	else
		return mqos3_Requested;

}

bool PDP_ContextInfo::setqos3_Requested(capstd::OctetString* qos3_Requested){
	if(mqos3_Requested == NULL)
	{
		return -1;
	}
	else
	{
		mqos3_Requested = qos3_Requested;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos3_Negotiated(){
	if(mqos3_Negotiated == NULL)
	{
		mqos3_Negotiated = new capstd::OctetString(1, 2);
		mTagsPresent |= PDP_ContextInfo_QOS3_NEGOTIATED;
		return mqos3_Negotiated;
	}
	else
		return mqos3_Negotiated;

}

bool PDP_ContextInfo::setqos3_Negotiated(capstd::OctetString* qos3_Negotiated){
	if(mqos3_Negotiated == NULL)
	{
		return -1;
	}
	else
	{
		mqos3_Negotiated = qos3_Negotiated;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos4_Subscribed(){
	if(mqos4_Subscribed == NULL)
	{
		mqos4_Subscribed = new capstd::OctetString(1, 1);
		mTagsPresent |= PDP_ContextInfo_QOS4_SUBSCRIBED;
		return mqos4_Subscribed;
	}
	else
		return mqos4_Subscribed;

}

bool PDP_ContextInfo::setqos4_Subscribed(capstd::OctetString* qos4_Subscribed){
	if(mqos4_Subscribed == NULL)
	{
		return -1;
	}
	else
	{
		mqos4_Subscribed = qos4_Subscribed;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos4_Requested(){
	if(mqos4_Requested == NULL)
	{
		mqos4_Requested = new capstd::OctetString(1, 1);
		mTagsPresent |= PDP_ContextInfo_QOS4_REQUESTED;
		return mqos4_Requested;
	}
	else
		return mqos4_Requested;

}

bool PDP_ContextInfo::setqos4_Requested(capstd::OctetString* qos4_Requested){
	if(mqos4_Requested == NULL)
	{
		return -1;
	}
	else
	{
		mqos4_Requested = qos4_Requested;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setqos4_Negotiated(){
	if(mqos4_Negotiated == NULL)
	{
		mqos4_Negotiated = new capstd::OctetString(1, 1);
		mTagsPresent |= PDP_ContextInfo_QOS4_NEGOTIATED;
		return mqos4_Negotiated;
	}
	else
		return mqos4_Negotiated;

}

bool PDP_ContextInfo::setqos4_Negotiated(capstd::OctetString* qos4_Negotiated){
	if(mqos4_Negotiated == NULL)
	{
		return -1;
	}
	else
	{
		mqos4_Negotiated = qos4_Negotiated;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setext_pdp_Type(){
	if(mext_pdp_Type == NULL)
	{
		mext_pdp_Type = new capstd::OctetString(2, 2);
		mTagsPresent |= PDP_ContextInfo_EXT_PDP_TYPE;
		return mext_pdp_Type;
	}
	else
		return mext_pdp_Type;

}

bool PDP_ContextInfo::setext_pdp_Type(capstd::OctetString* ext_pdp_Type){
	if(mext_pdp_Type == NULL)
	{
		return -1;
	}
	else
	{
		mext_pdp_Type = ext_pdp_Type;
		return true;
	}

}

capstd::OctetString* PDP_ContextInfo::setext_pdp_Address(){
	if(mext_pdp_Address == NULL)
	{
		mext_pdp_Address = new capstd::OctetString(1, 16);
		mTagsPresent |= PDP_ContextInfo_EXT_PDP_ADDRESS;
		return mext_pdp_Address;
	}
	else
		return mext_pdp_Address;

}

bool PDP_ContextInfo::setext_pdp_Address(capstd::OctetString* ext_pdp_Address){
	if(mext_pdp_Address == NULL)
	{
		return -1;
	}
	else
	{
		mext_pdp_Address = ext_pdp_Address;
		return true;
	}

}

capstd::INTEGER* PDP_ContextInfo::getpdp_ContextIdentifier() {//throw(const char*)
	if(NULL == mpdp_ContextIdentifier)
		throw("Object pdp_ContextIdentifier is NULL");
	else
		return mpdp_ContextIdentifier;
}

bool PDP_ContextInfo::getpdp_ContextActive() {
	return mpdp_ContextActive;
}

capstd::OctetString* PDP_ContextInfo::getpdp_Type() {//throw(const char*)
	if(NULL == mpdp_Type)
		throw("Object pdp_Type is NULL");
	else
		return mpdp_Type;
}

capstd::OctetString* PDP_ContextInfo::getpdp_Address() {//throw(const char*)
	if(NULL == mpdp_Address)
		throw("Object pdp_Address is NULL");
	else
		return mpdp_Address;
}

capstd::OctetString* PDP_ContextInfo::getapn_Subscribed() {//throw(const char*)
	if(NULL == mapn_Subscribed)
		throw("Object apn_Subscribed is NULL");
	else
		return mapn_Subscribed;
}

capstd::OctetString* PDP_ContextInfo::getapn_InUse() {//throw(const char*)
	if(NULL == mapn_InUse)
		throw("Object apn_InUse is NULL");
	else
		return mapn_InUse;
}

capstd::INTEGER* PDP_ContextInfo::getnsapi() {//throw(const char*)
	if(NULL == mnsapi)
		throw("Object nsapi is NULL");
	else
		return mnsapi;
}

capstd::OctetString* PDP_ContextInfo::gettransactionId() {//throw(const char*)
	if(NULL == mtransactionId)
		throw("Object transactionId is NULL");
	else
		return mtransactionId;
}

capstd::OctetString* PDP_ContextInfo::getteid_ForGnAndGp() {//throw(const char*)
	if(NULL == mteid_ForGnAndGp)
		throw("Object teid_ForGnAndGp is NULL");
	else
		return mteid_ForGnAndGp;
}

capstd::OctetString* PDP_ContextInfo::getteid_ForIu() {//throw(const char*)
	if(NULL == mteid_ForIu)
		throw("Object teid_ForIu is NULL");
	else
		return mteid_ForIu;
}

capstd::OctetString* PDP_ContextInfo::getggsn_Address() {//throw(const char*)
	if(NULL == mggsn_Address)
		throw("Object ggsn_Address is NULL");
	else
		return mggsn_Address;
}

capstd::OctetString* PDP_ContextInfo::getqos_Subscribed() {//throw(const char*)
	if(NULL == mqos_Subscribed)
		throw("Object qos_Subscribed is NULL");
	else
		return mqos_Subscribed;
}

capstd::OctetString* PDP_ContextInfo::getqos_Requested() {//throw(const char*)
	if(NULL == mqos_Requested)
		throw("Object qos_Requested is NULL");
	else
		return mqos_Requested;
}

capstd::OctetString* PDP_ContextInfo::getqos_Negotiated() {//throw(const char*)
	if(NULL == mqos_Negotiated)
		throw("Object qos_Negotiated is NULL");
	else
		return mqos_Negotiated;
}

capstd::OctetString* PDP_ContextInfo::getchargingId() {//throw(const char*)
	if(NULL == mchargingId)
		throw("Object chargingId is NULL");
	else
		return mchargingId;
}

capstd::OctetString* PDP_ContextInfo::getchargingCharacteristics() {//throw(const char*)
	if(NULL == mchargingCharacteristics)
		throw("Object chargingCharacteristics is NULL");
	else
		return mchargingCharacteristics;
}

capstd::OctetString* PDP_ContextInfo::getrnc_Address() {//throw(const char*)
	if(NULL == mrnc_Address)
		throw("Object rnc_Address is NULL");
	else
		return mrnc_Address;
}

capstd::GENERIC* PDP_ContextInfo::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

capstd::OctetString* PDP_ContextInfo::getqos2_Subscribed() {//throw(const char*)
	if(NULL == mqos2_Subscribed)
		throw("Object qos2_Subscribed is NULL");
	else
		return mqos2_Subscribed;
}

capstd::OctetString* PDP_ContextInfo::getqos2_Requested() {//throw(const char*)
	if(NULL == mqos2_Requested)
		throw("Object qos2_Requested is NULL");
	else
		return mqos2_Requested;
}

capstd::OctetString* PDP_ContextInfo::getqos2_Negotiated() {//throw(const char*)
	if(NULL == mqos2_Negotiated)
		throw("Object qos2_Negotiated is NULL");
	else
		return mqos2_Negotiated;
}

capstd::OctetString* PDP_ContextInfo::getqos3_Subscribed() {//throw(const char*)
	if(NULL == mqos3_Subscribed)
		throw("Object qos3_Subscribed is NULL");
	else
		return mqos3_Subscribed;
}

capstd::OctetString* PDP_ContextInfo::getqos3_Requested() {//throw(const char*)
	if(NULL == mqos3_Requested)
		throw("Object qos3_Requested is NULL");
	else
		return mqos3_Requested;
}

capstd::OctetString* PDP_ContextInfo::getqos3_Negotiated() {//throw(const char*)
	if(NULL == mqos3_Negotiated)
		throw("Object qos3_Negotiated is NULL");
	else
		return mqos3_Negotiated;
}

capstd::OctetString* PDP_ContextInfo::getqos4_Subscribed() {//throw(const char*)
	if(NULL == mqos4_Subscribed)
		throw("Object qos4_Subscribed is NULL");
	else
		return mqos4_Subscribed;
}

capstd::OctetString* PDP_ContextInfo::getqos4_Requested() {//throw(const char*)
	if(NULL == mqos4_Requested)
		throw("Object qos4_Requested is NULL");
	else
		return mqos4_Requested;
}

capstd::OctetString* PDP_ContextInfo::getqos4_Negotiated() {//throw(const char*)
	if(NULL == mqos4_Negotiated)
		throw("Object qos4_Negotiated is NULL");
	else
		return mqos4_Negotiated;
}

capstd::OctetString* PDP_ContextInfo::getext_pdp_Type() {//throw(const char*)
	if(NULL == mext_pdp_Type)
		throw("Object ext_pdp_Type is NULL");
	else
		return mext_pdp_Type;
}

capstd::OctetString* PDP_ContextInfo::getext_pdp_Address() {//throw(const char*)
	if(NULL == mext_pdp_Address)
		throw("Object ext_pdp_Address is NULL");
	else
		return mext_pdp_Address;
}

bool PDP_ContextInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int PDP_ContextInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setpdp_ContextIdentifier())
					return -1;
				if(mpdp_ContextIdentifier->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setpdp_ContextActive())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setpdp_Type())
					return -1;
				if(mpdp_Type->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setpdp_Address())
					return -1;
				if(mpdp_Address->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setapn_Subscribed())
					return -1;
				if(mapn_Subscribed->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setapn_InUse())
					return -1;
				if(mapn_InUse->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setnsapi())
					return -1;
				if(mnsapi->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->settransactionId())
					return -1;
				if(mtransactionId->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->setteid_ForGnAndGp())
					return -1;
				if(mteid_ForGnAndGp->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setteid_ForIu())
					return -1;
				if(mteid_ForIu->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setggsn_Address())
					return -1;
				if(mggsn_Address->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008B:
				if(NULL == this->setqos_Subscribed())
					return -1;
				if(mqos_Subscribed->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008C:
				if(NULL == this->setqos_Requested())
					return -1;
				if(mqos_Requested->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008D:
				if(NULL == this->setqos_Negotiated())
					return -1;
				if(mqos_Negotiated->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008E:
				if(NULL == this->setchargingId())
					return -1;
				if(mchargingId->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008F:
				if(NULL == this->setchargingCharacteristics())
					return -1;
				if(mchargingCharacteristics->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0090:
				if(NULL == this->setrnc_Address())
					return -1;
				if(mrnc_Address->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00B1:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, PDP_ContextInfo_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			case 0X0092:
				if(NULL == this->setqos2_Subscribed())
					return -1;
				if(mqos2_Subscribed->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0093:
				if(NULL == this->setqos2_Requested())
					return -1;
				if(mqos2_Requested->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0094:
				if(NULL == this->setqos2_Negotiated())
					return -1;
				if(mqos2_Negotiated->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0095:
				if(NULL == this->setqos3_Subscribed())
					return -1;
				if(mqos3_Subscribed->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0096:
				if(NULL == this->setqos3_Requested())
					return -1;
				if(mqos3_Requested->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0097:
				if(NULL == this->setqos3_Negotiated())
					return -1;
				if(mqos3_Negotiated->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0099:
				if(NULL == this->setqos4_Subscribed())
					return -1;
				if(mqos4_Subscribed->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009A:
				if(NULL == this->setqos4_Requested())
					return -1;
				if(mqos4_Requested->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009B:
				if(NULL == this->setqos4_Negotiated())
					return -1;
				if(mqos4_Negotiated->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009C:
				if(NULL == this->setext_pdp_Type())
					return -1;
				if(mext_pdp_Type->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X009D:
				if(NULL == this->setext_pdp_Address())
					return -1;
				if(mext_pdp_Address->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: PDP_ContextInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("PDP_ContextInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int PDP_ContextInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("PDP_ContextInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case PDP_ContextInfo_PDP_CONTEXTIDENTIFIER:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpdp_ContextIdentifier->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_PDP_CONTEXTACTIVE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case PDP_ContextInfo_PDP_TYPE:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpdp_Type->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_PDP_ADDRESS:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpdp_Address->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_APN_SUBSCRIBED:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mapn_Subscribed->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_APN_INUSE:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mapn_InUse->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_NSAPI:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnsapi->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_TRANSACTIONID:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtransactionId->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_TEID_FORGNANDGP:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mteid_ForGnAndGp->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_TEID_FORIU:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mteid_ForIu->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_GGSN_ADDRESS:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mggsn_Address->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS_SUBSCRIBED:
				if(asn1_tag_encode(139, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos_Subscribed->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS_REQUESTED:
				if(asn1_tag_encode(140, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos_Requested->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS_NEGOTIATED:
				if(asn1_tag_encode(141, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos_Negotiated->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_CHARGINGID:
				if(asn1_tag_encode(142, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mchargingId->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_CHARGINGCHARACTERISTICS:
				if(asn1_tag_encode(143, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mchargingCharacteristics->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_RNC_ADDRESS:
				if(asn1_tag_encode(144, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrnc_Address->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_EXTENSIONCONTAINER:
				if(asn1_tag_encode(177, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS2_SUBSCRIBED:
				if(asn1_tag_encode(146, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos2_Subscribed->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS2_REQUESTED:
				if(asn1_tag_encode(147, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos2_Requested->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS2_NEGOTIATED:
				if(asn1_tag_encode(148, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos2_Negotiated->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS3_SUBSCRIBED:
				if(asn1_tag_encode(149, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos3_Subscribed->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS3_REQUESTED:
				if(asn1_tag_encode(150, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos3_Requested->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS3_NEGOTIATED:
				if(asn1_tag_encode(151, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos3_Negotiated->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS4_SUBSCRIBED:
				if(asn1_tag_encode(153, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos4_Subscribed->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS4_REQUESTED:
				if(asn1_tag_encode(154, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos4_Requested->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_QOS4_NEGOTIATED:
				if(asn1_tag_encode(155, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mqos4_Negotiated->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_EXT_PDP_TYPE:
				if(asn1_tag_encode(156, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mext_pdp_Type->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case PDP_ContextInfo_EXT_PDP_ADDRESS:
				if(asn1_tag_encode(157, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mext_pdp_Address->Encode(array) < 0) || 
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

	return 0;
}

int PDP_ContextInfo::Display(int tab){
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
			case PDP_ContextInfo_PDP_CONTEXTIDENTIFIER:
			{
				printf(temp, " ", "pdp_ContextIdentifier");
				if(mpdp_ContextIdentifier->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_PDP_CONTEXTACTIVE:
			{
				printf(temp, " ", "pdp_ContextActive");
				break;
			}
			case PDP_ContextInfo_PDP_TYPE:
			{
				printf(temp, " ", "pdp_Type");
				if(mpdp_Type->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_PDP_ADDRESS:
			{
				printf(temp, " ", "pdp_Address");
				if(mpdp_Address->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_APN_SUBSCRIBED:
			{
				printf(temp, " ", "apn_Subscribed");
				if(mapn_Subscribed->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_APN_INUSE:
			{
				printf(temp, " ", "apn_InUse");
				if(mapn_InUse->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_NSAPI:
			{
				printf(temp, " ", "nsapi");
				if(mnsapi->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_TRANSACTIONID:
			{
				printf(temp, " ", "transactionId");
				if(mtransactionId->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_TEID_FORGNANDGP:
			{
				printf(temp, " ", "teid_ForGnAndGp");
				if(mteid_ForGnAndGp->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_TEID_FORIU:
			{
				printf(temp, " ", "teid_ForIu");
				if(mteid_ForIu->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_GGSN_ADDRESS:
			{
				printf(temp, " ", "ggsn_Address");
				if(mggsn_Address->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS_SUBSCRIBED:
			{
				printf(temp, " ", "qos_Subscribed");
				if(mqos_Subscribed->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS_REQUESTED:
			{
				printf(temp, " ", "qos_Requested");
				if(mqos_Requested->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS_NEGOTIATED:
			{
				printf(temp, " ", "qos_Negotiated");
				if(mqos_Negotiated->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_CHARGINGID:
			{
				printf(temp, " ", "chargingId");
				if(mchargingId->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_CHARGINGCHARACTERISTICS:
			{
				printf(temp, " ", "chargingCharacteristics");
				if(mchargingCharacteristics->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_RNC_ADDRESS:
			{
				printf(temp, " ", "rnc_Address");
				if(mrnc_Address->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS2_SUBSCRIBED:
			{
				printf(temp, " ", "qos2_Subscribed");
				if(mqos2_Subscribed->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS2_REQUESTED:
			{
				printf(temp, " ", "qos2_Requested");
				if(mqos2_Requested->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS2_NEGOTIATED:
			{
				printf(temp, " ", "qos2_Negotiated");
				if(mqos2_Negotiated->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS3_SUBSCRIBED:
			{
				printf(temp, " ", "qos3_Subscribed");
				if(mqos3_Subscribed->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS3_REQUESTED:
			{
				printf(temp, " ", "qos3_Requested");
				if(mqos3_Requested->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS3_NEGOTIATED:
			{
				printf(temp, " ", "qos3_Negotiated");
				if(mqos3_Negotiated->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS4_SUBSCRIBED:
			{
				printf(temp, " ", "qos4_Subscribed");
				if(mqos4_Subscribed->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS4_REQUESTED:
			{
				printf(temp, " ", "qos4_Requested");
				if(mqos4_Requested->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_QOS4_NEGOTIATED:
			{
				printf(temp, " ", "qos4_Negotiated");
				if(mqos4_Negotiated->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_EXT_PDP_TYPE:
			{
				printf(temp, " ", "ext_pdp_Type");
				if(mext_pdp_Type->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PDP_ContextInfo_EXT_PDP_ADDRESS:
			{
				printf(temp, " ", "ext_pdp_Address");
				if(mext_pdp_Address->Display(tab+1) < 0)
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

bool PDP_ContextInfo::ValidateMandatory(char *errStr){
	if(NULL == mpdp_ContextIdentifier)
	{
		strcpy(errStr, "pdp_ContextIdentifier");
		return false;
	}
	else if(NULL == mpdp_Type)
	{
		strcpy(errStr, "pdp_Type");
		return false;
	}

	return true;
}

PDP_ContextInfoList::PDP_ContextInfoList()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 0;
	mParamList.clear();
}

PDP_ContextInfoList::~PDP_ContextInfoList()
{
	vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

PDP_ContextInfo* PDP_ContextInfoList::getPDP_ContextInfo()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object PDP_ContextInfo is NULL");
}

PDP_ContextInfo* PDP_ContextInfoList::getNextPDP_ContextInfo()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object PDP_ContextInfo is NULL");
}

PDP_ContextInfo* PDP_ContextInfoList::getPDP_ContextInfoAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object PDP_ContextInfo is NULL");
}

unsigned PDP_ContextInfoList::getNoOfPDP_ContextInfo()
{
	return mParamList.size();
}

bool PDP_ContextInfoList::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

PDP_ContextInfo* PDP_ContextInfoList::setNewPDP_ContextInfo()
{
	mPDP_ContextInfo = new PDP_ContextInfo();
	if(NULL == mPDP_ContextInfo)
		return NULL;
	mParamList.push_back(mPDP_ContextInfo);
	mCounter++;
	return mPDP_ContextInfo;
}

PDP_ContextInfo* PDP_ContextInfoList::setPDP_ContextInfo()
{
	if(NULL == mPDP_ContextInfo)
		return NULL;
	return mPDP_ContextInfo;
}

int PDP_ContextInfoList::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				this->setNewPDP_ContextInfo();
				if(mPDP_ContextInfo->Decode(array, &bytesDecoded) < 0)
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
int PDP_ContextInfoList::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(48, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int PDP_ContextInfoList::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<PDP_ContextInfo *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "PDP_ContextInfo");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

PS_SubscriberState::PS_SubscriberState()
{
	mnotProvidedFromSGSNorMME = false;
	mps_Detached = false;
	mps_AttachedNotReachableForPaging = false;
	mps_AttachedReachableForPaging = false;
	mps_PDP_ActiveNotReachableForPaging = NULL;
	mps_PDP_ActiveReachableForPaging = NULL;
	mnetDetNotReachable = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X00A4, 0X00A5, 0X000A};
}

PS_SubscriberState::~PS_SubscriberState()
{
	if(mps_PDP_ActiveNotReachableForPaging != NULL)
		delete mps_PDP_ActiveNotReachableForPaging;
	if(mps_PDP_ActiveReachableForPaging != NULL)
		delete mps_PDP_ActiveReachableForPaging;
	if(mnetDetNotReachable != NULL)
		delete mnetDetNotReachable;
}

bool* PS_SubscriberState::setnotProvidedFromSGSNorMME(){
if(mParamSet == true)
	{
		if(mNullnotProvidedFromSGSNorMME == true)
			return &mnotProvidedFromSGSNorMME;
		else
			return NULL;
	}
	mTagsPresent |= PS_SubscriberState_NOTPROVIDEDFROMSGSNORMME;
		mParamSet = true;
	mNullnotProvidedFromSGSNorMME = true;
	return &mNullnotProvidedFromSGSNorMME;
}

bool PS_SubscriberState::setnotProvidedFromSGSNorMME(bool notProvidedFromSGSNorMME){
	mnotProvidedFromSGSNorMME = notProvidedFromSGSNorMME;
	return true;
}

bool* PS_SubscriberState::setps_Detached(){
if(mParamSet == true)
	{
		if(mNullps_Detached == true)
			return &mps_Detached;
		else
			return NULL;
	}
	mTagsPresent |= PS_SubscriberState_PS_DETACHED;
		mParamSet = true;
	mNullps_Detached = true;
	return &mNullps_Detached;
}

bool PS_SubscriberState::setps_Detached(bool ps_Detached){
	mps_Detached = ps_Detached;
	return true;
}

bool* PS_SubscriberState::setps_AttachedNotReachableForPaging(){
if(mParamSet == true)
	{
		if(mNullps_AttachedNotReachableForPaging == true)
			return &mps_AttachedNotReachableForPaging;
		else
			return NULL;
	}
	mTagsPresent |= PS_SubscriberState_PS_ATTACHEDNOTREACHABLEFORPAGING;
		mParamSet = true;
	mNullps_AttachedNotReachableForPaging = true;
	return &mNullps_AttachedNotReachableForPaging;
}

bool PS_SubscriberState::setps_AttachedNotReachableForPaging(bool ps_AttachedNotReachableForPaging){
	mps_AttachedNotReachableForPaging = ps_AttachedNotReachableForPaging;
	return true;
}

bool* PS_SubscriberState::setps_AttachedReachableForPaging(){
if(mParamSet == true)
	{
		if(mNullps_AttachedReachableForPaging == true)
			return &mps_AttachedReachableForPaging;
		else
			return NULL;
	}
	mTagsPresent |= PS_SubscriberState_PS_ATTACHEDREACHABLEFORPAGING;
		mParamSet = true;
	mNullps_AttachedReachableForPaging = true;
	return &mNullps_AttachedReachableForPaging;
}

bool PS_SubscriberState::setps_AttachedReachableForPaging(bool ps_AttachedReachableForPaging){
	mps_AttachedReachableForPaging = ps_AttachedReachableForPaging;
	return true;
}

PDP_ContextInfoList* PS_SubscriberState::setps_PDP_ActiveNotReachableForPaging(){
if(mParamSet == true)
	{
		if(mps_PDP_ActiveNotReachableForPaging != NULL)
			return mps_PDP_ActiveNotReachableForPaging;
		else
			return NULL;
	}
	if(mps_PDP_ActiveNotReachableForPaging == NULL)
	{
		mps_PDP_ActiveNotReachableForPaging = new PDP_ContextInfoList();
		mTagsPresent |= PS_SubscriberState_PS_PDP_ACTIVENOTREACHABLEFORPAGING;
		mParamSet = true;
		return mps_PDP_ActiveNotReachableForPaging;
	}
}

bool PS_SubscriberState::setps_PDP_ActiveNotReachableForPaging(PDP_ContextInfoList* ps_PDP_ActiveNotReachableForPaging){
	if(mps_PDP_ActiveNotReachableForPaging == NULL)
	{
		return -1;
	}
	else
	{
		mps_PDP_ActiveNotReachableForPaging = ps_PDP_ActiveNotReachableForPaging;
		return true;
	}

}

PDP_ContextInfoList* PS_SubscriberState::setps_PDP_ActiveReachableForPaging(){
if(mParamSet == true)
	{
		if(mps_PDP_ActiveReachableForPaging != NULL)
			return mps_PDP_ActiveReachableForPaging;
		else
			return NULL;
	}
	if(mps_PDP_ActiveReachableForPaging == NULL)
	{
		mps_PDP_ActiveReachableForPaging = new PDP_ContextInfoList();
		mTagsPresent |= PS_SubscriberState_PS_PDP_ACTIVEREACHABLEFORPAGING;
		mParamSet = true;
		return mps_PDP_ActiveReachableForPaging;
	}
}

bool PS_SubscriberState::setps_PDP_ActiveReachableForPaging(PDP_ContextInfoList* ps_PDP_ActiveReachableForPaging){
	if(mps_PDP_ActiveReachableForPaging == NULL)
	{
		return -1;
	}
	else
	{
		mps_PDP_ActiveReachableForPaging = ps_PDP_ActiveReachableForPaging;
		return true;
	}

}

NotReachableReason* PS_SubscriberState::setnetDetNotReachable(){
if(mParamSet == true)
	{
		if(mnetDetNotReachable != NULL)
			return mnetDetNotReachable;
		else
			return NULL;
	}
	if(mnetDetNotReachable == NULL)
	{
		mnetDetNotReachable = new NotReachableReason();
		mTagsPresent |= PS_SubscriberState_NETDETNOTREACHABLE;
		mParamSet = true;
		return mnetDetNotReachable;
	}
}

bool PS_SubscriberState::setnetDetNotReachable(NotReachableReason* netDetNotReachable){
	if(mnetDetNotReachable == NULL)
	{
		return -1;
	}
	else
	{
		mnetDetNotReachable = netDetNotReachable;
		return true;
	}

}

bool PS_SubscriberState::getnotProvidedFromSGSNorMME() {
	return mnotProvidedFromSGSNorMME;
}

bool PS_SubscriberState::getps_Detached() {
	return mps_Detached;
}

bool PS_SubscriberState::getps_AttachedNotReachableForPaging() {
	return mps_AttachedNotReachableForPaging;
}

bool PS_SubscriberState::getps_AttachedReachableForPaging() {
	return mps_AttachedReachableForPaging;
}

PDP_ContextInfoList* PS_SubscriberState::getps_PDP_ActiveNotReachableForPaging() {//throw(const char*)
	if(NULL == mps_PDP_ActiveNotReachableForPaging)
		throw("Object ps_PDP_ActiveNotReachableForPaging is NULL");
	else
		return mps_PDP_ActiveNotReachableForPaging;
}

PDP_ContextInfoList* PS_SubscriberState::getps_PDP_ActiveReachableForPaging() {//throw(const char*)
	if(NULL == mps_PDP_ActiveReachableForPaging)
		throw("Object ps_PDP_ActiveReachableForPaging is NULL");
	else
		return mps_PDP_ActiveReachableForPaging;
}

NotReachableReason* PS_SubscriberState::getnetDetNotReachable() {//throw(const char*)
	if(NULL == mnetDetNotReachable)
		throw("Object netDetNotReachable is NULL");
	else
		return mnetDetNotReachable;
}

bool PS_SubscriberState::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int PS_SubscriberState::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setnotProvidedFromSGSNorMME())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setps_Detached())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0082:
				if(NULL == this->setps_AttachedNotReachableForPaging())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0083:
				if(NULL == this->setps_AttachedReachableForPaging())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A4:
				if(NULL == this->setps_PDP_ActiveNotReachableForPaging())
					return -1;
				if(mps_PDP_ActiveNotReachableForPaging->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A5:
				if(NULL == this->setps_PDP_ActiveReachableForPaging())
					return -1;
				if(mps_PDP_ActiveReachableForPaging->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X000A:
				if(NULL == this->setnetDetNotReachable())
					return -1;
				if(mnetDetNotReachable->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: PS_SubscriberState Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("PS_SubscriberState: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int PS_SubscriberState::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("PS_SubscriberState: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case PS_SubscriberState_NOTPROVIDEDFROMSGSNORMME:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case PS_SubscriberState_PS_DETACHED:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case PS_SubscriberState_PS_ATTACHEDNOTREACHABLEFORPAGING:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case PS_SubscriberState_PS_ATTACHEDREACHABLEFORPAGING:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case PS_SubscriberState_PS_PDP_ACTIVENOTREACHABLEFORPAGING:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mps_PDP_ActiveNotReachableForPaging->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case PS_SubscriberState_PS_PDP_ACTIVEREACHABLEFORPAGING:
				if(asn1_tag_encode(165, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mps_PDP_ActiveReachableForPaging->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case PS_SubscriberState_NETDETNOTREACHABLE:
				if(asn1_tag_encode(10, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnetDetNotReachable->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int PS_SubscriberState::Display(int tab){
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
			case PS_SubscriberState_NOTPROVIDEDFROMSGSNORMME:
			{
				printf(temp, " ", "notProvidedFromSGSNorMME");
				break;
			}
			case PS_SubscriberState_PS_DETACHED:
			{
				printf(temp, " ", "ps_Detached");
				break;
			}
			case PS_SubscriberState_PS_ATTACHEDNOTREACHABLEFORPAGING:
			{
				printf(temp, " ", "ps_AttachedNotReachableForPaging");
				break;
			}
			case PS_SubscriberState_PS_ATTACHEDREACHABLEFORPAGING:
			{
				printf(temp, " ", "ps_AttachedReachableForPaging");
				break;
			}
			case PS_SubscriberState_PS_PDP_ACTIVENOTREACHABLEFORPAGING:
			{
				printf(temp, " ", "ps_PDP_ActiveNotReachableForPaging");
				if(mps_PDP_ActiveNotReachableForPaging->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PS_SubscriberState_PS_PDP_ACTIVEREACHABLEFORPAGING:
			{
				printf(temp, " ", "ps_PDP_ActiveReachableForPaging");
				if(mps_PDP_ActiveReachableForPaging->Display(tab+1) < 0)
					return -1;
				break;
			}
			case PS_SubscriberState_NETDETNOTREACHABLE:
			{
				printf(temp, " ", "netDetNotReachable");
				if(mnetDetNotReachable->Display(tab+1) < 0)
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

bool PS_SubscriberState::ValidateMandatory(char *errStr){

	return true;
}
PrivateExtension::PrivateExtension()
{
	mextId = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0004};
	mTagOptional = {false};
}

PrivateExtension::~PrivateExtension()
{
	if(mextId != NULL)
		delete mextId;
}

capstd::OctetString* PrivateExtension::setextId(){
	if(mextId == NULL)
	{
		mextId = new capstd::OctetString();
		mTagsPresent |= PrivateExtension_EXTID;
		return mextId;
	}
	else
		return mextId;

}

bool PrivateExtension::setextId(capstd::OctetString* extId){
	if(mextId == NULL)
	{
		return -1;
	}
	else
	{
		mextId = extId;
		return true;
	}

}

capstd::OctetString* PrivateExtension::getextId() {//throw(const char*)
	if(NULL == mextId)
		throw("Object extId is NULL");
	else
		return mextId;
}

bool PrivateExtension::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int PrivateExtension::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X0004:
				if(NULL == this->setextId())
					return -1;
				if(mextId->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: PrivateExtension Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("PrivateExtension: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int PrivateExtension::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("PrivateExtension: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case PrivateExtension_EXTID:
				if(asn1_tag_encode(4, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextId->Encode(array) < 0) || 
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

	return 0;
}

int PrivateExtension::Display(int tab){
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
			case PrivateExtension_EXTID:
			{
				printf(temp, " ", "extId");
				if(mextId->Display(tab+1) < 0)
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

bool PrivateExtension::ValidateMandatory(char *errStr){
	if(NULL == mextId)
	{
		strcpy(errStr, "extId");
		return false;
	}

	return true;
}

PrivateExtensionList::PrivateExtensionList()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 0;
	mParamList.clear();
}

PrivateExtensionList::~PrivateExtensionList()
{
	vector<PrivateExtension *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

PrivateExtension* PrivateExtensionList::getPrivateExtension()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<PrivateExtension *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object PrivateExtension is NULL");
}

PrivateExtension* PrivateExtensionList::getNextPrivateExtension()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<PrivateExtension *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object PrivateExtension is NULL");
}

PrivateExtension* PrivateExtensionList::getPrivateExtensionAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<PrivateExtension *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object PrivateExtension is NULL");
}

unsigned PrivateExtensionList::getNoOfPrivateExtension()
{
	return mParamList.size();
}

bool PrivateExtensionList::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

PrivateExtension* PrivateExtensionList::setNewPrivateExtension()
{
	mPrivateExtension = new PrivateExtension();
	if(NULL == mPrivateExtension)
		return NULL;
	mParamList.push_back(mPrivateExtension);
	mCounter++;
	return mPrivateExtension;
}

PrivateExtension* PrivateExtensionList::setPrivateExtension()
{
	if(NULL == mPrivateExtension)
		return NULL;
	return mPrivateExtension;
}

int PrivateExtensionList::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				this->setNewPrivateExtension();
				if(mPrivateExtension->Decode(array, &bytesDecoded) < 0)
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
int PrivateExtensionList::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<PrivateExtension *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(48, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int PrivateExtensionList::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<PrivateExtension *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "PrivateExtension");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

ReceivingSideID::ReceivingSideID()
{
	mreceivingSideID = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0081};
}

ReceivingSideID::~ReceivingSideID()
{
	if(mreceivingSideID != NULL)
		delete mreceivingSideID;
}

capstd::OctetString* ReceivingSideID::setreceivingSideID(){
if(mParamSet == true)
	{
		if(mreceivingSideID != NULL)
			return mreceivingSideID;
		else
			return NULL;
	}
	if(mreceivingSideID == NULL)
	{
		mreceivingSideID = new capstd::OctetString(1, 1);
		mTagsPresent |= ReceivingSideID_RECEIVINGSIDEID;
		mParamSet = true;
		return mreceivingSideID;
	}
}

bool ReceivingSideID::setreceivingSideID(capstd::OctetString* receivingSideID){
	if(mreceivingSideID == NULL)
	{
		return -1;
	}
	else
	{
		mreceivingSideID = receivingSideID;
		return true;
	}

}

capstd::OctetString* ReceivingSideID::getreceivingSideID() {//throw(const char*)
	if(NULL == mreceivingSideID)
		throw("Object receivingSideID is NULL");
	else
		return mreceivingSideID;
}

bool ReceivingSideID::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ReceivingSideID::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0081:
				if(NULL == this->setreceivingSideID())
					return -1;
				if(mreceivingSideID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: ReceivingSideID Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ReceivingSideID: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ReceivingSideID::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ReceivingSideID: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ReceivingSideID_RECEIVINGSIDEID:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreceivingSideID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int ReceivingSideID::Display(int tab){
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
			case ReceivingSideID_RECEIVINGSIDEID:
			{
				printf(temp, " ", "receivingSideID");
				if(mreceivingSideID->Display(tab+1) < 0)
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

bool ReceivingSideID::ValidateMandatory(char *errStr){

	return true;
}
RequestedInfo::RequestedInfo()
{
	mlocationInformation = false;
	msubscriberState = false;
	mextensionContainer = NULL;
	mcurrentLocation = false;
	mrequestedDomain = NULL;
	mimei = false;
	mms_classmark = false;
	mmnpRequestedInfo = false;
	mt_adsData = false;
	mrequestedNodes = NULL;
	mservingNodeIndication = false;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X00A2, 0X0083, 0X0084, 0X0086, 0X0085, 0X0087, 0X0088, 0X0089, 0X008A};
	mTagOptional = {true, true, true, true, true, true, true, true, true, true, true};
}

RequestedInfo::~RequestedInfo()
{
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mrequestedDomain != NULL)
		delete mrequestedDomain;
	if(mrequestedNodes != NULL)
		delete mrequestedNodes;
}

bool* RequestedInfo::setlocationInformation(){
	mlocationInformation = true;
	mTagsPresent |= RequestedInfo_LOCATIONINFORMATION;
	mNulllocationInformation = true;
	return &mNulllocationInformation;
}

bool RequestedInfo::setlocationInformation(bool locationInformation){
	mlocationInformation = locationInformation;
	return true;
}

bool* RequestedInfo::setsubscriberState(){
	msubscriberState = true;
	mTagsPresent |= RequestedInfo_SUBSCRIBERSTATE;
	mNullsubscriberState = true;
	return &mNullsubscriberState;
}

bool RequestedInfo::setsubscriberState(bool subscriberState){
	msubscriberState = subscriberState;
	return true;
}

capstd::GENERIC* RequestedInfo::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= RequestedInfo_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool RequestedInfo::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

bool* RequestedInfo::setcurrentLocation(){
	mcurrentLocation = true;
	mTagsPresent |= RequestedInfo_CURRENTLOCATION;
	mNullcurrentLocation = true;
	return &mNullcurrentLocation;
}

bool RequestedInfo::setcurrentLocation(bool currentLocation){
	mcurrentLocation = currentLocation;
	return true;
}

DomainType* RequestedInfo::setrequestedDomain(){
	if(mrequestedDomain == NULL)
	{
		mrequestedDomain = new DomainType();
		mTagsPresent |= RequestedInfo_REQUESTEDDOMAIN;
		return mrequestedDomain;
	}
	else
		return mrequestedDomain;

}

bool RequestedInfo::setrequestedDomain(DomainType* requestedDomain){
	if(mrequestedDomain == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedDomain = requestedDomain;
		return true;
	}

}

bool* RequestedInfo::setimei(){
	mimei = true;
	mTagsPresent |= RequestedInfo_IMEI;
	mNullimei = true;
	return &mNullimei;
}

bool RequestedInfo::setimei(bool imei){
	mimei = imei;
	return true;
}

bool* RequestedInfo::setms_classmark(){
	mms_classmark = true;
	mTagsPresent |= RequestedInfo_MS_CLASSMARK;
	mNullms_classmark = true;
	return &mNullms_classmark;
}

bool RequestedInfo::setms_classmark(bool ms_classmark){
	mms_classmark = ms_classmark;
	return true;
}

bool* RequestedInfo::setmnpRequestedInfo(){
	mmnpRequestedInfo = true;
	mTagsPresent |= RequestedInfo_MNPREQUESTEDINFO;
	mNullmnpRequestedInfo = true;
	return &mNullmnpRequestedInfo;
}

bool RequestedInfo::setmnpRequestedInfo(bool mnpRequestedInfo){
	mmnpRequestedInfo = mnpRequestedInfo;
	return true;
}

bool* RequestedInfo::sett_adsData(){
	mt_adsData = true;
	mTagsPresent |= RequestedInfo_T_ADSDATA;
	mNullt_adsData = true;
	return &mNullt_adsData;
}

bool RequestedInfo::sett_adsData(bool t_adsData){
	mt_adsData = t_adsData;
	return true;
}

RequestedNodes* RequestedInfo::setrequestedNodes(){
	if(mrequestedNodes == NULL)
	{
		mrequestedNodes = new RequestedNodes();
		mTagsPresent |= RequestedInfo_REQUESTEDNODES;
		return mrequestedNodes;
	}
	else
		return mrequestedNodes;

}

bool RequestedInfo::setrequestedNodes(RequestedNodes* requestedNodes){
	if(mrequestedNodes == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedNodes = requestedNodes;
		return true;
	}

}

bool* RequestedInfo::setservingNodeIndication(){
	mservingNodeIndication = true;
	mTagsPresent |= RequestedInfo_SERVINGNODEINDICATION;
	mNullservingNodeIndication = true;
	return &mNullservingNodeIndication;
}

bool RequestedInfo::setservingNodeIndication(bool servingNodeIndication){
	mservingNodeIndication = servingNodeIndication;
	return true;
}

bool RequestedInfo::getlocationInformation() {
	return mlocationInformation;
}

bool RequestedInfo::getsubscriberState() {
	return msubscriberState;
}

capstd::GENERIC* RequestedInfo::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

bool RequestedInfo::getcurrentLocation() {
	return mcurrentLocation;
}

DomainType* RequestedInfo::getrequestedDomain() {//throw(const char*)
	if(NULL == mrequestedDomain)
		throw("Object requestedDomain is NULL");
	else
		return mrequestedDomain;
}

bool RequestedInfo::getimei() {
	return mimei;
}

bool RequestedInfo::getms_classmark() {
	return mms_classmark;
}

bool RequestedInfo::getmnpRequestedInfo() {
	return mmnpRequestedInfo;
}

bool RequestedInfo::gett_adsData() {
	return mt_adsData;
}

RequestedNodes* RequestedInfo::getrequestedNodes() {//throw(const char*)
	if(NULL == mrequestedNodes)
		throw("Object requestedNodes is NULL");
	else
		return mrequestedNodes;
}

bool RequestedInfo::getservingNodeIndication() {
	return mservingNodeIndication;
}

bool RequestedInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int RequestedInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setlocationInformation())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setsubscriberState())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, RequestedInfo_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setcurrentLocation())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setrequestedDomain())
					return -1;
				if(mrequestedDomain->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setimei())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setms_classmark())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0087:
				if(NULL == this->setmnpRequestedInfo())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0088:
				if(NULL == this->sett_adsData())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setrequestedNodes())
					return -1;
				if(mrequestedNodes->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setservingNodeIndication())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: RequestedInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("RequestedInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int RequestedInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("RequestedInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case RequestedInfo_LOCATIONINFORMATION:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_SUBSCRIBERSTATE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_EXTENSIONCONTAINER:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case RequestedInfo_CURRENTLOCATION:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_REQUESTEDDOMAIN:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedDomain->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case RequestedInfo_IMEI:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_MS_CLASSMARK:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_MNPREQUESTEDINFO:
				if(asn1_tag_encode(135, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_T_ADSDATA:
				if(asn1_tag_encode(136, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case RequestedInfo_REQUESTEDNODES:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedNodes->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case RequestedInfo_SERVINGNODEINDICATION:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				asn1_null_encode(array);
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

	return 0;
}

int RequestedInfo::Display(int tab){
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
			case RequestedInfo_LOCATIONINFORMATION:
			{
				printf(temp, " ", "locationInformation");
				break;
			}
			case RequestedInfo_SUBSCRIBERSTATE:
			{
				printf(temp, " ", "subscriberState");
				break;
			}
			case RequestedInfo_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInfo_CURRENTLOCATION:
			{
				printf(temp, " ", "currentLocation");
				break;
			}
			case RequestedInfo_REQUESTEDDOMAIN:
			{
				printf(temp, " ", "requestedDomain");
				if(mrequestedDomain->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInfo_IMEI:
			{
				printf(temp, " ", "imei");
				break;
			}
			case RequestedInfo_MS_CLASSMARK:
			{
				printf(temp, " ", "ms_classmark");
				break;
			}
			case RequestedInfo_MNPREQUESTEDINFO:
			{
				printf(temp, " ", "mnpRequestedInfo");
				break;
			}
			case RequestedInfo_T_ADSDATA:
			{
				printf(temp, " ", "t_adsData");
				break;
			}
			case RequestedInfo_REQUESTEDNODES:
			{
				printf(temp, " ", "requestedNodes");
				if(mrequestedNodes->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInfo_SERVINGNODEINDICATION:
			{
				printf(temp, " ", "servingNodeIndication");
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

bool RequestedInfo::ValidateMandatory(char *errStr){

	return true;
}
RequestedInformation::RequestedInformation()
{
	mrequestedInformationType = NULL;
	mrequestedInformationValue = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X00A1};
	mTagOptional = {false, false};
}

RequestedInformation::~RequestedInformation()
{
	if(mrequestedInformationType != NULL)
		delete mrequestedInformationType;
	if(mrequestedInformationValue != NULL)
		delete mrequestedInformationValue;
}

RequestedInformationType* RequestedInformation::setrequestedInformationType(){
	if(mrequestedInformationType == NULL)
	{
		mrequestedInformationType = new RequestedInformationType();
		mTagsPresent |= RequestedInformation_REQUESTEDINFORMATIONTYPE;
		return mrequestedInformationType;
	}
	else
		return mrequestedInformationType;

}

bool RequestedInformation::setrequestedInformationType(RequestedInformationType* requestedInformationType){
	if(mrequestedInformationType == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedInformationType = requestedInformationType;
		return true;
	}

}

RequestedInformationValue* RequestedInformation::setrequestedInformationValue(){
	if(mrequestedInformationValue == NULL)
	{
		mrequestedInformationValue = new RequestedInformationValue();
		mTagsPresent |= RequestedInformation_REQUESTEDINFORMATIONVALUE;
		return mrequestedInformationValue;
	}
	else
		return mrequestedInformationValue;

}

bool RequestedInformation::setrequestedInformationValue(RequestedInformationValue* requestedInformationValue){
	if(mrequestedInformationValue == NULL)
	{
		return -1;
	}
	else
	{
		mrequestedInformationValue = requestedInformationValue;
		return true;
	}

}

RequestedInformationType* RequestedInformation::getrequestedInformationType() {//throw(const char*)
	if(NULL == mrequestedInformationType)
		throw("Object requestedInformationType is NULL");
	else
		return mrequestedInformationType;
}

RequestedInformationValue* RequestedInformation::getrequestedInformationValue() {//throw(const char*)
	if(NULL == mrequestedInformationValue)
		throw("Object requestedInformationValue is NULL");
	else
		return mrequestedInformationValue;
}

bool RequestedInformation::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int RequestedInformation::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setrequestedInformationType())
					return -1;
				if(mrequestedInformationType->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setrequestedInformationValue())
					return -1;
				if(mrequestedInformationValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: RequestedInformation Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("RequestedInformation: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int RequestedInformation::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("RequestedInformation: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case RequestedInformation_REQUESTEDINFORMATIONTYPE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedInformationType->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case RequestedInformation_REQUESTEDINFORMATIONVALUE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mrequestedInformationValue->Encode(array) < 0) || 
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

	return 0;
}

int RequestedInformation::Display(int tab){
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
			case RequestedInformation_REQUESTEDINFORMATIONTYPE:
			{
				printf(temp, " ", "requestedInformationType");
				if(mrequestedInformationType->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInformation_REQUESTEDINFORMATIONVALUE:
			{
				printf(temp, " ", "requestedInformationValue");
				if(mrequestedInformationValue->Display(tab+1) < 0)
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

bool RequestedInformation::ValidateMandatory(char *errStr){
	if(NULL == mrequestedInformationType)
	{
		strcpy(errStr, "requestedInformationType");
		return false;
	}
	else if(NULL == mrequestedInformationValue)
	{
		strcpy(errStr, "requestedInformationValue");
		return false;
	}

	return true;
}

RequestedInformationList::RequestedInformationList()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 0;
	mParamList.clear();
}

RequestedInformationList::~RequestedInformationList()
{
	vector<RequestedInformation *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

RequestedInformation* RequestedInformationList::getRequestedInformation()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<RequestedInformation *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object RequestedInformation is NULL");
}

RequestedInformation* RequestedInformationList::getNextRequestedInformation()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<RequestedInformation *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object RequestedInformation is NULL");
}

RequestedInformation* RequestedInformationList::getRequestedInformationAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<RequestedInformation *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object RequestedInformation is NULL");
}

unsigned RequestedInformationList::getNoOfRequestedInformation()
{
	return mParamList.size();
}

bool RequestedInformationList::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

RequestedInformation* RequestedInformationList::setNewRequestedInformation()
{
	mRequestedInformation = new RequestedInformation();
	if(NULL == mRequestedInformation)
		return NULL;
	mParamList.push_back(mRequestedInformation);
	mCounter++;
	return mRequestedInformation;
}

RequestedInformation* RequestedInformationList::setRequestedInformation()
{
	if(NULL == mRequestedInformation)
		return NULL;
	return mRequestedInformation;
}

int RequestedInformationList::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				this->setNewRequestedInformation();
				if(mRequestedInformation->Decode(array, &bytesDecoded) < 0)
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
int RequestedInformationList::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<RequestedInformation *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(48, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int RequestedInformationList::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<RequestedInformation *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "RequestedInformation");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}


RequestedInformationType::RequestedInformationType()
{
	mTag = 0X000A;
}

RequestedInformationType::~RequestedInformationType()
{
}

bool RequestedInformationType::setValue(REQUESTEDINFORMATIONTYPE val)
{
	mValue = val;
	return true;
}

REQUESTEDINFORMATIONTYPE RequestedInformationType::getValue()
{
	return mValue;
}

int RequestedInformationType::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (REQUESTEDINFORMATIONTYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int RequestedInformationType::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int RequestedInformationType::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", REQUESTEDINFORMATIONTYPE_str(mValue), mValue);
	return 0;
}


RequestedInformationTypeList::RequestedInformationTypeList()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 0;
	mParamList.clear();
}

RequestedInformationTypeList::~RequestedInformationTypeList()
{
	vector<RequestedInformationType *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

RequestedInformationType* RequestedInformationTypeList::getRequestedInformationType()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<RequestedInformationType *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object RequestedInformationType is NULL");
}

RequestedInformationType* RequestedInformationTypeList::getNextRequestedInformationType()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<RequestedInformationType *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object RequestedInformationType is NULL");
}

RequestedInformationType* RequestedInformationTypeList::getRequestedInformationTypeAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<RequestedInformationType *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object RequestedInformationType is NULL");
}

unsigned RequestedInformationTypeList::getNoOfRequestedInformationType()
{
	return mParamList.size();
}

bool RequestedInformationTypeList::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

RequestedInformationType* RequestedInformationTypeList::setNewRequestedInformationType()
{
	mRequestedInformationType = new RequestedInformationType();
	if(NULL == mRequestedInformationType)
		return NULL;
	mParamList.push_back(mRequestedInformationType);
	mCounter++;
	return mRequestedInformationType;
}

RequestedInformationType* RequestedInformationTypeList::setRequestedInformationType()
{
	if(NULL == mRequestedInformationType)
		return NULL;
	return mRequestedInformationType;
}

int RequestedInformationTypeList::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X000A:
				this->setNewRequestedInformationType();
				if(mRequestedInformationType->Decode(array, &bytesDecoded) < 0)
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
int RequestedInformationTypeList::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<RequestedInformationType *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(10, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int RequestedInformationTypeList::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<RequestedInformationType *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "RequestedInformationType");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

RequestedInformationValue::RequestedInformationValue()
{
	mcallAttemptElapsedTimeValue = NULL;
	mcallStopTimeValue = NULL;
	mcallConnectedElapsedTimeValue = NULL;
	mreleaseCauseValue = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X009E};
}

RequestedInformationValue::~RequestedInformationValue()
{
	if(mcallAttemptElapsedTimeValue != NULL)
		delete mcallAttemptElapsedTimeValue;
	if(mcallStopTimeValue != NULL)
		delete mcallStopTimeValue;
	if(mcallConnectedElapsedTimeValue != NULL)
		delete mcallConnectedElapsedTimeValue;
	if(mreleaseCauseValue != NULL)
		delete mreleaseCauseValue;
}

capstd::INTEGER* RequestedInformationValue::setcallAttemptElapsedTimeValue(){
if(mParamSet == true)
	{
		if(mcallAttemptElapsedTimeValue != NULL)
			return mcallAttemptElapsedTimeValue;
		else
			return NULL;
	}
	if(mcallAttemptElapsedTimeValue == NULL)
	{
		mcallAttemptElapsedTimeValue = new capstd::INTEGER(0, 255);
		mTagsPresent |= RequestedInformationValue_CALLATTEMPTELAPSEDTIMEVALUE;
		mParamSet = true;
		return mcallAttemptElapsedTimeValue;
	}
}

bool RequestedInformationValue::setcallAttemptElapsedTimeValue(capstd::INTEGER* callAttemptElapsedTimeValue){
	if(mcallAttemptElapsedTimeValue == NULL)
	{
		return -1;
	}
	else
	{
		mcallAttemptElapsedTimeValue = callAttemptElapsedTimeValue;
		return true;
	}

}

capstd::DateAndTime* RequestedInformationValue::setcallStopTimeValue(){
if(mParamSet == true)
	{
		if(mcallStopTimeValue != NULL)
			return mcallStopTimeValue;
		else
			return NULL;
	}
	if(mcallStopTimeValue == NULL)
	{
		mcallStopTimeValue = new capstd::DateAndTime();
		mTagsPresent |= RequestedInformationValue_CALLSTOPTIMEVALUE;
		mParamSet = true;
		return mcallStopTimeValue;
	}
}

bool RequestedInformationValue::setcallStopTimeValue(capstd::DateAndTime* callStopTimeValue){
	if(mcallStopTimeValue == NULL)
	{
		return -1;
	}
	else
	{
		mcallStopTimeValue = callStopTimeValue;
		return true;
	}

}

capstd::INTEGER* RequestedInformationValue::setcallConnectedElapsedTimeValue(){
if(mParamSet == true)
	{
		if(mcallConnectedElapsedTimeValue != NULL)
			return mcallConnectedElapsedTimeValue;
		else
			return NULL;
	}
	if(mcallConnectedElapsedTimeValue == NULL)
	{
		mcallConnectedElapsedTimeValue = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= RequestedInformationValue_CALLCONNECTEDELAPSEDTIMEVALUE;
		mParamSet = true;
		return mcallConnectedElapsedTimeValue;
	}
}

bool RequestedInformationValue::setcallConnectedElapsedTimeValue(capstd::INTEGER* callConnectedElapsedTimeValue){
	if(mcallConnectedElapsedTimeValue == NULL)
	{
		return -1;
	}
	else
	{
		mcallConnectedElapsedTimeValue = callConnectedElapsedTimeValue;
		return true;
	}

}

capstd::GENERIC* RequestedInformationValue::setreleaseCauseValue(){
if(mParamSet == true)
	{
		if(mreleaseCauseValue != NULL)
			return mreleaseCauseValue;
		else
			return NULL;
	}
	if(mreleaseCauseValue == NULL)
	{
		mreleaseCauseValue = new capstd::GENERIC();
		mTagsPresent |= RequestedInformationValue_RELEASECAUSEVALUE;
		mParamSet = true;
		return mreleaseCauseValue;
	}
}

bool RequestedInformationValue::setreleaseCauseValue(capstd::GENERIC* releaseCauseValue){
	if(mreleaseCauseValue == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseCauseValue = releaseCauseValue;
		return true;
	}

}

capstd::INTEGER* RequestedInformationValue::getcallAttemptElapsedTimeValue() {//throw(const char*)
	if(NULL == mcallAttemptElapsedTimeValue)
		throw("Object callAttemptElapsedTimeValue is NULL");
	else
		return mcallAttemptElapsedTimeValue;
}

capstd::DateAndTime* RequestedInformationValue::getcallStopTimeValue() {//throw(const char*)
	if(NULL == mcallStopTimeValue)
		throw("Object callStopTimeValue is NULL");
	else
		return mcallStopTimeValue;
}

capstd::INTEGER* RequestedInformationValue::getcallConnectedElapsedTimeValue() {//throw(const char*)
	if(NULL == mcallConnectedElapsedTimeValue)
		throw("Object callConnectedElapsedTimeValue is NULL");
	else
		return mcallConnectedElapsedTimeValue;
}

capstd::GENERIC* RequestedInformationValue::getreleaseCauseValue() {//throw(const char*)
	if(NULL == mreleaseCauseValue)
		throw("Object releaseCauseValue is NULL");
	else
		return mreleaseCauseValue;
}

bool RequestedInformationValue::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int RequestedInformationValue::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setcallAttemptElapsedTimeValue())
					return -1;
				if(mcallAttemptElapsedTimeValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setcallStopTimeValue())
					return -1;
				if(mcallStopTimeValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0082:
				if(NULL == this->setcallConnectedElapsedTimeValue())
					return -1;
				if(mcallConnectedElapsedTimeValue->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X009E:
				if(NULL == this->setreleaseCauseValue())
					return -1;
				if(mreleaseCauseValue->Decode(array, &bytesDecoded, mTagArray, RequestedInformationValue_RELEASECAUSEVALUE) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: RequestedInformationValue Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("RequestedInformationValue: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int RequestedInformationValue::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("RequestedInformationValue: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case RequestedInformationValue_CALLATTEMPTELAPSEDTIMEVALUE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallAttemptElapsedTimeValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case RequestedInformationValue_CALLSTOPTIMEVALUE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallStopTimeValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case RequestedInformationValue_CALLCONNECTEDELAPSEDTIMEVALUE:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallConnectedElapsedTimeValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case RequestedInformationValue_RELEASECAUSEVALUE:
				if(asn1_tag_encode(158, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseCauseValue->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int RequestedInformationValue::Display(int tab){
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
			case RequestedInformationValue_CALLATTEMPTELAPSEDTIMEVALUE:
			{
				printf(temp, " ", "callAttemptElapsedTimeValue");
				if(mcallAttemptElapsedTimeValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInformationValue_CALLSTOPTIMEVALUE:
			{
				printf(temp, " ", "callStopTimeValue");
				if(mcallStopTimeValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInformationValue_CALLCONNECTEDELAPSEDTIMEVALUE:
			{
				printf(temp, " ", "callConnectedElapsedTimeValue");
				if(mcallConnectedElapsedTimeValue->Display(tab+1) < 0)
					return -1;
				break;
			}
			case RequestedInformationValue_RELEASECAUSEVALUE:
			{
				printf(temp, " ", "releaseCauseValue");
				if(mreleaseCauseValue->Display(tab+1) < 0)
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

bool RequestedInformationValue::ValidateMandatory(char *errStr){

	return true;
}

RequestedNodes::RequestedNodes()
{
	mTag = 0X0003;
	mLength = 0;
	minSize = 8;
	maxSize = 8;
}


RequestedNodes::RequestedNodes(int min, int max):minSize(min), maxSize(max)
{
	mTag = 0X0003;
	mLength = 0;
}

RequestedNodes::~RequestedNodes()
{
	if(mValue != NULL)
		delete mValue;
}

bool RequestedNodes::setMme()
{
	if(mValue == NULL)
	{
		int size = sizeof(_RequestedNodes);
		mValue = new char[(size > maxSize/8)?size:(maxSize/8)];
	}
	else
	{
		_RequestedNodes *lValue = (_RequestedNodes*)mValue;
		lValue->mme = 1;
	}
}
bool RequestedNodes::setSgsn()
{
	if(mValue == NULL)
	{
		int size = sizeof(_RequestedNodes);
		mValue = new char[(size > maxSize/8)?size:(maxSize/8)];
	}
	else
	{
		_RequestedNodes *lValue = (_RequestedNodes*)mValue;
		lValue->sgsn = 1;
	}
}
bool RequestedNodes::isSetMme()
{
	if(mValue == NULL)
		return false;

	_RequestedNodes *lValue = (_RequestedNodes*)mValue;
	return lValue->mme;
}
bool RequestedNodes::isSetSgsn()
{
	if(mValue == NULL)
		return false;

	_RequestedNodes *lValue = (_RequestedNodes*)mValue;
	return lValue->sgsn;
}

int RequestedNodes::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	/* First octet is number of bits not used in last octet
	 Value of this is in the range of 0 to 7*/
	mUnUsedBits = asn1_get_octet(array);
	mLength = length;
	mValue = new char[sizeof(_RequestedNodes) > length?sizeof(_RequestedNodes):length];
	memcpy(mValue, (array->byte + array->offset), length - 1);
	array->offset += length - 1;
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int RequestedNodes::Encode(capstd::byteArray* array){
	if(mValue == NULL)
		mValue = new char[sizeof(_RequestedNodes) > mLength?sizeof(_RequestedNodes):mLength];
	array->byte[array->offset++] = mLength;
	array->byte[array->offset++] = mUnUsedBits;
	memcpy((array->byte + array->offset), mValue, mLength - 1);
	array->offset += mLength - 1;
	array->size += 1 + mLength;
	return 0;
}
int RequestedNodes::Display(int tab){
	char temp[30];
	char temp1[30];
	sprintf(temp, "%%%ds %%s %%s\n", tab * 3);
	sprintf(temp1, "UnUsedBits :  %d", mUnUsedBits);

	printf(temp, " ", temp1, " ");

	if(NULL == mValue){
		printf("Value is NULL\n");
		return 0;
	}
	printf(temp, " ", "Mme   : ", isSetMme()?"Yes":"No");
	printf(temp, " ", "Sgsn   : ", isSetSgsn()?"Yes":"No");
	return 0;
}

ResourceAddress::ResourceAddress()
{
	mipRoutingAddress = NULL;
	mnone = false;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0083};
}

ResourceAddress::~ResourceAddress()
{
	if(mipRoutingAddress != NULL)
		delete mipRoutingAddress;
}

capstd::OctetString* ResourceAddress::setipRoutingAddress(){
if(mParamSet == true)
	{
		if(mipRoutingAddress != NULL)
			return mipRoutingAddress;
		else
			return NULL;
	}
	if(mipRoutingAddress == NULL)
	{
		mipRoutingAddress = new capstd::OctetString(2, 18);
		mTagsPresent |= ResourceAddress_IPROUTINGADDRESS;
		mParamSet = true;
		return mipRoutingAddress;
	}
}

bool ResourceAddress::setipRoutingAddress(capstd::OctetString* ipRoutingAddress){
	if(mipRoutingAddress == NULL)
	{
		return -1;
	}
	else
	{
		mipRoutingAddress = ipRoutingAddress;
		return true;
	}

}

bool* ResourceAddress::setnone(){
if(mParamSet == true)
	{
		if(mNullnone == true)
			return &mnone;
		else
			return NULL;
	}
	mTagsPresent |= ResourceAddress_NONE;
		mParamSet = true;
	mNullnone = true;
	return &mNullnone;
}

bool ResourceAddress::setnone(bool none){
	mnone = none;
	return true;
}

capstd::OctetString* ResourceAddress::getipRoutingAddress() {//throw(const char*)
	if(NULL == mipRoutingAddress)
		throw("Object ipRoutingAddress is NULL");
	else
		return mipRoutingAddress;
}

bool ResourceAddress::getnone() {
	return mnone;
}

bool ResourceAddress::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ResourceAddress::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setipRoutingAddress())
					return -1;
				if(mipRoutingAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0083:
				if(NULL == this->setnone())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: ResourceAddress Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ResourceAddress: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ResourceAddress::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ResourceAddress: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ResourceAddress_IPROUTINGADDRESS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mipRoutingAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case ResourceAddress_NONE:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
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

	return 0;
}

int ResourceAddress::Display(int tab){
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
			case ResourceAddress_IPROUTINGADDRESS:
			{
				printf(temp, " ", "ipRoutingAddress");
				if(mipRoutingAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ResourceAddress_NONE:
			{
				printf(temp, " ", "none");
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

bool ResourceAddress::ValidateMandatory(char *errStr){

	return true;
}
RouteSelectFailureSpecificInfo::RouteSelectFailureSpecificInfo()
{
	mfailureCause = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {true};
}

RouteSelectFailureSpecificInfo::~RouteSelectFailureSpecificInfo()
{
	if(mfailureCause != NULL)
		delete mfailureCause;
}

capstd::GENERIC* RouteSelectFailureSpecificInfo::setfailureCause(){
	if(mfailureCause == NULL)
	{
		mfailureCause = new capstd::GENERIC();
		mTagsPresent |= RouteSelectFailureSpecificInfo_FAILURECAUSE;
		return mfailureCause;
	}
	else
		return mfailureCause;

}

bool RouteSelectFailureSpecificInfo::setfailureCause(capstd::GENERIC* failureCause){
	if(mfailureCause == NULL)
	{
		return -1;
	}
	else
	{
		mfailureCause = failureCause;
		return true;
	}

}

capstd::GENERIC* RouteSelectFailureSpecificInfo::getfailureCause() {//throw(const char*)
	if(NULL == mfailureCause)
		throw("Object failureCause is NULL");
	else
		return mfailureCause;
}

bool RouteSelectFailureSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int RouteSelectFailureSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setfailureCause())
					return -1;
				if(mfailureCause->Decode(array, &bytesDecoded, mTagArray, RouteSelectFailureSpecificInfo_FAILURECAUSE) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: RouteSelectFailureSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("RouteSelectFailureSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int RouteSelectFailureSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("RouteSelectFailureSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case RouteSelectFailureSpecificInfo_FAILURECAUSE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mfailureCause->Encode(array) < 0) || 
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

	return 0;
}

int RouteSelectFailureSpecificInfo::Display(int tab){
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
			case RouteSelectFailureSpecificInfo_FAILURECAUSE:
			{
				printf(temp, " ", "failureCause");
				if(mfailureCause->Display(tab+1) < 0)
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

bool RouteSelectFailureSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
SendingSideID::SendingSideID()
{
	msendingSideID = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080};
}

SendingSideID::~SendingSideID()
{
	if(msendingSideID != NULL)
		delete msendingSideID;
}

capstd::OctetString* SendingSideID::setsendingSideID(){
if(mParamSet == true)
	{
		if(msendingSideID != NULL)
			return msendingSideID;
		else
			return NULL;
	}
	if(msendingSideID == NULL)
	{
		msendingSideID = new capstd::OctetString(1, 1);
		mTagsPresent |= SendingSideID_SENDINGSIDEID;
		mParamSet = true;
		return msendingSideID;
	}
}

bool SendingSideID::setsendingSideID(capstd::OctetString* sendingSideID){
	if(msendingSideID == NULL)
	{
		return -1;
	}
	else
	{
		msendingSideID = sendingSideID;
		return true;
	}

}

capstd::OctetString* SendingSideID::getsendingSideID() {//throw(const char*)
	if(NULL == msendingSideID)
		throw("Object sendingSideID is NULL");
	else
		return msendingSideID;
}

bool SendingSideID::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SendingSideID::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setsendingSideID())
					return -1;
				if(msendingSideID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: SendingSideID Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SendingSideID: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SendingSideID::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SendingSideID: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SendingSideID_SENDINGSIDEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msendingSideID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int SendingSideID::Display(int tab){
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
			case SendingSideID_SENDINGSIDEID:
			{
				printf(temp, " ", "sendingSideID");
				if(msendingSideID->Display(tab+1) < 0)
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

bool SendingSideID::ValidateMandatory(char *errStr){

	return true;
}
ServiceInteractionIndicatorsTwo::ServiceInteractionIndicatorsTwo()
{
	mforwardServiceInteractionInd = NULL;
	mbackwardServiceInteractionInd = NULL;
	mbothwayThroughConnectionInd = NULL;
	mconnectedNumberTreatmentInd = NULL;
	mnonCUGCall = false;
	mholdTreatmentIndicator = NULL;
	mcwTreatmentIndicator = NULL;
	mectTreatmentIndicator = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1, 0X0082, 0X0084, 0X008D, 0X9F32, 0X9F33, 0X9F34};
	mTagOptional = {true, true, true, true, true, true, true, true};
}

ServiceInteractionIndicatorsTwo::~ServiceInteractionIndicatorsTwo()
{
	if(mforwardServiceInteractionInd != NULL)
		delete mforwardServiceInteractionInd;
	if(mbackwardServiceInteractionInd != NULL)
		delete mbackwardServiceInteractionInd;
	if(mbothwayThroughConnectionInd != NULL)
		delete mbothwayThroughConnectionInd;
	if(mconnectedNumberTreatmentInd != NULL)
		delete mconnectedNumberTreatmentInd;
	if(mholdTreatmentIndicator != NULL)
		delete mholdTreatmentIndicator;
	if(mcwTreatmentIndicator != NULL)
		delete mcwTreatmentIndicator;
	if(mectTreatmentIndicator != NULL)
		delete mectTreatmentIndicator;
}

ForwardServiceInteractionInd* ServiceInteractionIndicatorsTwo::setforwardServiceInteractionInd(){
	if(mforwardServiceInteractionInd == NULL)
	{
		mforwardServiceInteractionInd = new ForwardServiceInteractionInd();
		mTagsPresent |= ServiceInteractionIndicatorsTwo_FORWARDSERVICEINTERACTIONIND;
		return mforwardServiceInteractionInd;
	}
	else
		return mforwardServiceInteractionInd;

}

bool ServiceInteractionIndicatorsTwo::setforwardServiceInteractionInd(ForwardServiceInteractionInd* forwardServiceInteractionInd){
	if(mforwardServiceInteractionInd == NULL)
	{
		return -1;
	}
	else
	{
		mforwardServiceInteractionInd = forwardServiceInteractionInd;
		return true;
	}

}

BackwardServiceInteractionInd* ServiceInteractionIndicatorsTwo::setbackwardServiceInteractionInd(){
	if(mbackwardServiceInteractionInd == NULL)
	{
		mbackwardServiceInteractionInd = new BackwardServiceInteractionInd();
		mTagsPresent |= ServiceInteractionIndicatorsTwo_BACKWARDSERVICEINTERACTIONIND;
		return mbackwardServiceInteractionInd;
	}
	else
		return mbackwardServiceInteractionInd;

}

bool ServiceInteractionIndicatorsTwo::setbackwardServiceInteractionInd(BackwardServiceInteractionInd* backwardServiceInteractionInd){
	if(mbackwardServiceInteractionInd == NULL)
	{
		return -1;
	}
	else
	{
		mbackwardServiceInteractionInd = backwardServiceInteractionInd;
		return true;
	}

}

BothwayThroughConnectionInd* ServiceInteractionIndicatorsTwo::setbothwayThroughConnectionInd(){
	if(mbothwayThroughConnectionInd == NULL)
	{
		mbothwayThroughConnectionInd = new BothwayThroughConnectionInd();
		mTagsPresent |= ServiceInteractionIndicatorsTwo_BOTHWAYTHROUGHCONNECTIONIND;
		return mbothwayThroughConnectionInd;
	}
	else
		return mbothwayThroughConnectionInd;

}

bool ServiceInteractionIndicatorsTwo::setbothwayThroughConnectionInd(BothwayThroughConnectionInd* bothwayThroughConnectionInd){
	if(mbothwayThroughConnectionInd == NULL)
	{
		return -1;
	}
	else
	{
		mbothwayThroughConnectionInd = bothwayThroughConnectionInd;
		return true;
	}

}

ConnectedNumberTreatmentInd* ServiceInteractionIndicatorsTwo::setconnectedNumberTreatmentInd(){
	if(mconnectedNumberTreatmentInd == NULL)
	{
		mconnectedNumberTreatmentInd = new ConnectedNumberTreatmentInd();
		mTagsPresent |= ServiceInteractionIndicatorsTwo_CONNECTEDNUMBERTREATMENTIND;
		return mconnectedNumberTreatmentInd;
	}
	else
		return mconnectedNumberTreatmentInd;

}

bool ServiceInteractionIndicatorsTwo::setconnectedNumberTreatmentInd(ConnectedNumberTreatmentInd* connectedNumberTreatmentInd){
	if(mconnectedNumberTreatmentInd == NULL)
	{
		return -1;
	}
	else
	{
		mconnectedNumberTreatmentInd = connectedNumberTreatmentInd;
		return true;
	}

}

bool* ServiceInteractionIndicatorsTwo::setnonCUGCall(){
	mnonCUGCall = true;
	mTagsPresent |= ServiceInteractionIndicatorsTwo_NONCUGCALL;
	mNullnonCUGCall = true;
	return &mNullnonCUGCall;
}

bool ServiceInteractionIndicatorsTwo::setnonCUGCall(bool nonCUGCall){
	mnonCUGCall = nonCUGCall;
	return true;
}

capstd::OctetString* ServiceInteractionIndicatorsTwo::setholdTreatmentIndicator(){
	if(mholdTreatmentIndicator == NULL)
	{
		mholdTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ServiceInteractionIndicatorsTwo_HOLDTREATMENTINDICATOR;
		return mholdTreatmentIndicator;
	}
	else
		return mholdTreatmentIndicator;

}

bool ServiceInteractionIndicatorsTwo::setholdTreatmentIndicator(capstd::OctetString* holdTreatmentIndicator){
	if(mholdTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mholdTreatmentIndicator = holdTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* ServiceInteractionIndicatorsTwo::setcwTreatmentIndicator(){
	if(mcwTreatmentIndicator == NULL)
	{
		mcwTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ServiceInteractionIndicatorsTwo_CWTREATMENTINDICATOR;
		return mcwTreatmentIndicator;
	}
	else
		return mcwTreatmentIndicator;

}

bool ServiceInteractionIndicatorsTwo::setcwTreatmentIndicator(capstd::OctetString* cwTreatmentIndicator){
	if(mcwTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mcwTreatmentIndicator = cwTreatmentIndicator;
		return true;
	}

}

capstd::OctetString* ServiceInteractionIndicatorsTwo::setectTreatmentIndicator(){
	if(mectTreatmentIndicator == NULL)
	{
		mectTreatmentIndicator = new capstd::OctetString(1, 1);
		mTagsPresent |= ServiceInteractionIndicatorsTwo_ECTTREATMENTINDICATOR;
		return mectTreatmentIndicator;
	}
	else
		return mectTreatmentIndicator;

}

bool ServiceInteractionIndicatorsTwo::setectTreatmentIndicator(capstd::OctetString* ectTreatmentIndicator){
	if(mectTreatmentIndicator == NULL)
	{
		return -1;
	}
	else
	{
		mectTreatmentIndicator = ectTreatmentIndicator;
		return true;
	}

}

ForwardServiceInteractionInd* ServiceInteractionIndicatorsTwo::getforwardServiceInteractionInd() {//throw(const char*)
	if(NULL == mforwardServiceInteractionInd)
		throw("Object forwardServiceInteractionInd is NULL");
	else
		return mforwardServiceInteractionInd;
}

BackwardServiceInteractionInd* ServiceInteractionIndicatorsTwo::getbackwardServiceInteractionInd() {//throw(const char*)
	if(NULL == mbackwardServiceInteractionInd)
		throw("Object backwardServiceInteractionInd is NULL");
	else
		return mbackwardServiceInteractionInd;
}

BothwayThroughConnectionInd* ServiceInteractionIndicatorsTwo::getbothwayThroughConnectionInd() {//throw(const char*)
	if(NULL == mbothwayThroughConnectionInd)
		throw("Object bothwayThroughConnectionInd is NULL");
	else
		return mbothwayThroughConnectionInd;
}

ConnectedNumberTreatmentInd* ServiceInteractionIndicatorsTwo::getconnectedNumberTreatmentInd() {//throw(const char*)
	if(NULL == mconnectedNumberTreatmentInd)
		throw("Object connectedNumberTreatmentInd is NULL");
	else
		return mconnectedNumberTreatmentInd;
}

bool ServiceInteractionIndicatorsTwo::getnonCUGCall() {
	return mnonCUGCall;
}

capstd::OctetString* ServiceInteractionIndicatorsTwo::getholdTreatmentIndicator() {//throw(const char*)
	if(NULL == mholdTreatmentIndicator)
		throw("Object holdTreatmentIndicator is NULL");
	else
		return mholdTreatmentIndicator;
}

capstd::OctetString* ServiceInteractionIndicatorsTwo::getcwTreatmentIndicator() {//throw(const char*)
	if(NULL == mcwTreatmentIndicator)
		throw("Object cwTreatmentIndicator is NULL");
	else
		return mcwTreatmentIndicator;
}

capstd::OctetString* ServiceInteractionIndicatorsTwo::getectTreatmentIndicator() {//throw(const char*)
	if(NULL == mectTreatmentIndicator)
		throw("Object ectTreatmentIndicator is NULL");
	else
		return mectTreatmentIndicator;
}

bool ServiceInteractionIndicatorsTwo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ServiceInteractionIndicatorsTwo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setforwardServiceInteractionInd())
					return -1;
				if(mforwardServiceInteractionInd->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setbackwardServiceInteractionInd())
					return -1;
				if(mbackwardServiceInteractionInd->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setbothwayThroughConnectionInd())
					return -1;
				if(mbothwayThroughConnectionInd->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0084:
				if(NULL == this->setconnectedNumberTreatmentInd())
					return -1;
				if(mconnectedNumberTreatmentInd->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008D:
				if(NULL == this->setnonCUGCall())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F32:
				if(NULL == this->setholdTreatmentIndicator())
					return -1;
				if(mholdTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F33:
				if(NULL == this->setcwTreatmentIndicator())
					return -1;
				if(mcwTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F34:
				if(NULL == this->setectTreatmentIndicator())
					return -1;
				if(mectTreatmentIndicator->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ServiceInteractionIndicatorsTwo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ServiceInteractionIndicatorsTwo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ServiceInteractionIndicatorsTwo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ServiceInteractionIndicatorsTwo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case ServiceInteractionIndicatorsTwo_FORWARDSERVICEINTERACTIONIND:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mforwardServiceInteractionInd->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_BACKWARDSERVICEINTERACTIONIND:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbackwardServiceInteractionInd->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_BOTHWAYTHROUGHCONNECTIONIND:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbothwayThroughConnectionInd->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_CONNECTEDNUMBERTREATMENTIND:
				if(asn1_tag_encode(132, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mconnectedNumberTreatmentInd->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_NONCUGCALL:
				if(asn1_tag_encode(141, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case ServiceInteractionIndicatorsTwo_HOLDTREATMENTINDICATOR:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mholdTreatmentIndicator->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_CWTREATMENTINDICATOR:
				if(asn1_tag_encode(40755, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcwTreatmentIndicator->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ServiceInteractionIndicatorsTwo_ECTTREATMENTINDICATOR:
				if(asn1_tag_encode(40756, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mectTreatmentIndicator->Encode(array) < 0) || 
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

	return 0;
}

int ServiceInteractionIndicatorsTwo::Display(int tab){
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
			case ServiceInteractionIndicatorsTwo_FORWARDSERVICEINTERACTIONIND:
			{
				printf(temp, " ", "forwardServiceInteractionInd");
				if(mforwardServiceInteractionInd->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_BACKWARDSERVICEINTERACTIONIND:
			{
				printf(temp, " ", "backwardServiceInteractionInd");
				if(mbackwardServiceInteractionInd->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_BOTHWAYTHROUGHCONNECTIONIND:
			{
				printf(temp, " ", "bothwayThroughConnectionInd");
				if(mbothwayThroughConnectionInd->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_CONNECTEDNUMBERTREATMENTIND:
			{
				printf(temp, " ", "connectedNumberTreatmentInd");
				if(mconnectedNumberTreatmentInd->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_NONCUGCALL:
			{
				printf(temp, " ", "nonCUGCall");
				break;
			}
			case ServiceInteractionIndicatorsTwo_HOLDTREATMENTINDICATOR:
			{
				printf(temp, " ", "holdTreatmentIndicator");
				if(mholdTreatmentIndicator->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_CWTREATMENTINDICATOR:
			{
				printf(temp, " ", "cwTreatmentIndicator");
				if(mcwTreatmentIndicator->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ServiceInteractionIndicatorsTwo_ECTTREATMENTINDICATOR:
			{
				printf(temp, " ", "ectTreatmentIndicator");
				if(mectTreatmentIndicator->Display(tab+1) < 0)
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

bool ServiceInteractionIndicatorsTwo::ValidateMandatory(char *errStr){

	return true;
}
SubscriberIdentity::SubscriberIdentity()
{
	mimsi = NULL;
	mmsisdn = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081};
}

SubscriberIdentity::~SubscriberIdentity()
{
	if(mimsi != NULL)
		delete mimsi;
	if(mmsisdn != NULL)
		delete mmsisdn;
}

capstd::IMSI* SubscriberIdentity::setimsi(){
if(mParamSet == true)
	{
		if(mimsi != NULL)
			return mimsi;
		else
			return NULL;
	}
	if(mimsi == NULL)
	{
		mimsi = new capstd::IMSI();
		mTagsPresent |= SubscriberIdentity_IMSI;
		mParamSet = true;
		return mimsi;
	}
}

bool SubscriberIdentity::setimsi(capstd::IMSI* imsi){
	if(mimsi == NULL)
	{
		return -1;
	}
	else
	{
		mimsi = imsi;
		return true;
	}

}

capstd::OctetString* SubscriberIdentity::setmsisdn(){
if(mParamSet == true)
	{
		if(mmsisdn != NULL)
			return mmsisdn;
		else
			return NULL;
	}
	if(mmsisdn == NULL)
	{
		mmsisdn = new capstd::OctetString(1, 0);
		mTagsPresent |= SubscriberIdentity_MSISDN;
		mParamSet = true;
		return mmsisdn;
	}
}

bool SubscriberIdentity::setmsisdn(capstd::OctetString* msisdn){
	if(mmsisdn == NULL)
	{
		return -1;
	}
	else
	{
		mmsisdn = msisdn;
		return true;
	}

}

capstd::IMSI* SubscriberIdentity::getimsi() {//throw(const char*)
	if(NULL == mimsi)
		throw("Object imsi is NULL");
	else
		return mimsi;
}

capstd::OctetString* SubscriberIdentity::getmsisdn() {//throw(const char*)
	if(NULL == mmsisdn)
		throw("Object msisdn is NULL");
	else
		return mmsisdn;
}

bool SubscriberIdentity::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SubscriberIdentity::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setimsi())
					return -1;
				if(mimsi->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setmsisdn())
					return -1;
				if(mmsisdn->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: SubscriberIdentity Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SubscriberIdentity: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SubscriberIdentity::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SubscriberIdentity: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SubscriberIdentity_IMSI:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mimsi->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case SubscriberIdentity_MSISDN:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmsisdn->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int SubscriberIdentity::Display(int tab){
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
			case SubscriberIdentity_IMSI:
			{
				printf(temp, " ", "imsi");
				if(mimsi->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberIdentity_MSISDN:
			{
				printf(temp, " ", "msisdn");
				if(mmsisdn->Display(tab+1) < 0)
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

bool SubscriberIdentity::ValidateMandatory(char *errStr){

	return true;
}
SubscriberInfo::SubscriberInfo()
{
	mlocationInformation = NULL;
	msubscriberState = NULL;
	mextensionContainer = NULL;
	mlocationInformationGPRS = NULL;
	mps_SubscriberState = NULL;
	mimei = NULL;
	mms_Classmark2 = NULL;
	mgprs_MS_Class = NULL;
	mmnpInfoRes = NULL;
	mimsVoiceOverPS_SessionsIndication = NULL;
	mlastUE_ActivityTime = NULL;
	mlastRAT_Type = NULL;
	meps_SubscriberState = NULL;
	mlocationInformationEPS = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1, 0X00A2, 0X00A3, 0X00A4, 0X0085, 0X0086, 0X00A7, 0X00A8, 0X0089, 0X008A, 0X008B, 0X00AC, 0X00AD};
	mTagOptional = {true, true, true, true, true, true, true, true, true, true, true, true, true, true};
}

SubscriberInfo::~SubscriberInfo()
{
	if(mlocationInformation != NULL)
		delete mlocationInformation;
	if(msubscriberState != NULL)
		delete msubscriberState;
	if(mextensionContainer != NULL)
		delete mextensionContainer;
	if(mlocationInformationGPRS != NULL)
		delete mlocationInformationGPRS;
	if(mps_SubscriberState != NULL)
		delete mps_SubscriberState;
	if(mimei != NULL)
		delete mimei;
	if(mms_Classmark2 != NULL)
		delete mms_Classmark2;
	if(mgprs_MS_Class != NULL)
		delete mgprs_MS_Class;
	if(mmnpInfoRes != NULL)
		delete mmnpInfoRes;
	if(mimsVoiceOverPS_SessionsIndication != NULL)
		delete mimsVoiceOverPS_SessionsIndication;
	if(mlastUE_ActivityTime != NULL)
		delete mlastUE_ActivityTime;
	if(mlastRAT_Type != NULL)
		delete mlastRAT_Type;
	if(meps_SubscriberState != NULL)
		delete meps_SubscriberState;
	if(mlocationInformationEPS != NULL)
		delete mlocationInformationEPS;
}

LocationInformation* SubscriberInfo::setlocationInformation(){
	if(mlocationInformation == NULL)
	{
		mlocationInformation = new LocationInformation();
		mTagsPresent |= SubscriberInfo_LOCATIONINFORMATION;
		return mlocationInformation;
	}
	else
		return mlocationInformation;

}

bool SubscriberInfo::setlocationInformation(LocationInformation* locationInformation){
	if(mlocationInformation == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformation = locationInformation;
		return true;
	}

}

SubscriberState* SubscriberInfo::setsubscriberState(){
	if(msubscriberState == NULL)
	{
		msubscriberState = new SubscriberState();
		mTagsPresent |= SubscriberInfo_SUBSCRIBERSTATE;
		return msubscriberState;
	}
	else
		return msubscriberState;

}

bool SubscriberInfo::setsubscriberState(SubscriberState* subscriberState){
	if(msubscriberState == NULL)
	{
		return -1;
	}
	else
	{
		msubscriberState = subscriberState;
		return true;
	}

}

capstd::GENERIC* SubscriberInfo::setextensionContainer(){
	if(mextensionContainer == NULL)
	{
		mextensionContainer = new capstd::GENERIC();
		mTagsPresent |= SubscriberInfo_EXTENSIONCONTAINER;
		return mextensionContainer;
	}
	else
		return mextensionContainer;

}

bool SubscriberInfo::setextensionContainer(capstd::GENERIC* extensionContainer){
	if(mextensionContainer == NULL)
	{
		return -1;
	}
	else
	{
		mextensionContainer = extensionContainer;
		return true;
	}

}

LocationInformationGPRS* SubscriberInfo::setlocationInformationGPRS(){
	if(mlocationInformationGPRS == NULL)
	{
		mlocationInformationGPRS = new LocationInformationGPRS();
		mTagsPresent |= SubscriberInfo_LOCATIONINFORMATIONGPRS;
		return mlocationInformationGPRS;
	}
	else
		return mlocationInformationGPRS;

}

bool SubscriberInfo::setlocationInformationGPRS(LocationInformationGPRS* locationInformationGPRS){
	if(mlocationInformationGPRS == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformationGPRS = locationInformationGPRS;
		return true;
	}

}

PS_SubscriberState* SubscriberInfo::setps_SubscriberState(){
	if(mps_SubscriberState == NULL)
	{
		mps_SubscriberState = new PS_SubscriberState();
		mTagsPresent |= SubscriberInfo_PS_SUBSCRIBERSTATE;
		return mps_SubscriberState;
	}
	else
		return mps_SubscriberState;

}

bool SubscriberInfo::setps_SubscriberState(PS_SubscriberState* ps_SubscriberState){
	if(mps_SubscriberState == NULL)
	{
		return -1;
	}
	else
	{
		mps_SubscriberState = ps_SubscriberState;
		return true;
	}

}

capstd::OctetString* SubscriberInfo::setimei(){
	if(mimei == NULL)
	{
		mimei = new capstd::OctetString();
		mTagsPresent |= SubscriberInfo_IMEI;
		return mimei;
	}
	else
		return mimei;

}

bool SubscriberInfo::setimei(capstd::OctetString* imei){
	if(mimei == NULL)
	{
		return -1;
	}
	else
	{
		mimei = imei;
		return true;
	}

}

capstd::OctetString* SubscriberInfo::setms_Classmark2(){
	if(mms_Classmark2 == NULL)
	{
		mms_Classmark2 = new capstd::OctetString(3, 3);
		mTagsPresent |= SubscriberInfo_MS_CLASSMARK2;
		return mms_Classmark2;
	}
	else
		return mms_Classmark2;

}

bool SubscriberInfo::setms_Classmark2(capstd::OctetString* ms_Classmark2){
	if(mms_Classmark2 == NULL)
	{
		return -1;
	}
	else
	{
		mms_Classmark2 = ms_Classmark2;
		return true;
	}

}

GPRSMSClass* SubscriberInfo::setgprs_MS_Class(){
	if(mgprs_MS_Class == NULL)
	{
		mgprs_MS_Class = new GPRSMSClass();
		mTagsPresent |= SubscriberInfo_GPRS_MS_CLASS;
		return mgprs_MS_Class;
	}
	else
		return mgprs_MS_Class;

}

bool SubscriberInfo::setgprs_MS_Class(GPRSMSClass* gprs_MS_Class){
	if(mgprs_MS_Class == NULL)
	{
		return -1;
	}
	else
	{
		mgprs_MS_Class = gprs_MS_Class;
		return true;
	}

}

MNPInfoRes* SubscriberInfo::setmnpInfoRes(){
	if(mmnpInfoRes == NULL)
	{
		mmnpInfoRes = new MNPInfoRes();
		mTagsPresent |= SubscriberInfo_MNPINFORES;
		return mmnpInfoRes;
	}
	else
		return mmnpInfoRes;

}

bool SubscriberInfo::setmnpInfoRes(MNPInfoRes* mnpInfoRes){
	if(mmnpInfoRes == NULL)
	{
		return -1;
	}
	else
	{
		mmnpInfoRes = mnpInfoRes;
		return true;
	}

}

IMS_VoiceOverPS_SessionsInd* SubscriberInfo::setimsVoiceOverPS_SessionsIndication(){
	if(mimsVoiceOverPS_SessionsIndication == NULL)
	{
		mimsVoiceOverPS_SessionsIndication = new IMS_VoiceOverPS_SessionsInd();
		mTagsPresent |= SubscriberInfo_IMSVOICEOVERPS_SESSIONSINDICATION;
		return mimsVoiceOverPS_SessionsIndication;
	}
	else
		return mimsVoiceOverPS_SessionsIndication;

}

bool SubscriberInfo::setimsVoiceOverPS_SessionsIndication(IMS_VoiceOverPS_SessionsInd* imsVoiceOverPS_SessionsIndication){
	if(mimsVoiceOverPS_SessionsIndication == NULL)
	{
		return -1;
	}
	else
	{
		mimsVoiceOverPS_SessionsIndication = imsVoiceOverPS_SessionsIndication;
		return true;
	}

}

capstd::OctetString* SubscriberInfo::setlastUE_ActivityTime(){
	if(mlastUE_ActivityTime == NULL)
	{
		mlastUE_ActivityTime = new capstd::OctetString(4, 4);
		mTagsPresent |= SubscriberInfo_LASTUE_ACTIVITYTIME;
		return mlastUE_ActivityTime;
	}
	else
		return mlastUE_ActivityTime;

}

bool SubscriberInfo::setlastUE_ActivityTime(capstd::OctetString* lastUE_ActivityTime){
	if(mlastUE_ActivityTime == NULL)
	{
		return -1;
	}
	else
	{
		mlastUE_ActivityTime = lastUE_ActivityTime;
		return true;
	}

}

Used_RAT_Type* SubscriberInfo::setlastRAT_Type(){
	if(mlastRAT_Type == NULL)
	{
		mlastRAT_Type = new Used_RAT_Type();
		mTagsPresent |= SubscriberInfo_LASTRAT_TYPE;
		return mlastRAT_Type;
	}
	else
		return mlastRAT_Type;

}

bool SubscriberInfo::setlastRAT_Type(Used_RAT_Type* lastRAT_Type){
	if(mlastRAT_Type == NULL)
	{
		return -1;
	}
	else
	{
		mlastRAT_Type = lastRAT_Type;
		return true;
	}

}

PS_SubscriberState* SubscriberInfo::seteps_SubscriberState(){
	if(meps_SubscriberState == NULL)
	{
		meps_SubscriberState = new PS_SubscriberState();
		mTagsPresent |= SubscriberInfo_EPS_SUBSCRIBERSTATE;
		return meps_SubscriberState;
	}
	else
		return meps_SubscriberState;

}

bool SubscriberInfo::seteps_SubscriberState(PS_SubscriberState* eps_SubscriberState){
	if(meps_SubscriberState == NULL)
	{
		return -1;
	}
	else
	{
		meps_SubscriberState = eps_SubscriberState;
		return true;
	}

}

LocationInformationEPS* SubscriberInfo::setlocationInformationEPS(){
	if(mlocationInformationEPS == NULL)
	{
		mlocationInformationEPS = new LocationInformationEPS();
		mTagsPresent |= SubscriberInfo_LOCATIONINFORMATIONEPS;
		return mlocationInformationEPS;
	}
	else
		return mlocationInformationEPS;

}

bool SubscriberInfo::setlocationInformationEPS(LocationInformationEPS* locationInformationEPS){
	if(mlocationInformationEPS == NULL)
	{
		return -1;
	}
	else
	{
		mlocationInformationEPS = locationInformationEPS;
		return true;
	}

}

LocationInformation* SubscriberInfo::getlocationInformation() {//throw(const char*)
	if(NULL == mlocationInformation)
		throw("Object locationInformation is NULL");
	else
		return mlocationInformation;
}

SubscriberState* SubscriberInfo::getsubscriberState() {//throw(const char*)
	if(NULL == msubscriberState)
		throw("Object subscriberState is NULL");
	else
		return msubscriberState;
}

capstd::GENERIC* SubscriberInfo::getextensionContainer() {//throw(const char*)
	if(NULL == mextensionContainer)
		throw("Object extensionContainer is NULL");
	else
		return mextensionContainer;
}

LocationInformationGPRS* SubscriberInfo::getlocationInformationGPRS() {//throw(const char*)
	if(NULL == mlocationInformationGPRS)
		throw("Object locationInformationGPRS is NULL");
	else
		return mlocationInformationGPRS;
}

PS_SubscriberState* SubscriberInfo::getps_SubscriberState() {//throw(const char*)
	if(NULL == mps_SubscriberState)
		throw("Object ps_SubscriberState is NULL");
	else
		return mps_SubscriberState;
}

capstd::OctetString* SubscriberInfo::getimei() {//throw(const char*)
	if(NULL == mimei)
		throw("Object imei is NULL");
	else
		return mimei;
}

capstd::OctetString* SubscriberInfo::getms_Classmark2() {//throw(const char*)
	if(NULL == mms_Classmark2)
		throw("Object ms_Classmark2 is NULL");
	else
		return mms_Classmark2;
}

GPRSMSClass* SubscriberInfo::getgprs_MS_Class() {//throw(const char*)
	if(NULL == mgprs_MS_Class)
		throw("Object gprs_MS_Class is NULL");
	else
		return mgprs_MS_Class;
}

MNPInfoRes* SubscriberInfo::getmnpInfoRes() {//throw(const char*)
	if(NULL == mmnpInfoRes)
		throw("Object mnpInfoRes is NULL");
	else
		return mmnpInfoRes;
}

IMS_VoiceOverPS_SessionsInd* SubscriberInfo::getimsVoiceOverPS_SessionsIndication() {//throw(const char*)
	if(NULL == mimsVoiceOverPS_SessionsIndication)
		throw("Object imsVoiceOverPS_SessionsIndication is NULL");
	else
		return mimsVoiceOverPS_SessionsIndication;
}

capstd::OctetString* SubscriberInfo::getlastUE_ActivityTime() {//throw(const char*)
	if(NULL == mlastUE_ActivityTime)
		throw("Object lastUE_ActivityTime is NULL");
	else
		return mlastUE_ActivityTime;
}

Used_RAT_Type* SubscriberInfo::getlastRAT_Type() {//throw(const char*)
	if(NULL == mlastRAT_Type)
		throw("Object lastRAT_Type is NULL");
	else
		return mlastRAT_Type;
}

PS_SubscriberState* SubscriberInfo::geteps_SubscriberState() {//throw(const char*)
	if(NULL == meps_SubscriberState)
		throw("Object eps_SubscriberState is NULL");
	else
		return meps_SubscriberState;
}

LocationInformationEPS* SubscriberInfo::getlocationInformationEPS() {//throw(const char*)
	if(NULL == mlocationInformationEPS)
		throw("Object locationInformationEPS is NULL");
	else
		return mlocationInformationEPS;
}

bool SubscriberInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SubscriberInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setlocationInformation())
					return -1;
				if(mlocationInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setsubscriberState())
					return -1;
				if(msubscriberState->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensionContainer())
					return -1;
				if(mextensionContainer->Decode(array, &bytesDecoded, mTagArray, SubscriberInfo_EXTENSIONCONTAINER) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setlocationInformationGPRS())
					return -1;
				if(mlocationInformationGPRS->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setps_SubscriberState())
					return -1;
				if(mps_SubscriberState->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0085:
				if(NULL == this->setimei())
					return -1;
				if(mimei->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0086:
				if(NULL == this->setms_Classmark2())
					return -1;
				if(mms_Classmark2->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A7:
				if(NULL == this->setgprs_MS_Class())
					return -1;
				if(mgprs_MS_Class->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A8:
				if(NULL == this->setmnpInfoRes())
					return -1;
				if(mmnpInfoRes->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0089:
				if(NULL == this->setimsVoiceOverPS_SessionsIndication())
					return -1;
				if(mimsVoiceOverPS_SessionsIndication->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008A:
				if(NULL == this->setlastUE_ActivityTime())
					return -1;
				if(mlastUE_ActivityTime->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X008B:
				if(NULL == this->setlastRAT_Type())
					return -1;
				if(mlastRAT_Type->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AC:
				if(NULL == this->seteps_SubscriberState())
					return -1;
				if(meps_SubscriberState->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00AD:
				if(NULL == this->setlocationInformationEPS())
					return -1;
				if(mlocationInformationEPS->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: SubscriberInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SubscriberInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SubscriberInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SubscriberInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SubscriberInfo_LOCATIONINFORMATION:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_SUBSCRIBERSTATE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((msubscriberState->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_EXTENSIONCONTAINER:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensionContainer->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_LOCATIONINFORMATIONGPRS:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformationGPRS->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_PS_SUBSCRIBERSTATE:
				if(asn1_tag_encode(164, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mps_SubscriberState->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_IMEI:
				if(asn1_tag_encode(133, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mimei->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_MS_CLASSMARK2:
				if(asn1_tag_encode(134, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mms_Classmark2->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_GPRS_MS_CLASS:
				if(asn1_tag_encode(167, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgprs_MS_Class->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_MNPINFORES:
				if(asn1_tag_encode(168, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmnpInfoRes->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_IMSVOICEOVERPS_SESSIONSINDICATION:
				if(asn1_tag_encode(137, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mimsVoiceOverPS_SessionsIndication->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_LASTUE_ACTIVITYTIME:
				if(asn1_tag_encode(138, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlastUE_ActivityTime->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_LASTRAT_TYPE:
				if(asn1_tag_encode(139, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlastRAT_Type->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_EPS_SUBSCRIBERSTATE:
				if(asn1_tag_encode(172, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((meps_SubscriberState->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SubscriberInfo_LOCATIONINFORMATIONEPS:
				if(asn1_tag_encode(173, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlocationInformationEPS->Encode(array) < 0) || 
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

	return 0;
}

int SubscriberInfo::Display(int tab){
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
			case SubscriberInfo_LOCATIONINFORMATION:
			{
				printf(temp, " ", "locationInformation");
				if(mlocationInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_SUBSCRIBERSTATE:
			{
				printf(temp, " ", "subscriberState");
				if(msubscriberState->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_EXTENSIONCONTAINER:
			{
				printf(temp, " ", "extensionContainer");
				if(mextensionContainer->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_LOCATIONINFORMATIONGPRS:
			{
				printf(temp, " ", "locationInformationGPRS");
				if(mlocationInformationGPRS->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_PS_SUBSCRIBERSTATE:
			{
				printf(temp, " ", "ps_SubscriberState");
				if(mps_SubscriberState->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_IMEI:
			{
				printf(temp, " ", "imei");
				if(mimei->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_MS_CLASSMARK2:
			{
				printf(temp, " ", "ms_Classmark2");
				if(mms_Classmark2->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_GPRS_MS_CLASS:
			{
				printf(temp, " ", "gprs_MS_Class");
				if(mgprs_MS_Class->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_MNPINFORES:
			{
				printf(temp, " ", "mnpInfoRes");
				if(mmnpInfoRes->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_IMSVOICEOVERPS_SESSIONSINDICATION:
			{
				printf(temp, " ", "imsVoiceOverPS_SessionsIndication");
				if(mimsVoiceOverPS_SessionsIndication->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_LASTUE_ACTIVITYTIME:
			{
				printf(temp, " ", "lastUE_ActivityTime");
				if(mlastUE_ActivityTime->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_LASTRAT_TYPE:
			{
				printf(temp, " ", "lastRAT_Type");
				if(mlastRAT_Type->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_EPS_SUBSCRIBERSTATE:
			{
				printf(temp, " ", "eps_SubscriberState");
				if(meps_SubscriberState->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberInfo_LOCATIONINFORMATIONEPS:
			{
				printf(temp, " ", "locationInformationEPS");
				if(mlocationInformationEPS->Display(tab+1) < 0)
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

bool SubscriberInfo::ValidateMandatory(char *errStr){

	return true;
}
SubscriberState::SubscriberState()
{
	massumedIdle = false;
	mcamelBusy = false;
	mnetDetNotReachable = NULL;
	mnotProvidedFromVLR = false;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081, 0X000A, 0X0082};
}

SubscriberState::~SubscriberState()
{
	if(mnetDetNotReachable != NULL)
		delete mnetDetNotReachable;
}

bool* SubscriberState::setassumedIdle(){
if(mParamSet == true)
	{
		if(mNullassumedIdle == true)
			return &massumedIdle;
		else
			return NULL;
	}
	mTagsPresent |= SubscriberState_ASSUMEDIDLE;
		mParamSet = true;
	mNullassumedIdle = true;
	return &mNullassumedIdle;
}

bool SubscriberState::setassumedIdle(bool assumedIdle){
	massumedIdle = assumedIdle;
	return true;
}

bool* SubscriberState::setcamelBusy(){
if(mParamSet == true)
	{
		if(mNullcamelBusy == true)
			return &mcamelBusy;
		else
			return NULL;
	}
	mTagsPresent |= SubscriberState_CAMELBUSY;
		mParamSet = true;
	mNullcamelBusy = true;
	return &mNullcamelBusy;
}

bool SubscriberState::setcamelBusy(bool camelBusy){
	mcamelBusy = camelBusy;
	return true;
}

NotReachableReason* SubscriberState::setnetDetNotReachable(){
if(mParamSet == true)
	{
		if(mnetDetNotReachable != NULL)
			return mnetDetNotReachable;
		else
			return NULL;
	}
	if(mnetDetNotReachable == NULL)
	{
		mnetDetNotReachable = new NotReachableReason();
		mTagsPresent |= SubscriberState_NETDETNOTREACHABLE;
		mParamSet = true;
		return mnetDetNotReachable;
	}
}

bool SubscriberState::setnetDetNotReachable(NotReachableReason* netDetNotReachable){
	if(mnetDetNotReachable == NULL)
	{
		return -1;
	}
	else
	{
		mnetDetNotReachable = netDetNotReachable;
		return true;
	}

}

bool* SubscriberState::setnotProvidedFromVLR(){
if(mParamSet == true)
	{
		if(mNullnotProvidedFromVLR == true)
			return &mnotProvidedFromVLR;
		else
			return NULL;
	}
	mTagsPresent |= SubscriberState_NOTPROVIDEDFROMVLR;
		mParamSet = true;
	mNullnotProvidedFromVLR = true;
	return &mNullnotProvidedFromVLR;
}

bool SubscriberState::setnotProvidedFromVLR(bool notProvidedFromVLR){
	mnotProvidedFromVLR = notProvidedFromVLR;
	return true;
}

bool SubscriberState::getassumedIdle() {
	return massumedIdle;
}

bool SubscriberState::getcamelBusy() {
	return mcamelBusy;
}

NotReachableReason* SubscriberState::getnetDetNotReachable() {//throw(const char*)
	if(NULL == mnetDetNotReachable)
		throw("Object netDetNotReachable is NULL");
	else
		return mnetDetNotReachable;
}

bool SubscriberState::getnotProvidedFromVLR() {
	return mnotProvidedFromVLR;
}

bool SubscriberState::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SubscriberState::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->setassumedIdle())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setcamelBusy())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X000A:
				if(NULL == this->setnetDetNotReachable())
					return -1;
				if(mnetDetNotReachable->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0082:
				if(NULL == this->setnotProvidedFromVLR())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: SubscriberState Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SubscriberState: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SubscriberState::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SubscriberState: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SubscriberState_ASSUMEDIDLE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case SubscriberState_CAMELBUSY:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			case SubscriberState_NETDETNOTREACHABLE:
				if(asn1_tag_encode(10, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnetDetNotReachable->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case SubscriberState_NOTPROVIDEDFROMVLR:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
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

	return 0;
}

int SubscriberState::Display(int tab){
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
			case SubscriberState_ASSUMEDIDLE:
			{
				printf(temp, " ", "assumedIdle");
				break;
			}
			case SubscriberState_CAMELBUSY:
			{
				printf(temp, " ", "camelBusy");
				break;
			}
			case SubscriberState_NETDETNOTREACHABLE:
			{
				printf(temp, " ", "netDetNotReachable");
				if(mnetDetNotReachable->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SubscriberState_NOTPROVIDEDFROMVLR:
			{
				printf(temp, " ", "notProvidedFromVLR");
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

bool SubscriberState::ValidateMandatory(char *errStr){

	return true;
}
SupportedExtensionsExtensionType::SupportedExtensionsExtensionType()
{
	mfirstExtensionExtensionType = false;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0005};
}

SupportedExtensionsExtensionType::~SupportedExtensionsExtensionType()
{
}

bool* SupportedExtensionsExtensionType::setfirstExtensionExtensionType(){
if(mParamSet == true)
	{
		if(mNullfirstExtensionExtensionType == true)
			return &mfirstExtensionExtensionType;
		else
			return NULL;
	}
	mTagsPresent |= SupportedExtensionsExtensionType_FIRSTEXTENSIONEXTENSIONTYPE;
		mParamSet = true;
	mNullfirstExtensionExtensionType = true;
	return &mNullfirstExtensionExtensionType;
}

bool SupportedExtensionsExtensionType::setfirstExtensionExtensionType(bool firstExtensionExtensionType){
	mfirstExtensionExtensionType = firstExtensionExtensionType;
	return true;
}

bool SupportedExtensionsExtensionType::getfirstExtensionExtensionType() {
	return mfirstExtensionExtensionType;
}

bool SupportedExtensionsExtensionType::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SupportedExtensionsExtensionType::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0005:
				if(NULL == this->setfirstExtensionExtensionType())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: SupportedExtensionsExtensionType Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SupportedExtensionsExtensionType: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SupportedExtensionsExtensionType::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SupportedExtensionsExtensionType: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SupportedExtensionsExtensionType_FIRSTEXTENSIONEXTENSIONTYPE:
				if(asn1_tag_encode(5, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
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

	return 0;
}

int SupportedExtensionsExtensionType::Display(int tab){
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
			case SupportedExtensionsExtensionType_FIRSTEXTENSIONEXTENSIONTYPE:
			{
				printf(temp, " ", "firstExtensionExtensionType");
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

bool SupportedExtensionsExtensionType::ValidateMandatory(char *errStr){

	return true;
}
TAnswerSpecificInfo::TAnswerSpecificInfo()
{
	mdestinationAddress = NULL;
	mor_Call = false;
	mforwardedCall = false;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X9F32, 0X9F33, 0X9F34};
	mTagOptional = {true, true, true};
}

TAnswerSpecificInfo::~TAnswerSpecificInfo()
{
	if(mdestinationAddress != NULL)
		delete mdestinationAddress;
}

capstd::OctetString* TAnswerSpecificInfo::setdestinationAddress(){
	if(mdestinationAddress == NULL)
	{
		mdestinationAddress = new capstd::OctetString(2, 18);
		mTagsPresent |= TAnswerSpecificInfo_DESTINATIONADDRESS;
		return mdestinationAddress;
	}
	else
		return mdestinationAddress;

}

bool TAnswerSpecificInfo::setdestinationAddress(capstd::OctetString* destinationAddress){
	if(mdestinationAddress == NULL)
	{
		return -1;
	}
	else
	{
		mdestinationAddress = destinationAddress;
		return true;
	}

}

bool* TAnswerSpecificInfo::setor_Call(){
	mor_Call = true;
	mTagsPresent |= TAnswerSpecificInfo_OR_CALL;
	mNullor_Call = true;
	return &mNullor_Call;
}

bool TAnswerSpecificInfo::setor_Call(bool or_Call){
	mor_Call = or_Call;
	return true;
}

bool* TAnswerSpecificInfo::setforwardedCall(){
	mforwardedCall = true;
	mTagsPresent |= TAnswerSpecificInfo_FORWARDEDCALL;
	mNullforwardedCall = true;
	return &mNullforwardedCall;
}

bool TAnswerSpecificInfo::setforwardedCall(bool forwardedCall){
	mforwardedCall = forwardedCall;
	return true;
}

capstd::OctetString* TAnswerSpecificInfo::getdestinationAddress() {//throw(const char*)
	if(NULL == mdestinationAddress)
		throw("Object destinationAddress is NULL");
	else
		return mdestinationAddress;
}

bool TAnswerSpecificInfo::getor_Call() {
	return mor_Call;
}

bool TAnswerSpecificInfo::getforwardedCall() {
	return mforwardedCall;
}

bool TAnswerSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TAnswerSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X9F32:
				if(NULL == this->setdestinationAddress())
					return -1;
				if(mdestinationAddress->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F33:
				if(NULL == this->setor_Call())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F34:
				if(NULL == this->setforwardedCall())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TAnswerSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TAnswerSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TAnswerSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TAnswerSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TAnswerSpecificInfo_DESTINATIONADDRESS:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mdestinationAddress->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TAnswerSpecificInfo_OR_CALL:
				if(asn1_tag_encode(40755, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case TAnswerSpecificInfo_FORWARDEDCALL:
				if(asn1_tag_encode(40756, array) < 0)
					return -1;
				asn1_null_encode(array);
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

	return 0;
}

int TAnswerSpecificInfo::Display(int tab){
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
			case TAnswerSpecificInfo_DESTINATIONADDRESS:
			{
				printf(temp, " ", "destinationAddress");
				if(mdestinationAddress->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TAnswerSpecificInfo_OR_CALL:
			{
				printf(temp, " ", "or_Call");
				break;
			}
			case TAnswerSpecificInfo_FORWARDEDCALL:
			{
				printf(temp, " ", "forwardedCall");
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

bool TAnswerSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
TBusySpecificInfo::TBusySpecificInfo()
{
	mbusyCause = NULL;
	mcallForwarded = false;
	mrouteNotPermitted = false;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X9F32, 0X9F33};
	mTagOptional = {true, true, true};
}

TBusySpecificInfo::~TBusySpecificInfo()
{
	if(mbusyCause != NULL)
		delete mbusyCause;
}

capstd::GENERIC* TBusySpecificInfo::setbusyCause(){
	if(mbusyCause == NULL)
	{
		mbusyCause = new capstd::GENERIC();
		mTagsPresent |= TBusySpecificInfo_BUSYCAUSE;
		return mbusyCause;
	}
	else
		return mbusyCause;

}

bool TBusySpecificInfo::setbusyCause(capstd::GENERIC* busyCause){
	if(mbusyCause == NULL)
	{
		return -1;
	}
	else
	{
		mbusyCause = busyCause;
		return true;
	}

}

bool* TBusySpecificInfo::setcallForwarded(){
	mcallForwarded = true;
	mTagsPresent |= TBusySpecificInfo_CALLFORWARDED;
	mNullcallForwarded = true;
	return &mNullcallForwarded;
}

bool TBusySpecificInfo::setcallForwarded(bool callForwarded){
	mcallForwarded = callForwarded;
	return true;
}

bool* TBusySpecificInfo::setrouteNotPermitted(){
	mrouteNotPermitted = true;
	mTagsPresent |= TBusySpecificInfo_ROUTENOTPERMITTED;
	mNullrouteNotPermitted = true;
	return &mNullrouteNotPermitted;
}

bool TBusySpecificInfo::setrouteNotPermitted(bool routeNotPermitted){
	mrouteNotPermitted = routeNotPermitted;
	return true;
}

capstd::GENERIC* TBusySpecificInfo::getbusyCause() {//throw(const char*)
	if(NULL == mbusyCause)
		throw("Object busyCause is NULL");
	else
		return mbusyCause;
}

bool TBusySpecificInfo::getcallForwarded() {
	return mcallForwarded;
}

bool TBusySpecificInfo::getrouteNotPermitted() {
	return mrouteNotPermitted;
}

bool TBusySpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TBusySpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setbusyCause())
					return -1;
				if(mbusyCause->Decode(array, &bytesDecoded, mTagArray, TBusySpecificInfo_BUSYCAUSE) < 0)
					decode = false;
				break;
			case 0X9F32:
				if(NULL == this->setcallForwarded())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X9F33:
				if(NULL == this->setrouteNotPermitted())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TBusySpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TBusySpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TBusySpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TBusySpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TBusySpecificInfo_BUSYCAUSE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbusyCause->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TBusySpecificInfo_CALLFORWARDED:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case TBusySpecificInfo_ROUTENOTPERMITTED:
				if(asn1_tag_encode(40755, array) < 0)
					return -1;
				asn1_null_encode(array);
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

	return 0;
}

int TBusySpecificInfo::Display(int tab){
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
			case TBusySpecificInfo_BUSYCAUSE:
			{
				printf(temp, " ", "busyCause");
				if(mbusyCause->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TBusySpecificInfo_CALLFORWARDED:
			{
				printf(temp, " ", "callForwarded");
				break;
			}
			case TBusySpecificInfo_ROUTENOTPERMITTED:
			{
				printf(temp, " ", "routeNotPermitted");
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

bool TBusySpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
TDisconnectSpecificInfo::TDisconnectSpecificInfo()
{
	mreleaseCause = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {true};
}

TDisconnectSpecificInfo::~TDisconnectSpecificInfo()
{
	if(mreleaseCause != NULL)
		delete mreleaseCause;
}

capstd::GENERIC* TDisconnectSpecificInfo::setreleaseCause(){
	if(mreleaseCause == NULL)
	{
		mreleaseCause = new capstd::GENERIC();
		mTagsPresent |= TDisconnectSpecificInfo_RELEASECAUSE;
		return mreleaseCause;
	}
	else
		return mreleaseCause;

}

bool TDisconnectSpecificInfo::setreleaseCause(capstd::GENERIC* releaseCause){
	if(mreleaseCause == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseCause = releaseCause;
		return true;
	}

}

capstd::GENERIC* TDisconnectSpecificInfo::getreleaseCause() {//throw(const char*)
	if(NULL == mreleaseCause)
		throw("Object releaseCause is NULL");
	else
		return mreleaseCause;
}

bool TDisconnectSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TDisconnectSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setreleaseCause())
					return -1;
				if(mreleaseCause->Decode(array, &bytesDecoded, mTagArray, TDisconnectSpecificInfo_RELEASECAUSE) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TDisconnectSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TDisconnectSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TDisconnectSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TDisconnectSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TDisconnectSpecificInfo_RELEASECAUSE:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseCause->Encode(array) < 0) || 
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

	return 0;
}

int TDisconnectSpecificInfo::Display(int tab){
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
			case TDisconnectSpecificInfo_RELEASECAUSE:
			{
				printf(temp, " ", "releaseCause");
				if(mreleaseCause->Display(tab+1) < 0)
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

bool TDisconnectSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
TNoAnswerSpecificInfo::TNoAnswerSpecificInfo()
{
	mcallForwarded = false;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X9F32};
	mTagOptional = {true};
}

TNoAnswerSpecificInfo::~TNoAnswerSpecificInfo()
{
}

bool* TNoAnswerSpecificInfo::setcallForwarded(){
	mcallForwarded = true;
	mTagsPresent |= TNoAnswerSpecificInfo_CALLFORWARDED;
	mNullcallForwarded = true;
	return &mNullcallForwarded;
}

bool TNoAnswerSpecificInfo::setcallForwarded(bool callForwarded){
	mcallForwarded = callForwarded;
	return true;
}

bool TNoAnswerSpecificInfo::getcallForwarded() {
	return mcallForwarded;
}

bool TNoAnswerSpecificInfo::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TNoAnswerSpecificInfo::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
			case 0X9F32:
				if(NULL == this->setcallForwarded())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TNoAnswerSpecificInfo Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TNoAnswerSpecificInfo: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TNoAnswerSpecificInfo::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TNoAnswerSpecificInfo: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TNoAnswerSpecificInfo_CALLFORWARDED:
				if(asn1_tag_encode(40754, array) < 0)
					return -1;
				asn1_null_encode(array);
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

	return 0;
}

int TNoAnswerSpecificInfo::Display(int tab){
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
			case TNoAnswerSpecificInfo_CALLFORWARDED:
			{
				printf(temp, " ", "callForwarded");
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

bool TNoAnswerSpecificInfo::ValidateMandatory(char *errStr){

	return true;
}
Text::Text()
{
	mmessageContent = NULL;
	mattributes = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, true};
}

Text::~Text()
{
	if(mmessageContent != NULL)
		delete mmessageContent;
	if(mattributes != NULL)
		delete mattributes;
}

capstd::OctetString* Text::setmessageContent(){
	if(mmessageContent == NULL)
	{
		mmessageContent = new capstd::OctetString(1, 127);
		mTagsPresent |= Text_MESSAGECONTENT;
		return mmessageContent;
	}
	else
		return mmessageContent;

}

bool Text::setmessageContent(capstd::OctetString* messageContent){
	if(mmessageContent == NULL)
	{
		return -1;
	}
	else
	{
		mmessageContent = messageContent;
		return true;
	}

}

capstd::OctetString* Text::setattributes(){
	if(mattributes == NULL)
	{
		mattributes = new capstd::OctetString(2, 10);
		mTagsPresent |= Text_ATTRIBUTES;
		return mattributes;
	}
	else
		return mattributes;

}

bool Text::setattributes(capstd::OctetString* attributes){
	if(mattributes == NULL)
	{
		return -1;
	}
	else
	{
		mattributes = attributes;
		return true;
	}

}

capstd::OctetString* Text::getmessageContent() {//throw(const char*)
	if(NULL == mmessageContent)
		throw("Object messageContent is NULL");
	else
		return mmessageContent;
}

capstd::OctetString* Text::getattributes() {//throw(const char*)
	if(NULL == mattributes)
		throw("Object attributes is NULL");
	else
		return mattributes;
}

bool Text::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int Text::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setmessageContent())
					return -1;
				if(mmessageContent->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setattributes())
					return -1;
				if(mattributes->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: Text Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("Text: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int Text::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("Text: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case Text_MESSAGECONTENT:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmessageContent->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case Text_ATTRIBUTES:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mattributes->Encode(array) < 0) || 
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

	return 0;
}

int Text::Display(int tab){
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
			case Text_MESSAGECONTENT:
			{
				printf(temp, " ", "messageContent");
				if(mmessageContent->Display(tab+1) < 0)
					return -1;
				break;
			}
			case Text_ATTRIBUTES:
			{
				printf(temp, " ", "attributes");
				if(mattributes->Display(tab+1) < 0)
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

bool Text::ValidateMandatory(char *errStr){
	if(NULL == mmessageContent)
	{
		strcpy(errStr, "messageContent");
		return false;
	}

	return true;
}
TimeDurationCharging::TimeDurationCharging()
{
	mmaxCallPeriodDuration = NULL;
	releaseIfdurationExceededDefault = new capstd::Boolean();
	releaseIfdurationExceededDefault->setValue(true);
	mreleaseIfdurationExceeded = NULL;
	mtariffSwitchInterval = NULL;
	toneDefault = new capstd::Boolean();
	toneDefault->setValue(true);
	mtone = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081, 0X0082, 0X0083, 0X00A4};
	mTagOptional = {false, false, true, false, true};
}

TimeDurationCharging::~TimeDurationCharging()
{
	if(mmaxCallPeriodDuration != NULL)
		delete mmaxCallPeriodDuration;
	if(mreleaseIfdurationExceeded != NULL)
		delete mreleaseIfdurationExceeded;
	if(releaseIfdurationExceededDefault != NULL)
		delete releaseIfdurationExceededDefault;
	if(mtariffSwitchInterval != NULL)
		delete mtariffSwitchInterval;
	if(mtone != NULL)
		delete mtone;
	if(toneDefault != NULL)
		delete toneDefault;
	if(mextensions != NULL)
		delete mextensions;
}

capstd::INTEGER* TimeDurationCharging::setmaxCallPeriodDuration(){
	if(mmaxCallPeriodDuration == NULL)
	{
		mmaxCallPeriodDuration = new capstd::INTEGER(1, 864000);
		mTagsPresent |= TimeDurationCharging_MAXCALLPERIODDURATION;
		return mmaxCallPeriodDuration;
	}
	else
		return mmaxCallPeriodDuration;

}

bool TimeDurationCharging::setmaxCallPeriodDuration(capstd::INTEGER* maxCallPeriodDuration){
	if(mmaxCallPeriodDuration == NULL)
	{
		return -1;
	}
	else
	{
		mmaxCallPeriodDuration = maxCallPeriodDuration;
		return true;
	}

}

capstd::Boolean* TimeDurationCharging::setreleaseIfdurationExceeded(){
	if(mreleaseIfdurationExceeded == NULL)
	{
		mreleaseIfdurationExceeded = new capstd::Boolean();
		mTagsPresent |= TimeDurationCharging_RELEASEIFDURATIONEXCEEDED;
		return mreleaseIfdurationExceeded;
	}
	else
		return mreleaseIfdurationExceeded;

}

bool TimeDurationCharging::setreleaseIfdurationExceeded(capstd::Boolean* releaseIfdurationExceeded){
	if(mreleaseIfdurationExceeded == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseIfdurationExceeded = releaseIfdurationExceeded;
		return true;
	}

}

capstd::INTEGER* TimeDurationCharging::settariffSwitchInterval(){
	if(mtariffSwitchInterval == NULL)
	{
		mtariffSwitchInterval = new capstd::INTEGER(1, 86400);
		mTagsPresent |= TimeDurationCharging_TARIFFSWITCHINTERVAL;
		return mtariffSwitchInterval;
	}
	else
		return mtariffSwitchInterval;

}

bool TimeDurationCharging::settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval){
	if(mtariffSwitchInterval == NULL)
	{
		return -1;
	}
	else
	{
		mtariffSwitchInterval = tariffSwitchInterval;
		return true;
	}

}

capstd::Boolean* TimeDurationCharging::settone(){
	if(mtone == NULL)
	{
		mtone = new capstd::Boolean();
		mTagsPresent |= TimeDurationCharging_TONE;
		return mtone;
	}
	else
		return mtone;

}

bool TimeDurationCharging::settone(capstd::Boolean* tone){
	if(mtone == NULL)
	{
		return -1;
	}
	else
	{
		mtone = tone;
		return true;
	}

}

Extensions* TimeDurationCharging::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= TimeDurationCharging_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool TimeDurationCharging::setextensions(Extensions* extensions){
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

capstd::INTEGER* TimeDurationCharging::getmaxCallPeriodDuration() {//throw(const char*)
	if(NULL == mmaxCallPeriodDuration)
		throw("Object maxCallPeriodDuration is NULL");
	else
		return mmaxCallPeriodDuration;
}

capstd::Boolean* TimeDurationCharging::getreleaseIfdurationExceeded() {//throw(const char*)
	if(NULL == mreleaseIfdurationExceeded)
		throw("Object releaseIfdurationExceeded is NULL");
	else
		return mreleaseIfdurationExceeded;
}

capstd::INTEGER* TimeDurationCharging::gettariffSwitchInterval() {//throw(const char*)
	if(NULL == mtariffSwitchInterval)
		throw("Object tariffSwitchInterval is NULL");
	else
		return mtariffSwitchInterval;
}

capstd::Boolean* TimeDurationCharging::gettone() {//throw(const char*)
	if(NULL == mtone)
		throw("Object tone is NULL");
	else
		return mtone;
}

Extensions* TimeDurationCharging::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool TimeDurationCharging::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TimeDurationCharging::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setmaxCallPeriodDuration())
					return -1;
				if(mmaxCallPeriodDuration->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setreleaseIfdurationExceeded())
					return -1;
				if(mreleaseIfdurationExceeded->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->settariffSwitchInterval())
					return -1;
				if(mtariffSwitchInterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->settone())
					return -1;
				if(mtone->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TimeDurationCharging Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TimeDurationCharging: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TimeDurationCharging::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TimeDurationCharging: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TimeDurationCharging_MAXCALLPERIODDURATION:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mmaxCallPeriodDuration->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationCharging_RELEASEIFDURATIONEXCEEDED:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseIfdurationExceeded->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationCharging_TARIFFSWITCHINTERVAL:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtariffSwitchInterval->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationCharging_TONE:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtone->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationCharging_EXTENSIONS:
				if(asn1_tag_encode(164, array) < 0)
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

	return 0;
}

int TimeDurationCharging::Display(int tab){
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
			case TimeDurationCharging_MAXCALLPERIODDURATION:
			{
				printf(temp, " ", "maxCallPeriodDuration");
				if(mmaxCallPeriodDuration->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationCharging_RELEASEIFDURATIONEXCEEDED:
			{
				printf(temp, " ", "releaseIfdurationExceeded");
				if(mreleaseIfdurationExceeded->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationCharging_TARIFFSWITCHINTERVAL:
			{
				printf(temp, " ", "tariffSwitchInterval");
				if(mtariffSwitchInterval->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationCharging_TONE:
			{
				printf(temp, " ", "tone");
				if(mtone->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationCharging_EXTENSIONS:
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

bool TimeDurationCharging::ValidateMandatory(char *errStr){
	if(NULL == mmaxCallPeriodDuration)
	{
		strcpy(errStr, "maxCallPeriodDuration");
		return false;
	}
	else if(NULL == mreleaseIfdurationExceeded)
	{
		strcpy(errStr, "releaseIfdurationExceeded");
		return false;
	}
	else if(NULL == mtone)
	{
		strcpy(errStr, "tone");
		return false;
	}

	return true;
}
TimeDurationChargingResult::TimeDurationChargingResult()
{
	mpartyToCharge = NULL;
	mtimeInformation = NULL;
	callActiveDefault = new capstd::Boolean();
	callActiveDefault->setValue(true);
	mcallActive = NULL;
	mcallReleasedAtTcpExpiry = false;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1, 0X0082, 0X0083, 0X00A4};
	mTagOptional = {false, false, false, true, true};
}

TimeDurationChargingResult::~TimeDurationChargingResult()
{
	if(mpartyToCharge != NULL)
		delete mpartyToCharge;
	if(mtimeInformation != NULL)
		delete mtimeInformation;
	if(mcallActive != NULL)
		delete mcallActive;
	if(callActiveDefault != NULL)
		delete callActiveDefault;
	if(mextensions != NULL)
		delete mextensions;
}

ReceivingSideID* TimeDurationChargingResult::setpartyToCharge(){
	if(mpartyToCharge == NULL)
	{
		mpartyToCharge = new ReceivingSideID();
		mTagsPresent |= TimeDurationChargingResult_PARTYTOCHARGE;
		return mpartyToCharge;
	}
	else
		return mpartyToCharge;

}

bool TimeDurationChargingResult::setpartyToCharge(ReceivingSideID* partyToCharge){
	if(mpartyToCharge == NULL)
	{
		return -1;
	}
	else
	{
		mpartyToCharge = partyToCharge;
		return true;
	}

}

TimeInformation* TimeDurationChargingResult::settimeInformation(){
	if(mtimeInformation == NULL)
	{
		mtimeInformation = new TimeInformation();
		mTagsPresent |= TimeDurationChargingResult_TIMEINFORMATION;
		return mtimeInformation;
	}
	else
		return mtimeInformation;

}

bool TimeDurationChargingResult::settimeInformation(TimeInformation* timeInformation){
	if(mtimeInformation == NULL)
	{
		return -1;
	}
	else
	{
		mtimeInformation = timeInformation;
		return true;
	}

}

capstd::Boolean* TimeDurationChargingResult::setcallActive(){
	if(mcallActive == NULL)
	{
		mcallActive = new capstd::Boolean();
		mTagsPresent |= TimeDurationChargingResult_CALLACTIVE;
		return mcallActive;
	}
	else
		return mcallActive;

}

bool TimeDurationChargingResult::setcallActive(capstd::Boolean* callActive){
	if(mcallActive == NULL)
	{
		return -1;
	}
	else
	{
		mcallActive = callActive;
		return true;
	}

}

bool* TimeDurationChargingResult::setcallReleasedAtTcpExpiry(){
	mcallReleasedAtTcpExpiry = true;
	mTagsPresent |= TimeDurationChargingResult_CALLRELEASEDATTCPEXPIRY;
	mNullcallReleasedAtTcpExpiry = true;
	return &mNullcallReleasedAtTcpExpiry;
}

bool TimeDurationChargingResult::setcallReleasedAtTcpExpiry(bool callReleasedAtTcpExpiry){
	mcallReleasedAtTcpExpiry = callReleasedAtTcpExpiry;
	return true;
}

Extensions* TimeDurationChargingResult::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= TimeDurationChargingResult_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool TimeDurationChargingResult::setextensions(Extensions* extensions){
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

ReceivingSideID* TimeDurationChargingResult::getpartyToCharge() {//throw(const char*)
	if(NULL == mpartyToCharge)
		throw("Object partyToCharge is NULL");
	else
		return mpartyToCharge;
}

TimeInformation* TimeDurationChargingResult::gettimeInformation() {//throw(const char*)
	if(NULL == mtimeInformation)
		throw("Object timeInformation is NULL");
	else
		return mtimeInformation;
}

capstd::Boolean* TimeDurationChargingResult::getcallActive() {//throw(const char*)
	if(NULL == mcallActive)
		throw("Object callActive is NULL");
	else
		return mcallActive;
}

bool TimeDurationChargingResult::getcallReleasedAtTcpExpiry() {
	return mcallReleasedAtTcpExpiry;
}

Extensions* TimeDurationChargingResult::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool TimeDurationChargingResult::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TimeDurationChargingResult::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setpartyToCharge())
					return -1;
				if(mpartyToCharge->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->settimeInformation())
					return -1;
				if(mtimeInformation->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setcallActive())
					return -1;
				if(mcallActive->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0083:
				if(NULL == this->setcallReleasedAtTcpExpiry())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TimeDurationChargingResult Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TimeDurationChargingResult: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TimeDurationChargingResult::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TimeDurationChargingResult: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TimeDurationChargingResult_PARTYTOCHARGE:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpartyToCharge->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationChargingResult_TIMEINFORMATION:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeInformation->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationChargingResult_CALLACTIVE:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallActive->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeDurationChargingResult_CALLRELEASEDATTCPEXPIRY:
				if(asn1_tag_encode(131, array) < 0)
					return -1;
				asn1_null_encode(array);
				break;
			case TimeDurationChargingResult_EXTENSIONS:
				if(asn1_tag_encode(164, array) < 0)
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

	return 0;
}

int TimeDurationChargingResult::Display(int tab){
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
			case TimeDurationChargingResult_PARTYTOCHARGE:
			{
				printf(temp, " ", "partyToCharge");
				if(mpartyToCharge->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationChargingResult_TIMEINFORMATION:
			{
				printf(temp, " ", "timeInformation");
				if(mtimeInformation->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationChargingResult_CALLACTIVE:
			{
				printf(temp, " ", "callActive");
				if(mcallActive->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeDurationChargingResult_CALLRELEASEDATTCPEXPIRY:
			{
				printf(temp, " ", "callReleasedAtTcpExpiry");
				break;
			}
			case TimeDurationChargingResult_EXTENSIONS:
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

bool TimeDurationChargingResult::ValidateMandatory(char *errStr){
	if(NULL == mpartyToCharge)
	{
		strcpy(errStr, "partyToCharge");
		return false;
	}
	else if(NULL == mtimeInformation)
	{
		strcpy(errStr, "timeInformation");
		return false;
	}
	else if(NULL == mcallActive)
	{
		strcpy(errStr, "callActive");
		return false;
	}

	return true;
}
TimeGPRSIfTariffSwitch::TimeGPRSIfTariffSwitch()
{
	mtimeGPRSSinceLastTariffSwitch = NULL;
	mtimeGPRSTariffSwitchInterval = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, true};
}

TimeGPRSIfTariffSwitch::~TimeGPRSIfTariffSwitch()
{
	if(mtimeGPRSSinceLastTariffSwitch != NULL)
		delete mtimeGPRSSinceLastTariffSwitch;
	if(mtimeGPRSTariffSwitchInterval != NULL)
		delete mtimeGPRSTariffSwitchInterval;
}

capstd::INTEGER* TimeGPRSIfTariffSwitch::settimeGPRSSinceLastTariffSwitch(){
	if(mtimeGPRSSinceLastTariffSwitch == NULL)
	{
		mtimeGPRSSinceLastTariffSwitch = new capstd::INTEGER(0, 86400);
		mTagsPresent |= TimeGPRSIfTariffSwitch_TIMEGPRSSINCELASTTARIFFSWITCH;
		return mtimeGPRSSinceLastTariffSwitch;
	}
	else
		return mtimeGPRSSinceLastTariffSwitch;

}

bool TimeGPRSIfTariffSwitch::settimeGPRSSinceLastTariffSwitch(capstd::INTEGER* timeGPRSSinceLastTariffSwitch){
	if(mtimeGPRSSinceLastTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeGPRSSinceLastTariffSwitch = timeGPRSSinceLastTariffSwitch;
		return true;
	}

}

capstd::INTEGER* TimeGPRSIfTariffSwitch::settimeGPRSTariffSwitchInterval(){
	if(mtimeGPRSTariffSwitchInterval == NULL)
	{
		mtimeGPRSTariffSwitchInterval = new capstd::INTEGER(0, 86400);
		mTagsPresent |= TimeGPRSIfTariffSwitch_TIMEGPRSTARIFFSWITCHINTERVAL;
		return mtimeGPRSTariffSwitchInterval;
	}
	else
		return mtimeGPRSTariffSwitchInterval;

}

bool TimeGPRSIfTariffSwitch::settimeGPRSTariffSwitchInterval(capstd::INTEGER* timeGPRSTariffSwitchInterval){
	if(mtimeGPRSTariffSwitchInterval == NULL)
	{
		return -1;
	}
	else
	{
		mtimeGPRSTariffSwitchInterval = timeGPRSTariffSwitchInterval;
		return true;
	}

}

capstd::INTEGER* TimeGPRSIfTariffSwitch::gettimeGPRSSinceLastTariffSwitch() {//throw(const char*)
	if(NULL == mtimeGPRSSinceLastTariffSwitch)
		throw("Object timeGPRSSinceLastTariffSwitch is NULL");
	else
		return mtimeGPRSSinceLastTariffSwitch;
}

capstd::INTEGER* TimeGPRSIfTariffSwitch::gettimeGPRSTariffSwitchInterval() {//throw(const char*)
	if(NULL == mtimeGPRSTariffSwitchInterval)
		throw("Object timeGPRSTariffSwitchInterval is NULL");
	else
		return mtimeGPRSTariffSwitchInterval;
}

bool TimeGPRSIfTariffSwitch::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TimeGPRSIfTariffSwitch::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->settimeGPRSSinceLastTariffSwitch())
					return -1;
				if(mtimeGPRSSinceLastTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->settimeGPRSTariffSwitchInterval())
					return -1;
				if(mtimeGPRSTariffSwitchInterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TimeGPRSIfTariffSwitch Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TimeGPRSIfTariffSwitch: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TimeGPRSIfTariffSwitch::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TimeGPRSIfTariffSwitch: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TimeGPRSIfTariffSwitch_TIMEGPRSSINCELASTTARIFFSWITCH:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeGPRSSinceLastTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeGPRSIfTariffSwitch_TIMEGPRSTARIFFSWITCHINTERVAL:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeGPRSTariffSwitchInterval->Encode(array) < 0) || 
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

	return 0;
}

int TimeGPRSIfTariffSwitch::Display(int tab){
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
			case TimeGPRSIfTariffSwitch_TIMEGPRSSINCELASTTARIFFSWITCH:
			{
				printf(temp, " ", "timeGPRSSinceLastTariffSwitch");
				if(mtimeGPRSSinceLastTariffSwitch->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeGPRSIfTariffSwitch_TIMEGPRSTARIFFSWITCHINTERVAL:
			{
				printf(temp, " ", "timeGPRSTariffSwitchInterval");
				if(mtimeGPRSTariffSwitchInterval->Display(tab+1) < 0)
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

bool TimeGPRSIfTariffSwitch::ValidateMandatory(char *errStr){
	if(NULL == mtimeGPRSSinceLastTariffSwitch)
	{
		strcpy(errStr, "timeGPRSSinceLastTariffSwitch");
		return false;
	}

	return true;
}
TimeIfTariffSwitch::TimeIfTariffSwitch()
{
	mtimeSinceTariffSwitch = NULL;
	mtariffSwitchInterval = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, true};
}

TimeIfTariffSwitch::~TimeIfTariffSwitch()
{
	if(mtimeSinceTariffSwitch != NULL)
		delete mtimeSinceTariffSwitch;
	if(mtariffSwitchInterval != NULL)
		delete mtariffSwitchInterval;
}

capstd::INTEGER* TimeIfTariffSwitch::settimeSinceTariffSwitch(){
	if(mtimeSinceTariffSwitch == NULL)
	{
		mtimeSinceTariffSwitch = new capstd::INTEGER(0, 864000);
		mTagsPresent |= TimeIfTariffSwitch_TIMESINCETARIFFSWITCH;
		return mtimeSinceTariffSwitch;
	}
	else
		return mtimeSinceTariffSwitch;

}

bool TimeIfTariffSwitch::settimeSinceTariffSwitch(capstd::INTEGER* timeSinceTariffSwitch){
	if(mtimeSinceTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeSinceTariffSwitch = timeSinceTariffSwitch;
		return true;
	}

}

capstd::INTEGER* TimeIfTariffSwitch::settariffSwitchInterval(){
	if(mtariffSwitchInterval == NULL)
	{
		mtariffSwitchInterval = new capstd::INTEGER(1, 864000);
		mTagsPresent |= TimeIfTariffSwitch_TARIFFSWITCHINTERVAL;
		return mtariffSwitchInterval;
	}
	else
		return mtariffSwitchInterval;

}

bool TimeIfTariffSwitch::settariffSwitchInterval(capstd::INTEGER* tariffSwitchInterval){
	if(mtariffSwitchInterval == NULL)
	{
		return -1;
	}
	else
	{
		mtariffSwitchInterval = tariffSwitchInterval;
		return true;
	}

}

capstd::INTEGER* TimeIfTariffSwitch::gettimeSinceTariffSwitch() {//throw(const char*)
	if(NULL == mtimeSinceTariffSwitch)
		throw("Object timeSinceTariffSwitch is NULL");
	else
		return mtimeSinceTariffSwitch;
}

capstd::INTEGER* TimeIfTariffSwitch::gettariffSwitchInterval() {//throw(const char*)
	if(NULL == mtariffSwitchInterval)
		throw("Object tariffSwitchInterval is NULL");
	else
		return mtariffSwitchInterval;
}

bool TimeIfTariffSwitch::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TimeIfTariffSwitch::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->settimeSinceTariffSwitch())
					return -1;
				if(mtimeSinceTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->settariffSwitchInterval())
					return -1;
				if(mtariffSwitchInterval->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: TimeIfTariffSwitch Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TimeIfTariffSwitch: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TimeIfTariffSwitch::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TimeIfTariffSwitch: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TimeIfTariffSwitch_TIMESINCETARIFFSWITCH:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeSinceTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case TimeIfTariffSwitch_TARIFFSWITCHINTERVAL:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtariffSwitchInterval->Encode(array) < 0) || 
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

	return 0;
}

int TimeIfTariffSwitch::Display(int tab){
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
			case TimeIfTariffSwitch_TIMESINCETARIFFSWITCH:
			{
				printf(temp, " ", "timeSinceTariffSwitch");
				if(mtimeSinceTariffSwitch->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeIfTariffSwitch_TARIFFSWITCHINTERVAL:
			{
				printf(temp, " ", "tariffSwitchInterval");
				if(mtariffSwitchInterval->Display(tab+1) < 0)
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

bool TimeIfTariffSwitch::ValidateMandatory(char *errStr){
	if(NULL == mtimeSinceTariffSwitch)
	{
		strcpy(errStr, "timeSinceTariffSwitch");
		return false;
	}

	return true;
}
TimeInformation::TimeInformation()
{
	mtimeIfNoTariffSwitch = NULL;
	mtimeIfTariffSwitch = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X00A1};
}

TimeInformation::~TimeInformation()
{
	if(mtimeIfNoTariffSwitch != NULL)
		delete mtimeIfNoTariffSwitch;
	if(mtimeIfTariffSwitch != NULL)
		delete mtimeIfTariffSwitch;
}

capstd::INTEGER* TimeInformation::settimeIfNoTariffSwitch(){
if(mParamSet == true)
	{
		if(mtimeIfNoTariffSwitch != NULL)
			return mtimeIfNoTariffSwitch;
		else
			return NULL;
	}
	if(mtimeIfNoTariffSwitch == NULL)
	{
		mtimeIfNoTariffSwitch = new capstd::INTEGER(0, 864000);
		mTagsPresent |= TimeInformation_TIMEIFNOTARIFFSWITCH;
		mParamSet = true;
		return mtimeIfNoTariffSwitch;
	}
}

bool TimeInformation::settimeIfNoTariffSwitch(capstd::INTEGER* timeIfNoTariffSwitch){
	if(mtimeIfNoTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeIfNoTariffSwitch = timeIfNoTariffSwitch;
		return true;
	}

}

TimeIfTariffSwitch* TimeInformation::settimeIfTariffSwitch(){
if(mParamSet == true)
	{
		if(mtimeIfTariffSwitch != NULL)
			return mtimeIfTariffSwitch;
		else
			return NULL;
	}
	if(mtimeIfTariffSwitch == NULL)
	{
		mtimeIfTariffSwitch = new TimeIfTariffSwitch();
		mTagsPresent |= TimeInformation_TIMEIFTARIFFSWITCH;
		mParamSet = true;
		return mtimeIfTariffSwitch;
	}
}

bool TimeInformation::settimeIfTariffSwitch(TimeIfTariffSwitch* timeIfTariffSwitch){
	if(mtimeIfTariffSwitch == NULL)
	{
		return -1;
	}
	else
	{
		mtimeIfTariffSwitch = timeIfTariffSwitch;
		return true;
	}

}

capstd::INTEGER* TimeInformation::gettimeIfNoTariffSwitch() {//throw(const char*)
	if(NULL == mtimeIfNoTariffSwitch)
		throw("Object timeIfNoTariffSwitch is NULL");
	else
		return mtimeIfNoTariffSwitch;
}

TimeIfTariffSwitch* TimeInformation::gettimeIfTariffSwitch() {//throw(const char*)
	if(NULL == mtimeIfTariffSwitch)
		throw("Object timeIfTariffSwitch is NULL");
	else
		return mtimeIfTariffSwitch;
}

bool TimeInformation::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int TimeInformation::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
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
	while(length && decode && !lParamSet)
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
				if(NULL == this->settimeIfNoTariffSwitch())
					return -1;
				if(mtimeIfNoTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->settimeIfTariffSwitch())
					return -1;
				if(mtimeIfTariffSwitch->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: TimeInformation Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("TimeInformation: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int TimeInformation::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("TimeInformation: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case TimeInformation_TIMEIFNOTARIFFSWITCH:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeIfNoTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case TimeInformation_TIMEIFTARIFFSWITCH:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtimeIfTariffSwitch->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
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

	return 0;
}

int TimeInformation::Display(int tab){
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
			case TimeInformation_TIMEIFNOTARIFFSWITCH:
			{
				printf(temp, " ", "timeIfNoTariffSwitch");
				if(mtimeIfNoTariffSwitch->Display(tab+1) < 0)
					return -1;
				break;
			}
			case TimeInformation_TIMEIFTARIFFSWITCH:
			{
				printf(temp, " ", "timeIfTariffSwitch");
				if(mtimeIfTariffSwitch->Display(tab+1) < 0)
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

bool TimeInformation::ValidateMandatory(char *errStr){

	return true;
}

TimerID::TimerID()
{
	mTag = 0X000A;
}

TimerID::~TimerID()
{
}

bool TimerID::setValue(TIMERID val)
{
	mValue = val;
	return true;
}

TIMERID TimerID::getValue()
{
	return mValue;
}

int TimerID::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (TIMERID)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int TimerID::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int TimerID::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", TIMERID_str(mValue), mValue);
	return 0;
}

Tone::Tone()
{
	mtoneID = NULL;
	mduration = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X0081};
	mTagOptional = {false, true};
}

Tone::~Tone()
{
	if(mtoneID != NULL)
		delete mtoneID;
	if(mduration != NULL)
		delete mduration;
}

capstd::INTEGER* Tone::settoneID(){
	if(mtoneID == NULL)
	{
		mtoneID = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= Tone_TONEID;
		return mtoneID;
	}
	else
		return mtoneID;

}

bool Tone::settoneID(capstd::INTEGER* toneID){
	if(mtoneID == NULL)
	{
		return -1;
	}
	else
	{
		mtoneID = toneID;
		return true;
	}

}

capstd::INTEGER* Tone::setduration(){
	if(mduration == NULL)
	{
		mduration = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= Tone_DURATION;
		return mduration;
	}
	else
		return mduration;

}

bool Tone::setduration(capstd::INTEGER* duration){
	if(mduration == NULL)
	{
		return -1;
	}
	else
	{
		mduration = duration;
		return true;
	}

}

capstd::INTEGER* Tone::gettoneID() {//throw(const char*)
	if(NULL == mtoneID)
		throw("Object toneID is NULL");
	else
		return mtoneID;
}

capstd::INTEGER* Tone::getduration() {//throw(const char*)
	if(NULL == mduration)
		throw("Object duration is NULL");
	else
		return mduration;
}

bool Tone::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int Tone::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->settoneID())
					return -1;
				if(mtoneID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setduration())
					return -1;
				if(mduration->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: Tone Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("Tone: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int Tone::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("Tone: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case Tone_TONEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mtoneID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case Tone_DURATION:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mduration->Encode(array) < 0) || 
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

	return 0;
}

int Tone::Display(int tab){
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
			case Tone_TONEID:
			{
				printf(temp, " ", "toneID");
				if(mtoneID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case Tone_DURATION:
			{
				printf(temp, " ", "duration");
				if(mduration->Display(tab+1) < 0)
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

bool Tone::ValidateMandatory(char *errStr){
	if(NULL == mtoneID)
	{
		strcpy(errStr, "toneID");
		return false;
	}

	return true;
}

Used_RAT_Type::Used_RAT_Type()
{
	mTag = 0X000A;
}

Used_RAT_Type::~Used_RAT_Type()
{
}

bool Used_RAT_Type::setValue(USED_RAT_TYPE val)
{
	mValue = val;
	return true;
}

USED_RAT_TYPE Used_RAT_Type::getValue()
{
	return mValue;
}

int Used_RAT_Type::Decode(capstd::byteArray *array, unsigned *bytesParsed){
	unsigned length = 0, lengthSize = 0;

	bool definite = true;
	(*bytesParsed) = 0;

	lengthSize = asn1_length_decode(array, &definite, &length);
	if(-1 == lengthSize)
		return -1;
	if(length != 1)
	{
		errno = 1;
		return -1;
	}
	mValue = (USED_RAT_TYPE)asn1_get_octet(array);
	(*bytesParsed) = lengthSize + length;
	return 0;
}

int Used_RAT_Type::Encode(capstd::byteArray *array){
	array->byte[array->offset++] = mValue;
	array->size += 1;
	return 0;
}

int Used_RAT_Type::Display(int tab){
	char temp[30];
	char temp1[100];
	sprintf(temp, "%%%ds %%s %%s (%%d)\n", tab * 3);
	printf(temp, " ", "Enum Value is : ", USED_RAT_TYPE_str(mValue), mValue);
	return 0;
}

VariableMessage::VariableMessage()
{
	melementaryMessageID = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080};
	mTagOptional = {false};
}

VariableMessage::~VariableMessage()
{
	if(melementaryMessageID != NULL)
		delete melementaryMessageID;
}

capstd::INTEGER* VariableMessage::setelementaryMessageID(){
	if(melementaryMessageID == NULL)
	{
		melementaryMessageID = new capstd::INTEGER(0, 2147483647);
		mTagsPresent |= VariableMessage_ELEMENTARYMESSAGEID;
		return melementaryMessageID;
	}
	else
		return melementaryMessageID;

}

bool VariableMessage::setelementaryMessageID(capstd::INTEGER* elementaryMessageID){
	if(melementaryMessageID == NULL)
	{
		return -1;
	}
	else
	{
		melementaryMessageID = elementaryMessageID;
		return true;
	}

}

capstd::INTEGER* VariableMessage::getelementaryMessageID() {//throw(const char*)
	if(NULL == melementaryMessageID)
		throw("Object elementaryMessageID is NULL");
	else
		return melementaryMessageID;
}

bool VariableMessage::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int VariableMessage::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

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
				if(NULL == this->setelementaryMessageID())
					return -1;
				if(melementaryMessageID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: VariableMessage Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("VariableMessage: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int VariableMessage::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("VariableMessage: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case VariableMessage_ELEMENTARYMESSAGEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((melementaryMessageID->Encode(array) < 0) || 
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

	return 0;
}

int VariableMessage::Display(int tab){
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
			case VariableMessage_ELEMENTARYMESSAGEID:
			{
				printf(temp, " ", "elementaryMessageID");
				if(melementaryMessageID->Display(tab+1) < 0)
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

bool VariableMessage::ValidateMandatory(char *errStr){
	if(NULL == melementaryMessageID)
	{
		strcpy(errStr, "elementaryMessageID");
		return false;
	}

	return true;
}

bcsmEvents::bcsmEvents()
{
	mTag = 0X0030;
	mCounter = 0;
	mCurrentLocation = 0;
	mMinSize = 1;
	mMaxSize = 10;
	mParamList.clear();
}

bcsmEvents::~bcsmEvents()
{
	vector<BCSMEvent *>::iterator lParam = mParamList.begin();
	while(mParamList.end() != lParam)
	{
		delete *lParam;
		lParam++;
	}
	mParamList.clear();
}

BCSMEvent* bcsmEvents::getBCSMEvent()//throw(const char*)
{
	if(mParamList.size() > 0)
	{
		vector<BCSMEvent *>::iterator lParam = mParamList.begin();
		mCurrentLocation = 0;
		mCurrentLocation++;
		return *lParam;
	}
	else
		throw("Object BCSMEvent is NULL");
}

BCSMEvent* bcsmEvents::getNextBCSMEvent()//throw(const char*)
{
	if(mParamList.size() > mCurrentLocation)
	{
		vector<BCSMEvent *>::iterator lParam = mParamList.begin();
		lParam = lParam + (mCurrentLocation++);
		return *lParam;
	}
	else
		throw("Object BCSMEvent is NULL");
}

BCSMEvent* bcsmEvents::getBCSMEventAtLocation(unsigned location)//throw(const char*)
{
	if(mParamList.size() > location)
	{
		vector<BCSMEvent *>::iterator lParam = mParamList.begin();
		return *(lParam+location);
	}
	else
		throw("Object BCSMEvent is NULL");
}

unsigned bcsmEvents::getNoOfBCSMEvent()
{
	return mParamList.size();
}

bool bcsmEvents::CheckBoundary()
{
	if(mCounter < mMinSize || mCounter > mMaxSize)
		return false;

	return true;
}

BCSMEvent* bcsmEvents::setNewBCSMEvent()
{
	mBCSMEvent = new BCSMEvent();
	if(NULL == mBCSMEvent)
		return NULL;
	mParamList.push_back(mBCSMEvent);
	mCounter++;
	return mBCSMEvent;
}

BCSMEvent* bcsmEvents::setBCSMEvent()
{
	if(NULL == mBCSMEvent)
		return NULL;
	return mBCSMEvent;
}

int bcsmEvents::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				this->setNewBCSMEvent();
				if(mBCSMEvent->Decode(array, &bytesDecoded) < 0)
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
int bcsmEvents::Encode(capstd::byteArray *array){
	unsigned lTemp = 0, tagsPresent = 1;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	vector<BCSMEvent *>::iterator lParam = mParamList.begin();
	while(lParam != mParamList.end())
	{
		if(asn1_tag_encode(48, array) < 0)
			return -1;
		lLengthOffset = array->offset++;
		if(((*lParam)->Encode(array) < 0) || 
			(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0))
			return -1;
		lParam++;
	}
	return 0;
}

int bcsmEvents::Display(int tab){
	char temp[30];
	sprintf(temp, "%%%ds %%s\n", tab * 3);
	vector<BCSMEvent *>::iterator lParam = mParamList.begin();

	while(lParam != mParamList.end())
	{
		printf(temp, " ", "BCSMEvent");
		(*lParam)->Display(tab+1);
		lParam++;
	}
}

