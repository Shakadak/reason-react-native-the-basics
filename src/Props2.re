open ReactNative;

module Greeting = {
    [@react.component]
    let make = (~name: string) => {
        let greeting = "Hello " ++ name;
        <View style={Style.style(~alignItems=`center, ())}>
            <Text>{React.string(greeting)}</Text>
        </View>
    }
}

[@react.component]
let make = () => {
    let style =
        Style.style(~alignItems=`center, ~top=Style.dp(50.), ());
    <View style>
        <Greeting name="Rexxar" />
        <Greeting name="Jaina" />
        <Greeting name="Valeera" />
    </View>
};
