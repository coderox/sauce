#ifndef SAUCE_SAUCE_SCOPES_H_
#define SAUCE_SAUCE_SCOPES_H_

namespace sauce {

/**
 * The scope of unscoped bindings.
 *
 * It is magical in that values are never saved: successive provisions will always be different.
 */
class NoScope {};

/**
 * The Singleton scope.
 *
 * Its intended use is for extremely long-lived values.
 * TODO mention eager loading once it exists.
 */
class SingletonScope {};

/**
 * The Session scope.
 *
 * Its intended use is for values that exist once in each logical dialog or extended interaction.
 */
class SessionScope {};

/**
 * The Request scope.
 *
 * Its intended use is for values that exist once in each immediate interaction.
 */
class RequestScope {};

}

#endif // SAUCE_SAUCE_SCOPES_H_