/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Text Classifier                                    =
	=            File name:     token.cpp                                          =
	=            Author:        Gabriel Melián Hernández		                   =
	=																			   =
=========================================================================================
=======================================================================================*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/token.hpp"

/*------------------------------------------------*/

/**
 * @brief      Construye una nueva instancia.
 */
Token::Token (void) {
	set_Name("");
	set_Ammount(0);
	set_Type("");
}

/**
 * @brief      Construye una nueva instancia.
 *
 * @param[in]  name  El nombre.
 */
Token::Token (std::string name) {
	set_Name(name);
	set_Ammount(1);
	set_Type("");
}

/**
 * @brief      Destruye el objeto.
 */
Token::~Token (void) {
}

/**
 * @brief      Consigue el nombre.
 *
 * @return     El nombre.
 */
std::string Token::get_Name(void) const {
	return name_;
}

/**
 * @brief      Consigue la cantidad.
 *
 * @return     La cantidad.
 */
unsigned Token::get_Ammount (void) const {
	return ammount_;
}

/**
 * @brief      Consigue el tipo.
 *
 * @return     El tipo.
 */
std::string Token::get_Type (void) const {
	return type_;
}

/**
 * @brief      Establece el nombre.
 *
 * @param[in]  name  El nombre.
 */
void Token::set_Name (std::string name) {
	name_ = name;
}

/**
 * @brief      Establece la cantidad.
 *
 * @param[in]  ammount  La cantidad.
 */
void Token::set_Ammount (unsigned ammount) {
	ammount_ = ammount;
}

/**
 * @brief      Establece el tipo.
 *
 * @param[in]  newType  El tipo.
 */
void Token::set_Type (std::string newType) {
	type_ = newType;
}

/**
 * @brief      Operador <.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator< (const Token& otherToken) const {
	return (get_Name() < otherToken.get_Name());
}

/**
 * @brief      Operador <=.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator<= (const Token& otherToken) const {
	return (get_Name() <= otherToken.get_Name());
}

/**
 * @brief      Operador <.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator< (const std::string& str) const {
	return (get_Name() < str);
}

/**
 * @brief      Operador <=.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator<= (const std::string& str) const {
	return (get_Name() <= str);
}

/**
 * @brief      Operador >.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator> (const Token& otherToken) const {
	return (get_Name() > otherToken.get_Name());
}

/**
 * @brief      Operador >=.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator>= (const Token& otherToken) const {
	return (get_Name() >= otherToken.get_Name());
}

/**
 * @brief      Operador >.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator> (const std::string& str) const {
	return (get_Name() > str);
}

/**
 * @brief      Operador >=.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator>= (const std::string& str) const {
	return (get_Name() >= str);
}

/**
 * @brief      Operador ==.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator== (const Token& otherToken) const {
	return (get_Name() == otherToken.get_Name());
}

/**
 * @brief      Operador ==.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la comparación.
 */
bool Token::operator== (const std::string& str) const {
	return (get_Name() == str);
}

/**
 * @brief      Operador ++.
 *
 * @return     El resultado del incremento.
 */
Token& Token::operator++ (void) {
	this -> set_Ammount(get_Ammount() + 1);
	return *this;
}

/**
 * @brief      Operador =.
 *
 * @param[in]  otherToken  El otro token.
 *
 * @return     El resultado de la asignación.
 */
Token& Token::operator= (const Token& otherToken) {
	this -> set_Name(otherToken.get_Name());
	this -> set_Ammount(otherToken.get_Ammount());
	this -> set_Type(otherToken.get_Type());
	return *this;
}

/**
 * @brief      Incrementa la cantidad en 1.
 */
void Token::incrementate (void) {
	ammount_++;
}

/**
 * @brief      Escribe un token.
 */
void Token::printToken (void) const {
	std::cout << std::endl << "Token Info:" << std::endl << "\t - Name: " << get_Name() << std::endl << "\t - Ammount: " << get_Ammount() << std::endl << "\t - Type: " << get_Type() << std::endl;
}
