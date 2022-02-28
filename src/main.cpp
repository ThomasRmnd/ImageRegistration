#include <iostream>
#include <cstdlib>
#include "Recalage.h"

int main(int argc, char* argv[]) {
	
  std::string filenameIm(argv[1]);
  std::string filenameImRef(argv[2]);
  
  ReadFromFile testRead(filenameIm,filenameImRef);
  
  ApplyTransfo testTrans;
  
  Amoeba testOpti(0.001);
  
  VecDoub start(3), result;
  start[0] = std::atof(argv[3]), start[1] = std::atof(argv[4]), start[2] = std::atof(argv[5]);
  
  MatDoub Im, ImRef, ImRes(331,331);
  MatBool ImMask(331,331);
  
  std::string methodeInter(argv[6]);
  std::string methodeSimil(argv[7]);
  
  if (methodeInter == "Bilineaire") {
	  
	  std::cout << "Vous avez sélectionné la méthode d'interpolation biliénaire" << std::endl;
	  
	  Bilineaire testInter;
	  
	  DeformeImage testDeforme(&testInter,&testTrans);
	  
	  if (methodeSimil == "InformationMutuelle") {
		  
		  std::cout << "Vous avez sélectionné la méthode de similarité de l'information mutuelle" << std::endl;
		  
		  InformationMutuelle testSim;
		  
		  FonctionCout testCout(&testSim,&testDeforme,&testRead);
		  
		  Recalage testReca(&testOpti,&testCout);
		  
		  result = testReca(start,1.);
		  
		  std::cout << "tx = " << result[0] << " ty = " << result[1] << " theta = " << result[2] << std::endl;
		  std::cout << testCout(result) << std::endl;
		  
		  testRead(Im,ImRef);
		  
		  testDeforme(Im,ImRes,ImMask,result);
  
		  download(ImRes);
		  
	  }
	  
	  else {
		  
		  std::cout << "Vous avez sélectionné la méthode de similarité des moindres carrés" << std::endl;
		  
		  MoindreCarre testSim;
		  
		  FonctionCout testCout(&testSim,&testDeforme,&testRead);
		  
		  Recalage testReca(&testOpti,&testCout);
		  
		  result = testReca(start,1.);
		  
		  std::cout << "tx = " << result[0] << " ty = " << result[1] << " theta = " << result[2] << std::endl;
		  std::cout << testCout(result) << std::endl;
		  
		  testRead(Im,ImRef);
		  
		  testDeforme(Im,ImRes,ImMask,result);
  
		  download(ImRes);
		  
	  }
  }
  
  else {
	  
	  std::cout << "Vous avez sélectionné la méthode d'interpolation du plus proche voisin" << std::endl;
	  
	  PlusProcheVoisin testInter;
	  
	  DeformeImage testDeforme(&testInter,&testTrans);
	  
	  if (methodeSimil == "InformationMutuelle") {
		  
		  std::cout << "Vous avez sélectionné la méthode de similarité de l'information mutuelle" << std::endl;
		  
		  InformationMutuelle testSim;
		  
		  FonctionCout testCout(&testSim,&testDeforme,&testRead);
		  
		  Recalage testReca(&testOpti,&testCout);
		  
		  result = testReca(start,1.);
		  
		  std::cout << "tx = " << result[0] << " ty = " << result[1] << " theta = " << result[2] << std::endl;
		  std::cout << testCout(result) << std::endl;
		  
		  testRead(Im,ImRef);
		  
		  testDeforme(Im,ImRes,ImMask,result);
  
		  download(ImRes);
		  
	  }
	  
	  else {
		  
		  std::cout << "Vous avez sélectionné la méthode de similarité des moindres carrés" << std::endl;
		  
		  MoindreCarre testSim;
		  
		  FonctionCout testCout(&testSim,&testDeforme,&testRead);
		  
		  Recalage testReca(&testOpti,&testCout);
		  
		  result = testReca(start,1.);
		  
		  std::cout << "tx = " << result[0] << " ty = " << result[1] << " theta = " << result[2] << std::endl;
		  std::cout << testCout(result) << std::endl;
		  
		  testRead(Im,ImRef);
		  
		  testDeforme(Im,ImRes,ImMask,result);
  
		  download(ImRes);
		  
	  }
	  
  }
  return 0;
} 
