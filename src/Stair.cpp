#include "Stair.h"

Stair::Stair(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}

bool Stair::isBottomCollision(const sf::Sprite& playerIcon) const
{
    sf::FloatRect playerRect = playerIcon.getGlobalBounds(); // المستطيل الخاص باللاعب
    sf::FloatRect stairRect = m_icon.getGlobalBounds(); // المستطيل الخاص بالسلم

    // افحص ما إذا كانت هناك تداخل أو اتصال بين المستطيلين
    if (playerRect.intersects(stairRect) && (playerRect.top + playerRect.height) >= (stairRect.top + 5.f))
    {
        // يوجد تصادم بين اللاعب والسلم
        // هنا يمكنك تطبيق القواعد الخاصة بالتصادم للجزء السفلي من اللاعب والسلم
        // وفقًا لمتطلبات تصميم اللعبة الخاصة بك
        return true;
    }

    return false;
}
sf::FloatRect Stair::getGlobalBounds() const
{
    // التحقق مما إذا كان السلم محددًا
    if (!m_icon.getTexture()) {
        // إرجاع مستطيل فارغ إذا لم يكن السلم محددًا
        return sf::FloatRect();
    }

    // الحصول على المستطيل العام للسلم
    sf::FloatRect stairRect = m_icon.getGlobalBounds();

    return stairRect;
}