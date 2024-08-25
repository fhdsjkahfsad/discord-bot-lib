#include <dpp/dpp.h>
#include <iostream>

const std::string token = "YOUR_TOKEN";
int main() {
    dpp::cluster bot(token);
    bot.on_log(dpp::utility::cout_logger());
    bot.on_slashcommand([](const dpp::slashcommand_t& event){
        if (event.command.get_command_name() == "hi") {
            event.reply("sup");
        }
    });
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("hi", "greets you back", bot.me.id));
        }
    });
    bot.start(dpp::st_wait);
}
