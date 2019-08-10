open ReactNative;

let styles = StyleSheet.create({
    "bigBlue": Style.style(~color="blue", ~fontWeight=`bold, ~fontSize=30., ()),
    "red": Style.style(~color="red", ()),
});

[@react.component]
let app = () => {
    <View style=Style.style(~height=300.->Style.dp, ())>
        <View style=Style.(style(~flex=1., ~backgroundColor="powderblue", ()))/>
        <View style=Style.(style(~flex=2., ~backgroundColor="skyblue", ()))/>
        <View style=Style.(style(~flex=3., ~backgroundColor="steelblue", ()))/>
    </View>
};
