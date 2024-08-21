#include <Geode/utils/web.hpp>

using namespace geode::prelude;





















web::WebTask webSend(web::WebRequest *self, std::string_view method, std::string_view givenUrl)
    {













		return self->send(method, givenUrl);
    };

$execute
{
    auto hook = Mod::get()->hook(
        reinterpret_cast<void*>(
			geode::addresser::getNonVirtual(&web::WebRequest::send)
        ),
        &webSend,
        "web::WebRequest::send",
        tulip::hook::TulipConvention::Thiscall
    );
}
