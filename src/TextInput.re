open ReactNative;

module PizzaTranslator = {
    [@react.component]
    let make = () => {
        let (text, onChange) = React.useState(() => "");
        let pizzas =
            text
            |> Js.String.splitByRe([%re "/\\s+/"])
            |> Array.map(fun
                | Some(s) when String.length(s) > 0 => {js|🍕|js}
                | _ => "")
            |> Js.String2.concatMany("");

        Js.log(text);
        Js.log(pizzas);

        <View style=Style.(style(~padding=dp(10.), ()))>
            <TextInput
                style=Style.(style(~height=dp(40.), ()))
                placeholder="Type here to translate!"
                onChangeText={(x) => onChange(_ => x)}
                value=text
            />
            <Text style=Style.(style(~padding=dp(10.), ~fontSize=42., ()))>
                {React.string(pizzas)}
            </Text>
        </View>
    }
}

[@react.component]
let make = () => {
    <View style=Style.style(
        ~flex=1.,
        ~flexDirection=`column,
        ~justifyContent=`center,
        ~alignItems=`center,
        ~flexWrap=`wrap,
        ())>
        <PizzaTranslator/>
    </View>
};
