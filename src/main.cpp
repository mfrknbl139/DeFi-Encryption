#include <iostream>
#include "blockchain/Blockchain.h"
#include "models/Wallet.h"
#include "models/Transaction.h"

void printMenu() {
    std::cout << "=========== MENU ===========" << std::endl;
    std::cout << "1. Gonderen ve Alici Adreslerini Olustur" << std::endl;
    std::cout << "2. Islem Olustur ve Blockchain'e Ekle" << std::endl;
    std::cout << "3. Blockchain'i Goruntule" << std::endl;
    std::cout << "4. Cikis" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Seciminizi yapin: ";
}

int main() {
    Blockchain simpleChain;
    Wallet senderWallet;
    Wallet receiverWallet;

    int choice = 0;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                senderWallet.generateAddress();
                receiverWallet.generateAddress();
                std::cout << "Gonderen Adres: " << senderWallet.getAddress() << std::endl;
                std::cout << "Alici Adres: " << receiverWallet.getAddress() << std::endl;
                break;
            }
            case 2: {
                if (senderWallet.getAddress().empty() || receiverWallet.getAddress().empty()) {
                    std::cout << "Once adreslerinizi olusturun." << std::endl;
                    break;
                }
                double amount;
                std::cout << "Gonderilecek miktar girin: ";
                std::cin >> amount;
                Transaction tx(senderWallet.getAddress(), receiverWallet.getAddress(), amount);
                senderWallet.addTransaction(tx);
                simpleChain.addBlock(Block(simpleChain.getNextBlockNumber(), tx.toString()));
                std::cout << "Islem basariyla eklendi." << std::endl;
                break;
            }
            case 3: {
                std::cout << "Blockchain:" << std::endl;
                simpleChain.printChain();
                break;
            }
            case 4: {
                std::cout << "Cikis yapiliyor..." << std::endl;
                break;
            }
            default: {
                std::cout << "Gecersiz secenek! Lutfen tekrar deneyin." << std::endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
