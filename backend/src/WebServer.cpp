#include "spmodweb.hpp"

namespace SPModWeb {
  void WebServer::initialize(Poco::Util::Application &self) {
    loadConfiguration();
    Poco::Util::ServerApplication::initialize(self);
  }

  int WebServer::main(const std::vector<std::string> &) {
    Poco::UInt16 port = static_cast<Poco::UInt16>(config().getUInt("port", 8080));
    Poco::Net::HTTPServer srv(new SPModWeb::RequestHandlerFactory, port);

    srv.start();
    Poco::Util::ServerApplication::logger().information("Server started");
    Poco::Util::ServerApplication::waitForTerminationRequest();
    Poco::Util::ServerApplication::logger().information("Stopped Server");
    srv.stop();

    return Poco::Util::Application::EXIT_OK;
  }
}

POCO_SERVER_MAIN(SPModWeb::WebServer);