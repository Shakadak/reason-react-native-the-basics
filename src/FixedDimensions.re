open ReactNative;

[@react.component]
let make = () => {
    <View>
        <View style=Style.(style(~width=50.->dp, ~height=50.->dp, ~backgroundColor="powderblue", ()))/>
        <View style=Style.(style(~width=100.->dp, ~height=100.->dp, ~backgroundColor="skyblue", ()))/>
        <View style=Style.(style(~width=150.->dp, ~height=150.->dp, ~backgroundColor="steelblue", ()))/>
    </View>
};
