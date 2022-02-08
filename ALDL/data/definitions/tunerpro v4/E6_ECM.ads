//--------------------------------------------------------------------------------------
// Created by TunerPro. Hand editing is *not* recommended or supported.
//--------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
//--------------------------------- HEADER ------------------------------------
//--------------------------------------------------------------------------------------

{
	fDefFrmtVers             =1.21;
	strDefVersion            =Version 1.0;
	strDefTitle              =A201 $E6 ECM;
	strAuthor                =Robert Saar;
	strEngine                =L03, L05, L35, LB4;
	strYear                  =1993;
	strVINCode               =H/K/W/Z;
	strCodeMask              =$E6;
	strComments              =questions/comments should be directed to robertisaar@yahoo.com;
	iBaud                    =8192;
	dwFlags                  =0x00000000;
	dwCSID                   =0x00015118;
	btNumDumpRequests        =2;

	strCommandName           =Mode 1 (Tansmit Data);
	rgbtCommand              =F4, 57, 01, 00;
	iTotalBytesInCommand     =5;
	bChecksumCommand         =1;
	iNumBytesInPayload       =63;
	iNumBytesBeforePayload   =3;
	bMaster                  =1;
	bMonitor                 =1;
	iChainTo                 =-1;

	strCommandName           =Mode 10 (Clear Codes);
	rgbtCommand              =F4, 56, 0A;
	iTotalBytesInCommand     =4;
	bChecksumCommand         =1;
	iNumBytesInPayload       =3;
	iNumBytesBeforePayload   =0;
	bMaster                  =0;
	bMonitor                 =0;
	iChainTo                 =-1;
}

//--------------------------------------------------------------------------------------
//---------------------------------- DASH -------------------------------------
//--------------------------------------------------------------------------------------

{
	dwItemType               =6;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =0;

	btNumGauges              =6;
	strIDsDisplayed          =78,44,73,67,41,45,;
	btNumMonitors            =4;
	strMonsDisplayed         =78,79,80,73,;
}

//--------------------------------------------------------------------------------------
//--------------------------------- VALUES ------------------------------------
//--------------------------------------------------------------------------------------

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =4;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Important=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =67;

	btByteNumber             =31;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =Vehicle Speed;
	strUnitLabel             =MPH;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =73;

	btByteNumber             =34;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =25.000000;
	dOffset                  =0.000000;
	strItemTitle             =Engine Speed;
	strUnitLabel             =RPM;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =44;

	btByteNumber             =17;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.019608;
	dOffset                  =0.000000;
	strItemTitle             =TPS;
	strUnitLabel             =Volts;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =78;

	btByteNumber             =42;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.392157;
	dOffset                  =0.000000;
	strItemTitle             =TPS;
	strUnitLabel             =%;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =5;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Temps C=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =41;

	btByteNumber             =15;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.750000;
	dOffset                  =-40.000000;
	strItemTitle             =Coolant Temp;
	strUnitLabel             =C;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =88;

	btByteNumber             =63;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.750000;
	dOffset                  =-40.000000;
	strItemTitle             =MAT;
	strUnitLabel             =C;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =6;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Temps F=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =42;

	btByteNumber             =15;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.350000;
	dOffset                  =-40.000000;
	strItemTitle             =Coolant Temp;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =89;

	btByteNumber             =63;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.350000;
	dOffset                  =-40.000000;
	strItemTitle             =MAT;
	strUnitLabel             =F;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =7;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Air/Fuel=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =45;

	btByteNumber             =18;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.019608;
	dOffset                  =0.000000;
	strItemTitle             =MAP;
	strUnitLabel             =Volts;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =46;

	btByteNumber             =18;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.369000;
	dOffset                  =10.354000;
	strItemTitle             =MAP;
	strUnitLabel             =kPa;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =57;

	btByteNumber             =27;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.019608;
	dOffset                  =0.000000;
	strItemTitle             =Barometric;
	strUnitLabel             =Volts;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =58;

	btByteNumber             =27;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.369000;
	dOffset                  =10.354000;
	strItemTitle             =Barometric;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =47;

	btByteNumber             =19;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =4.420000;
	dOffset                  =0.000000;
	strItemTitle             =O2 Voltage;
	strUnitLabel             =mV;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =83;

	btByteNumber             =54;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =BLM Cell;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =84;

	btByteNumber             =55;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =BLM;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =81;

	btByteNumber             =49;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =INT;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =82;

	btByteNumber             =51;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =Rich/Lean Transitions;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =85;

	btByteNumber             =56;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.100000;
	dOffset                  =0.000000;
	strItemTitle             =Target Air/Fuel Ratio;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =86;

	btByteNumber             =57;
	btMessageNumber          =1;
	dwItemSizeBits           =16;
	dwOperation              =0;
	dFactor                  =0.015259;
	dOffset                  =0.000000;
	strItemTitle             =BPW;
	strUnitLabel             =mSec;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =2550;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =8;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Spark=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =79;

	btByteNumber             =45;
	btMessageNumber          =1;
	dwItemSizeBits           =16;
	dwOperation              =0;
	dFactor                  =0.352941;
	dOffset                  =0.000000;
	strItemTitle             =Spark Advance;
	strUnitLabel             =*;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =80;

	btByteNumber             =47;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =Knock Counter;
	strUnitLabel             =;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =9;

	btByteNumber             =0;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             ======Misc=====;
	strUnitLabel             =Units;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =43;

	btByteNumber             =16;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.100000;
	dOffset                  =0.000000;
	strItemTitle             =Battery Voltage;
	strUnitLabel             =Volts;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =72;

	btByteNumber             =33;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.100000;
	dOffset                  =0.000000;
	strItemTitle             =Fuel Pump Voltage;
	strUnitLabel             =Volts;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =10;

	btByteNumber             =5;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =3;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =IAC Position;
	strUnitLabel             =Steps;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =74;

	btByteNumber             =37;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.392157;
	dOffset                  =0.000000;
	strItemTitle             =EGR Duty Cycle;
	strUnitLabel             =%;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =76;

	btByteNumber             =39;
	btMessageNumber          =1;
	dwItemSizeBits           =16;
	dwOperation              =0;
	dFactor                  =1.000000;
	dOffset                  =0.000000;
	strItemTitle             =Engine Run Time;
	strUnitLabel             =Seconds;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255000;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =77;

	btByteNumber             =41;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =12.500000;
	dOffset                  =0.000000;
	strItemTitle             =Desired Idle Speed;
	strUnitLabel             =RPM;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

{
	dwItemType               =1;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =87;

	btByteNumber             =62;
	btMessageNumber          =1;
	dwItemSizeBits           =8;
	dwOperation              =0;
	dFactor                  =0.392157;
	dOffset                  =0.000000;
	strItemTitle             =CCP Duty Cycle;
	strUnitLabel             =%;
	dwAlarmHigh              =255;
	bAlarmHighENable         =0;
	dwAlarmLow               =0;
	bAlarmLowEnable          =0;
	iRangeHigh               =255;
	iRangeLow                =0;
	iLookupTableIndex        =-1;
}

//--------------------------------------------------------------------------------------
//---------------------------------- BITS -------------------------------------
//--------------------------------------------------------------------------------------

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =1;

	btByteNumber             =0;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             ======Status=====;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =1;
	strBitClearTitle         =0;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =2;

	btByteNumber             =3;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =O2 Status;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =1;
	strBitSetTitle           =READY;
	strBitClearTitle         =NOT READY;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =3;

	btByteNumber             =4;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =A/C;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ENGAGED;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =48;

	btByteNumber             =20;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =Decel Enleanment;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =49;

	btByteNumber             =20;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =Power Enrichment;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =50;

	btByteNumber             =20;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =Accel Enrichment;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =51;

	btByteNumber             =20;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =Async Fuel;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =52;

	btByteNumber             =24;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =Idle Spark;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =Yes;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =53;

	btByteNumber             =25;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =A/C Request;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =54;

	btByteNumber             =25;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =Brake Switch;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =PRESSED;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =55;

	btByteNumber             =25;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =4WD Low;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =56;

	btByteNumber             =26;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =DFCO;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =59;

	btByteNumber             =28;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =CCP;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =60;

	btByteNumber             =29;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =Rich/Lean;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =RICH;
	strBitClearTitle         =LEAN;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =61;

	btByteNumber             =29;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =Loop Status;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =1;
	strBitSetTitle           =CLOSED;
	strBitClearTitle         =OPEN;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =71;

	btByteNumber             =32;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =Force Motor;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ENABLED;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =75;

	btByteNumber             =38;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =Fire Mode;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =SINGLE;
	strBitClearTitle         =QUASI;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =62;

	btByteNumber             =0;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =TCC;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =1;
	strBitClearTitle         =0;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =63;

	btByteNumber             =30;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =TCC Forced Off;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =64;

	btByteNumber             =30;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =TCC in Releasing Mode;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =65;

	btByteNumber             =30;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =TCC in Lock/Adjust Mode;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =66;

	btByteNumber             =30;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =TCC in Locking Mode;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =68;

	btByteNumber             =0;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =Shift Solenoids;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =1;
	strBitClearTitle         =0;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =69;

	btByteNumber             =32;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =A;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =70;

	btByteNumber             =32;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =B;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =YES;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =1;
	bVisible                 =1;
	dwUniqueID               =11;

	btByteNumber             =0;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             ======Codes=====;
	bAlarmSetEnable          =0;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =1;
	strBitClearTitle         =0;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =16;

	btByteNumber             =6;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =13 O2 Sensor;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =15;

	btByteNumber             =6;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =14 Coolant High;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =14;

	btByteNumber             =6;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =15 Coolant Low;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =13;

	btByteNumber             =6;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =16 2002PPM Speed Sensor;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =12;

	btByteNumber             =6;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =21 TPS High;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =21;

	btByteNumber             =7;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =22 TPS Low;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =20;

	btByteNumber             =7;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =23 MAT Low;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =19;

	btByteNumber             =7;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =24 VSS;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =18;

	btByteNumber             =7;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =25 MAT High;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =17;

	btByteNumber             =7;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =28 Pressure Switch Manifold;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =28;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =31 Governer;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =27;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =32 EGR;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =26;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =33 MAP High;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =25;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =34 MAP Low;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =24;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =3;
	strItemTitle             =35 IAC;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =23;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =37 Brake On;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =22;

	btByteNumber             =8;
	btMessageNumber          =1;
	btBitNumber              =0;
	strItemTitle             =38 Brake Off;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =35;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =7;
	strItemTitle             =39 TCC Off;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =0;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =34;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =6;
	strItemTitle             =41 1X (Cam Sensor);
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =33;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =42 Knock Sensor;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =32;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =43 ESC;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =31;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =3;
	strItemTitle             =44 O2 Lean;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =30;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =2;
	strItemTitle             =45 O2 Rich;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =29;

	btByteNumber             =9;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =46 VATS;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =40;

	btByteNumber             =10;
	btMessageNumber          =1;
	btBitNumber              =5;
	strItemTitle             =51 PROM;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =39;

	btByteNumber             =10;
	btMessageNumber          =1;
	btBitNumber              =4;
	strItemTitle             =52 Voltage High-Long Term;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =38;

	btByteNumber             =10;
	btMessageNumber          =1;
	btBitNumber              =3;
	strItemTitle             =53 Voltage High;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =37;

	btByteNumber             =10;
	btMessageNumber          =1;
	btBitNumber              =2;
	strItemTitle             =54 Fuel Pump Relay;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

{
	dwItemType               =2;
	strItemComments          =<Comments>;
	bSeparator               =0;
	bVisible                 =1;
	dwUniqueID               =36;

	btByteNumber             =10;
	btMessageNumber          =1;
	btBitNumber              =1;
	strItemTitle             =55 ADU;
	bAlarmSetEnable          =1;
	bAlarmNotSetEnable       =0;
	strBitSetTitle           =ERROR;
	strBitClearTitle         =;
}

//--------------------------------------------------------------------------------------
//---------------------------- LOOKUP TABLES ----------------------------------
//--------------------------------------------------------------------------------------

