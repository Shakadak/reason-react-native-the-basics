open ReactNative;

[@react.component]
let make = () => {
    <View style=Style.style(~height=300.->Style.dp, ())>
        <View style=Style.(style(~flex=1., ~backgroundColor="powderblue", ()))/>
        <View style=Style.(style(~flex=2., ~backgroundColor="skyblue", ()))/>
        <View style=Style.(style(~flex=3., ~backgroundColor="steelblue", ()))/>
    </View>
};
