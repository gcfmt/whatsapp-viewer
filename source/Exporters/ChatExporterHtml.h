#pragma once

#include <string>
#include <set>
#include <vector>

#include "ChatExporter.h"

class WhatsappChat;
class WhatsappMessage;

class ChatExporterHtml : public ChatExporter
{
private:
	std::string templateHtml;

	std::string buildMessages(WhatsappChat &chat, std::set<int> &usedEmoticons);
	std::string buildChats(std::vector<WhatsappChat *> chats);
	void replacePlaceholder(std::string &html, const std::string &placeholder, const std::string &text);
	std::string convertMessageToHtml(WhatsappMessage &message, std::set<int> &usedEmoticons);
	std::string buildEmoticonStyles(const std::set<int> &usedEmoticons);

public:
	ChatExporterHtml(const std::string &templateHtml);
	~ChatExporterHtml();

	void exportChat(WhatsappChat &chat, const std::string &filename);
	void exportChatAll(std::vector<WhatsappChat *> chat, const std::string & filename);
};
