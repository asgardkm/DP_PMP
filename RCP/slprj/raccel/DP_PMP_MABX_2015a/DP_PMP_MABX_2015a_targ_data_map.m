  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% rtP.Constant11_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant10_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Constant9_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Constant5_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Constant3_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Constant6_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Constant7_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Constant8_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Constant12_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.Constant4_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.Constant13_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.Constant17_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.Constant_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.Constant18_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 812;
	
	  ;% rtP.Constant1_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 1612;
	
	  ;% rtP.Step_Time
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 10412;
	
	  ;% rtP.Step_Y0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 10413;
	
	  ;% rtP.Step_YFinal
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 10414;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtB.d5jctfz5jv
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ctauc4dyfo
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.fylwekf5vd
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.joewxwm0m5
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fbder3zpch
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.hkwzdlepko.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gzvuolh0vm.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cxjmyxwwya
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.n0e1c5dddi
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 122533255;
  targMap.checksum1 = 2387482475;
  targMap.checksum2 = 1929481518;
  targMap.checksum3 = 1921104030;

