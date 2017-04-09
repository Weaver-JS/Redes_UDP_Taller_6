#pragma once
#include "SFML\Network.hpp"
#include <iostream>
#include <OutputMemoryBitStream.h>
#include <InputMemoryBitStream.h>
#include <PlayerInfo.h>
#define PORT 50000
#define BINARYPACKETYPELENGTH 3
#define POSITION_BYNARY_LENGTH 10
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define IP "127.0.0.1"

enum PacketType
{
	PT_EMPTY,
	PT_HELLO,
	PT_WELCOME,
	PT_FULL,
	PT_PING,
	PT_PLAYER_POSITION,
	PT_DISCONNECT,
	PT_SHUTDOWN
};
class UDPmanager
{
private:
	PlayerInfo* player; //En udp al poseer un socket, lo que guardamos son ip:puerto
	std::vector<PlayerInfo*> playerList;
	int size;
	sf::UdpSocket socket;
	bool notConnected;
	bool disconnected;
	sf::Clock client_clock;
	sf::Clock shutdown_Clock;
	

public:
	UDPmanager();
	~UDPmanager();
	void initConnection();
	void ping(uint16_t x, uint16_t y);
	void readMessage(char*  _message,const size_t & _sizeMessage,sf::IpAddress & ip, unsigned short & port);
	bool sendMessage(char* message, sf::IpAddress  ip, unsigned short  port, uint32_t sizeBuffer);
	PlayerInfo & getPlayer();
	PlayerInfo & getPlayer(int i);
	int  getPlayerSize();
	void recv();
	void disconnect();
	bool isDisconnected();
	bool getNotConnected();
};

