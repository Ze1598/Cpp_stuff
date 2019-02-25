// This file goes over namespaces, the `using` keyword and storage classes
#include <iostream>
#include <string> // string types
using namespace std;

/*
Namespaces are useful to group entities (variables, functions, etc.) within
a narrower scope.
The syntax for defining a new namespace is:
namespace namespaceName {
	named_entities
}
`namespaceName` can be any name you desire and you can create as many
`named_entities` as needed.
To access an entity from a namespace use namespaceName::named_entity.
Due note a namespace can be renamed after its creation using
namespace newName = currentName;
*/
// Create a namespace called `firstNS` which contains two `int` variables:
// `a` and `b`
namespace firstNS {
	int a, b;
}
// Create a namespace with one function: `testFunc`
namespace secondNS {
	int testFunc () {return 5;}
}
// `thirdNS` has a `testFunc` function just like the `secondNS` namespace,\
// but there's no name colision since they are defined in different\
// namespaces
namespace thirdNS {
	string testFunc() {return "Hello World";}
}
// We can add more entities to a namespace previously created
namespace firstNS{
	// Now `firstNS` contains `a`, `b` and `c`
	int c;
}

/*
using
The keyword `using` introduces a name into the current scope, thus removing the
need to qualify a name.
using namespaceName::named_entity removes the need to qualify a single entity.
using namespace namespaceName removes the need to qualify all named entities from
`namespaceName`.
Both of these are only valid in the scope that they appear or for the whole file
when declared in the file's global scope.
*/

/*
storage classes
static storage: variables from the global scope or from a named namespace are stored
for the entire duration of the program and their values is initialized as `0`.
automatic storage: the storage of variables from local scopes (those declared within
a conditional/ function/loop/etc. block) is only available during the block in which
they are declared. These variables are left uninitialized, that is, they are left
with an undetermined value.
*/

int main() {
	// Initialize a variable from the `firstNS` namespace
	firstNS::a = 2;
	// Create an `a` variable, which doesn't affect `firstNS`'s `a` because this\
	// one is created in the scope of `main()`
	int a = 3;
	cout << "firstNS::a => " << firstNS::a << "\nmain() scope `a` => " << a << "\n";
	cout << "secondNS::testFunc() => " << secondNS::testFunc() << "\n";
	cout << "thirdNS::testFunc() => " << thirdNS::testFunc() << "\n";
	// Thanks to this, `firstNS`'s `c` doesn't need to be called in a qualified way\
	// anymore (though `a` and `b` still require qualified uses)
	using firstNS::c;
	c = 10;
	cout << "firstNS::c => " << c << "\n";

	// storage classes examples
	// Example of an uninitialized static storage variable
	cout << "firstNS::b (uninitialized variable) => " << firstNS::b << "\n";
	// Use this do-while loop just to create a local scope (the loop runs once only)
	do {
		int loop_var;
		// Example of an uninitialized automatic storage variable
		cout << "uninitialized variable from a loop => " << loop_var << "\n";
	} while (1 > 2);
	cout << "END\n";
}