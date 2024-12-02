#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


//parsing du fichier

int isSorted(std::vector<int> input) {
  int i=0;
  auto inputcopy=input;
  bool isSorted=true;
  int erasedNb=-1;
  auto cmp=[](int a, int b){return a>b;};
  //test ordre croissant
  while (i<input.size()-2) {
    if (inputcopy[i]>=inputcopy[i+1]) {
      if (inputcopy.size()==input.size()) {
        inputcopy.erase(inputcopy.begin()+i+1);
        erasedNb=i+1;
        i--;
      }
      else {
        isSorted=false;
        break;
      }
    }
    i++;
  }
  if (isSorted) return erasedNb;
  isSorted=true;
  inputcopy=input;
  i=0;
  while (i<inputcopy.size()-2) {
    if (inputcopy[i]<=inputcopy[i+1]) {
      if (inputcopy.size()==input.size()) {
        inputcopy.erase(inputcopy.begin()+i+1);
        erasedNb=i+1;
        i--;
      }
      else {
        isSorted=false;
        break;
      }
    }
    i++;
  }
  if (isSorted) return erasedNb;
  else return(-2);

}

int main(){
  std::ifstream file("../input.txt");
  if (!file.is_open()) {
    throw std::runtime_error("Impossible d'ouvrir le fichier");
  }
  std::vector<int> report;
  std::string line;
  int number;
  int validReport=0;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    //on met le report dans le tableau
    report.clear();
    while(iss>>number) {report.push_back(number);}

    //définition de la taille de base
    int initSize=report.size();
    //pour la partie 2, on ajoute une tolérance d'un nombre supprimable
    int resultSort=isSorted(report);
    if( resultSort!=-2) {
      //si la liste est triée/triable
      //on retire l'élément problématique avant la suite
      if (resultSort!=-1) report.erase(report.begin()+resultSort-1);
      //une fois ceci fait on reprend notre vérification
      bool isSafe=true;
      for(int i=0;i<report.size()-1;i++){
        if(abs(report[i]-report[i+1])<1 || abs(report[i]-report[i+1])>3) {
          if (report.size()<initSize) isSafe=false;
          else report.erase(report.begin()+i);
        }
      }
      if(isSafe) {validReport++;
      std::cout<<line<<std::endl;
    }
    }

}
  file.close();

std::cout<<validReport<<std::endl;
  return 0;
}