/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     main.cpp                                           =
	=            Author:        Gabriel Melián Hernández		                   =
	=																			   =
=========================================================================================
=======================================================================================*/

/*------------------  DECLARACIÓN DE FUNCIONES  -----------------*/

#include "../include/vocabulary.hpp"
#include "../include/corpus.hpp"
#include "../include/learner.hpp"

/*------------------------------------------------*/

void printHelp (void);
void generateVocabulary (int& argc, char* argv[]);
void generateCorpus (int& argc, char* argv[]);
void generateLearner (int& argc, char* argv[]);

/**
 * @brief      Función Main del programa recibe el fichero de datos como
 *             parametro.
 *
 * @param[in]  argc  El número de argummentos.
 * @param      argv  El array de argumentos
 *
 * @return     0 Si el programa finaliza correctamente.
 */
int main (int argc, char* argv[]) {
	if (argc <= 1) {
		printHelp();
	}
	else {
		std::string flag = argv[1];
		if (flag == "-h" || flag == "--help") {
			printHelp();
			return(0);
		}
		else if (flag == "-v" || flag == "--vocabulary") {
			generateVocabulary(argc, argv);
		}
		else if (flag == "-co" || flag == "--corpus") {
			generateCorpus(argc, argv);
		}
		else if (flag == "-l" || flag == "--learner") {
			generateLearner(argc, argv);
		}
	}
	
	std::cout << std::endl << "Program finished correclty." << std::endl;
	return 0;
}	

/**
 * @brief      Muestra por pantalla información de ayuda para ejecutar el programa correctamente.
 */
void printHelp (void) {
	const std::string MAN = "../include/man.txt";
	std::ifstream file(MAN, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error while opening manual file, make sure the file \"man.txt\" is placed on the include folder." << std::endl;
		exit(1);
	} 
	std::string reader;
	while (!file.eof()) {
		std::getline(file, reader);
		std::cout << reader << std::endl;
	}
}

/**
 * @brief      Genera el vocabulario desde el primer fichero de entrada y lo almacena
 *             en el segundo fichero, haciendo uso de las stopWords ddel tercer fichero.
 *
 * @param      argc  El conteo de argumentos.
 * @param      argv  Los argumentos del array.
 */
void generateVocabulary (int& argc, char* argv[]) {
	if (argc != 5) {
		std::cout << std::endl << "Error, the program needs 4 arguments to generate the vocabulary:" << std::endl << "\t bin/textClassifier -v originFile outputFile reservedWordsFile" << std::endl;
		exit(1);
	}
	std::string originFile = argv[2];
	std::string outputFile = argv[3];
	std::string reservedWords = argv[4];
	std::string fileHelper = "../outputs/preProcesserHelper.txt";
	Vocabulary vocabulary(originFile, outputFile);
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.preProcessData(reservedWords);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed pre-processing time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.generateVocabulary(fileHelper, false);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed generating vocabulary time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
	{
		Chrono chrono;
		chrono.startChrono();
		vocabulary.storeVocabulary(outputFile);
		chrono.stopChrono();
		std::cout << std::endl << "Elapsed storing vocabulary time: " << chrono.get_Seconds(5) << " seconds." << std::endl;
	}
}

/**
 * @brief      Genera un corpus para cada tipo de dato recibido como argumento por consola.
 *             El tipo de dato, tiene que ser la primera columna del fichero .csv seguido 
 *			   por una coma en el fichero de datos, pero no en la línea de comandos.
 *
 * @param      argc  La cantidad de argumentos.
 * @param      argv  El array de argumentos.
 */
void generateCorpus (int& argc, char* argv[]) {
	if (argc < 4) {
		std::cout << std::endl << "Error, the program needs at least 3 arguments to generate the corpus:" << std::endl << "\t bin/textClassifier -co originFile reservedWordsFile CORPUS1 CORPUS2 CORPUS3 . . ." << std::endl;
		std::cout << std::endl << "Each \"CORPUS\" represents one data type that wants to be separated into different corpus." << std::endl;
		exit(1);
	}
	std::string originFile = argv[2];
	std::string reservedWords = argv[3];
	PreProcesser preProcesser;
	Vocabulary voc;
	std::vector<std::string> stopWords = voc.loadStopWord(reservedWords);
	for (int i = 4; i < argc; i++) {
		std::string tmp = argv[i];
		Corpus newCorpus(tmp, originFile);
		newCorpus.generateCorpus(stopWords, preProcesser);
	}
}

/**
 * @brief      Calcula la probabilidad de cada token en el corpus proporcionado
 *             como entrada y las guarda en otro fichero.
 *
 * @param      argc  La cantidad de argumentos.
 * @param      argv  El array de argumentos.
 */
void generateLearner (int& argc, char* argv[]) {
	if (argc < 3) {
		std::cout << std::endl << "Error, the program needs at least 2 arguments to learn data from corpus." << std::endl << "\t bin/textClassifier -l vocabularyFile Data1 Data2 ... DataX" << std::endl;
		std::cout << std::endl << "Each \"Data\" represents one data learning type that wants generated." << std::endl;
		exit(1);
	}
	Learner learner(argv, argc);
}
