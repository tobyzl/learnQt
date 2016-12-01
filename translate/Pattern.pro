QMAKEVERSION = $$[QMAKE_VERSION]
ISQT4 = $$find(QMAKEVERSION,^[2-9])
isEmpty( ISQT4 ){
error("Use the qmake include with Qt4.4 or greater,on Ubuntu that is qmake-qt4");
}

TEMPLATE = subdirs
SUBDIRS = ../PAD7/Common/Projects/PadConjoin/PadConjoin.pro \
          ../PAD7/Common/Projects/PadCore/PadCore.pro \
		  ../PAD7/Common/Projects/PadDbg/PadDbg.pro \
		  ../PAD7/Common/Projects/PadGeo/PadGeo.pro \
		  ../PAD7/Common/Projects/PadHelp/PadHelp.pro \
		  ../PAD7/Common/Projects/PadImpExp/PadImpExp.pro \
		  ../PAD7/Common/Projects/PadNester/PadNester.pro \
		  ../PAD7/Common/Projects/PadPlotter/PadPlotter.pro \
       	  ../PAD7/Pattern/Projects/PatternAssistant/PatternAssistant.pro \  
          ../PAD7/Pattern/Projects/Pattern/Pattern.pro \
		  ../PAD7/Pattern/Projects/PatternConjoin/PatternConjoin.pro \
		  ../PAD7/Pattern/Projects/PatternDB/PatternDB.pro \
		  ../PAD7/Pattern/Projects/PatternFileConv/PatternFileConv.pro \
		  ../PAD7/Pattern/Projects/PatternFileExp/PatternFileExp.pro \
		  ../PAD7/Pattern/Projects/PatternFileImp/PatternFileImp.pro \
		  ../PAD7/Pattern/Projects/PatternGraphic/PatternGraphic.pro \
		  ../PAD7/Pattern/Projects/PatternIO/PatternIO.pro \
		  ../PAD7/Pattern/Projects/PatternTool/PatternTool.pro 